#include "binary.h"
#include <stdio.h>

int main(void)
{
    unsigned char arr[10];
    arr[0] = B(11111111);
    arr[1] = B(0);
    arr[2] = B(101);
    arr[3] = B(10101010);
    int i;
    for(i=0; i < 4; i++)
        printf("%d\n", arr[i]);
}
