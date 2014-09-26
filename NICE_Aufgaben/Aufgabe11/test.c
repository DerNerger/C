#include <stdio.h>
#include "Vector1.1.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main(void)
{
    int i;
    time_t *theTime;
    time(theTime);
    srand(*theTime);
    for(i=0;i < MAXSIZE; i++)
    {
        int nextRand = rand()/((double)INT_MAX+1)*10;
        append(nextRand);
    }
    printf("The Vector: \n");
    printVector();

    for(i = 0; i < 10; i++)
    {
        printf("Vorkommen der Zahl :%d\n", i);
        int result=findelem(i, START_SEARCH);
        while(result != NOT_FOUND)
        {
            printf("%d, ", result);
            result = findelem(i, result);
        } 
        printf("\n");
    }
}
