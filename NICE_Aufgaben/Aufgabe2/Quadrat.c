#include <stdio.h>
#include "Quadrat.h"

int check(int ** arr)
{
    int sum = 0;
    int currentSum = 0;
    int i, j;
    for(i = 0;i< SIZE; i++)
        sum += arr[0][i];

    /*Zeilen */
    for(i=1; i <  SIZE; i++)
    {
        currentSum = 0;
        for(j=0; j < SIZE; j++)
            currentSum += arr[i][j];

        if(currentSum != sum)
            return 0;
    }

    /*Spalten*/
    for(i=0; i <  SIZE; i++)
    {
        currentSum = 0;
        for(j=0; j < SIZE; j++)
            currentSum += arr[j][i];

        if(currentSum != sum)
            return 0;
    }

    /*Hauptdiagonale*/
    currentSum = 0;
    for(i=0; i <  SIZE; i++)
        currentSum+=arr[i][i];

    if(currentSum != sum)
        return 0;

    /*Nebendiagonale*/
    currentSum = 0;
    for(i= 0; i <  SIZE; i++)
        currentSum += arr[SIZE-i-1][i];

    if(currentSum != sum)
        return 0;

    return 1;
}
