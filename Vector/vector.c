#include "vector.h"

static unsigned Size = 0;
static element_t vec[CAPACITY];
int pointer = 0;

unsigned size(void) 
{
    return Size;
}

unsigned capacity(void)
{
    return CAPACITY;
}

void append(element_t elem)
{
    vec[Size] = elem;
    Size += 1;
}

short int getelem(void)
{
    return vec[pointer++];
}

void reread(void)
{
    pointer = 0;
}


int findelem(element_t elem, int last)
{
    if(last == NOT_FOUND)
        return NOT_FOUND;
    int i;
    for(i = last+1; i < CAPACITY; i++)
    {
	if(vec[i]==elem)
            return i;
    }
    return NOT_FOUND;
}

void clear(void)
{
    int i;
    for(i=0; i < CAPACITY; i++)
        vec[i] = 0;
}

int find(element_t elem)
{
    static int lastIndex = -1;
    static int lastValue;
    int index;
    if(lastValue == elem)
        /* use the lastIndex */
        index = lastIndex;
    else
        /* use the dafault */
        index = -1;
    lastIndex = findelem(elem, index);
    return lastIndex;
}
