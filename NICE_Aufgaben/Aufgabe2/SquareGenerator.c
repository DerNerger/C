#include "Quadrat.h"
#include <stdio.h>
#include <stdlib.h>

int ** genMagic(int n)
{
    int k = 0;
    if ( n % 2 == 0 )
    {
        printf("%s\n", "Ein Magisches Quadrat kann nur bei einer ungerade Dimension generiert werden.");
    }
   
    /* Zweidimensionales Array dynamisch initialisieren */ 
    int ** arr;
    arr = (int **) malloc(n * sizeof(int *));
    register int i, j;
    for(i = 0; i < n; i++)
        arr[i] = (int *) malloc( sizeof(int) * n);

    /* erstelle das Magische Quadrat */
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            int a_ij = 0;
            int b_ij = 0;

            if( (i+j) % n == 0 )
                a_ij = (i+j) % n;
            else
                a_ij = n + (i+j) % n;

            if( ((i-j+n)%n)%2 == 0 )
                b_ij = n*(((i-j+n)%n)-1);
            else
                b_ij = n*(n - 1 + (i-j+n)%n);

            arr[i][j] = 0.5 * (a_ij + b_ij);
        }
    }
    
    return arr;
}

int main(void)
{
    int ** arr = genMagic(SIZE);

    register int i,j;
    for(i=0; i < SIZE; i++)
    {
        for(j=0; j < SIZE; j++)
            printf("%d  ", arr[i][j]);
        printf("\n");
    }

    int isSquare = check(arr);

    if(isSquare)
        printf("%s", "Das angegebene Quadrat ist ein Magisches Quadrat\n");
    else
        printf("%s", "Das angegebene Quadrat ist kein Magisches Quadrat\n");
}
