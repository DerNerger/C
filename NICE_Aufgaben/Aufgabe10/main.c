#include "Vector1.0.h"
#include <stdio.h>


int main(void)
{
    printf("maxSize = %d\n", cap());
    printf("currentSize = %d\n", size());
 
    int i;
    for(i=0; i<MAXSIZE+1; i++)
    {
        append(i);
        printf("currentSize = %d\n", size());
    }
    
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    for(i=0; i<MAXSIZE; i++)
    {
        printf("arr[%d] = %d\n",i, getelem());
    }
    reread();
    for(i=0; i<MAXSIZE; i++)
    {
        printf("arr[%d] = %d\n",i, getelem());
    }

    
    printf("index von 3 = %d\n", findelem(3, START_SEARCH));
    printf("index von 2 = %d\n", findelem(3, 3));

    printVector();

    return 0;
}
