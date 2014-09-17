#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main(void)
{
    int i;
    time_t theTime;
    time(&theTime);
    srand(theTime);
    for(i=0; i < CAPACITY; i++)
    {
        append((int)10*(rand()/((double)RAND_MAX+1)));
    }

    printf("%s\n", "--------------------------------");
    reread();
    for(i=0; i < CAPACITY; i++)
        printf("%d: %d\n",i , getelem());


    printf("%s\n", "--------------------------------");
    for(i=0; i < CAPACITY; i++)
        printf("%d: %d\n",i , find(i));
}
