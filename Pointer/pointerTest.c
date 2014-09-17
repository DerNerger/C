#include <stdio.h>

int main()
{
    int a=1, b=2, c=3, d=4;
    int * arr = {&a, &b, &c, &d};
    int i;
    for(i = 0; i < 4; i++)
        printf("%d\n", *arr[i]);
}
