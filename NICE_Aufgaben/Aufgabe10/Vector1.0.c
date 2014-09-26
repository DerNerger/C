#include "Vector1.0.h"


unsigned size(void)
{
    return currentSize; 
}

unsigned cap(void)
{
    return MAXSIZE;
}

void append(short int elem)
{
    if(currentSize < MAXSIZE)
        arr[currentSize++] = elem;
}

short int getelem(void)
{
    return arr[next++];
}

void reread(void)
{
    next = 0;
}

int findelem(short int elem, unsigned int lastIndex)
{
    int i;
    for(i = lastIndex+1; i < MAXSIZE; i++)
        if(arr[i] == elem)
            return i;
    return NOT_FOUND;
}

void clear(void)
{
    currentSize=0;
}

void printVector(void)
{
    int i;
    printf("Index:");
    for(i=0; i<currentSize; i++)
        printf("%3d|", i);
    printf("\n");
    printf("------");
    for(i=0; i<currentSize; i++)
        printf("----", i);
    printf("\n");
    printf("Value:");
    for(i=0; i<currentSize; i++)
        printf("%3d|", arr[i]);
    printf("\n");
}
