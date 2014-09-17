#include <stdio.h>
#include <float.h>
#define POINTS 5
#define GEN 100
#include <stdlib.h>
#include <math.h>

void mc(double points[POINTS][2])
{
    int i, j;
    double bestX = 0.5;
    double bestY = 0.5;
    double dist = FLT_MAX;
    double quLength = 1.0;

    for(i = 0; i < GEN; i++)
    {
        double x = bestX- quLength/2 + (rand() / ((double)RAND_MAX )) * quLength;
        double y = bestY -quLength/2 + (rand() / ((double)RAND_MAX )) * quLength;
        double currentDist = 0;

        for(j = 0; j < POINTS; j++)
            currentDist += sqrt( pow(x - points[j][0], 2) + pow(y - points[j][1], 2));
        if(currentDist < dist)
        {
            dist = currentDist;
            bestX = x;
            bestY = y;
            quLength /= 2;
        } 
        
    }
    printf("Ergebnis =\n");
    printf("( %f, %f )\n", bestX, bestY);
}

int main()
{
    double points [POINTS][2];
    int i;
    for(i = 0; i < POINTS; i++)
    {
        printf("Point %d:\n", i + 1);
        scanf("%lf, %lf", &points[i][0], &points[i][1]);
    }

    printf("Points=\n");
    for(i = 0; i < POINTS; i++)
        printf("( %f, %f )\n", points[i][0], points[i][1]);

    mc(points);
}
