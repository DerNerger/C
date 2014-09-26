#include "binary.h"
#include <stdio.h>

int main(void)
{
    unsigned char arr[4];
    arr[0] = B(11111111);
    arr[1] = B(0);
    arr[2] = B(101);
    arr[3] = B(10101010);
    

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);
}
