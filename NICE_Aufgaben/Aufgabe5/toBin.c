#include <stdio.h>

int main(void)
{
    int z;
    scanf("%d", &z);
    int i;
    for(i = 0; i < sizeof(int)*8; i++)
    {
        if(i % 4 == 0 && i != 0)
            printf("%c", ' ');
        printf("%d", (z & 1<< (sizeof(int)*8-1-i)) != 0 );
    }
    printf("\n");
}
