#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define RANDS 1000000
#define RESIZE 4
#define POINTS 5


struct Square
{
    double x;
    double y;
    double length;
};


double getDist(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x1-y1, 2) + pow(x2-y2, 2));
}

double * getMitte(int length, double arr[length][2])
{
    register int i, j;
    double bestX;
    double bestY;
    double bestDist = FLT_MAX; 
    struct Square square;
    square.x = 0.0;
    square.y = 0.0;
    square.length = 1.0;
    
    for(i = 0; i < RANDS; i++)
    {
        double x1 = rand()/((double)INT_MAX+1);
        double x2 = rand()/((double)INT_MAX+1);
        x1 = square.x + x1*square.length;
        x2 = square.y + x2*square.length;
        double distSum = 0;
        for(j = 0; j < length; j++)
            distSum = getDist(x1, x2, arr[j][0], arr[j][1]);
        if(distSum < bestDist)
        {
            bestX = x1;
            bestY = x2;
            bestDist = distSum;
        }

        if(i % (RANDS/RESIZE)==0 && i != 0)
        {
            /*Resize the Square */
            square.length = square.length/2.0;
            square.x = bestX-square.length/2;
            square.y = bestY-square.length/2;
            printf("Neues Quadrat: x=%f, y=%f, length=%f\n", square.x, square.y, square.length);
        }

        if((i % (RANDS/10)) == 0 )
            printf("%d%%  der Punkte sind bereits abgearbeitet.\n", 10*i/(RANDS/10));
    }
    double * values = (double *) malloc(sizeof(double) * 2);
    values[0] = bestX;
    values[1] = bestY;
    return values;
}

void print(int length, double arr[length][2])
{
    int i;
    printf("Eingegebene Punkte:\n");
    for(i=0; i < POINTS; i++)
    {
        printf("Punkt %d:   ", i + 1);
        printf("%f, ",arr[i][0]);
        printf("%f\n",arr[i][1]);
    }
}

int main(void)
{
    int i;
    double arr[POINTS][2];

    #ifndef DEBUG
    for(i=0; i<POINTS; i++)
    {
        printf("Punkt %d:\n", i + 1);
        scanf("%d, %d", &arr[i][0], &arr[i][1]);
    }
    #else
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[2][0] = 0;
    arr[2][1] = 1;
    arr[3][0] = 1;
    arr[3][1] = 0;
    arr[4][0] = 0.5;
    arr[4][1] = 0.5;
    #endif

    print(POINTS, arr);
    double * result = getMitte(POINTS, arr);
    printf("Eine Naeherung fuer den gesuchten Punkt ist: (%f, %f)\n", result[0], result[1]);
    return 0;
}
