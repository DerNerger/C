#include <stdio.h>

void toBin(int a)
{
    int i;
    int arr[sizeof(int) * 8];
    for(i = 0 ; i < sizeof(int) * 8; i++)
    {
        arr[sizeof(int)*8 - 1 - i] = a & 1;
        a>>=1;
    }
   
    for(i = 0; i < sizeof(int) * 8; i++)
    {
        if(i % 4 == 0)
           printf("  ");
        printf("%d", arr[i]);
    } 
    printf("\n");
}

int main(void)
{
    int a;
    scanf("%d", &a);
    toBin(a);
}
