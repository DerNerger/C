#include "Vector.h"

short int *arr = NULL;
int currentMaxSize = STARTSIZE;
int currentSize = 0;
int next = 0;

unsigned size(void)
{
    return currentSize;
}

unsigned capacity(void)
{
    return currentMaxSize;
}

void append(short int elem)
{
    if(arr == NULL )
        arr = (short int *) malloc( sizeof( short int) * STARTSIZE);

    if ( currentSize == currentMaxSize )
    {
        arr = (short int *) realloc(arr, sizeof( short int) * 2 * currentMaxSize);
        currentMaxSize = currentMaxSize * 2;
    }
    arr[currentSize++] = elem;
}

void print(void)
{
    int i;
    for (i = 0; i < currentSize; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

short int getelem(void)
{
    return arr[next++];
}

void reread()
{
    next = 0;
}

void clear(void)
{
    int i;
    for(i = 0; i < currentSize; i++)
        arr[i] = 0;
    currentSize = 0;
}

int findelem(short int elem, int last)
{
    int i;
    for( i = last; i < currentMaxSize; i++)
    {
        if ( elem == arr[i] )
            return i;
    }
    return NOT_FOUND;
}

void reserve(int newSize)
{
    if (newSize == 0)
    {
        free(arr);
        arr = NULL;
    }
    else
    {
        arr = (short int *) realloc(arr, sizeof(short int) * newSize );
    }
    if(currentSize > newSize)
        currentSize = newSize;
    currentMaxSize = newSize;
}
