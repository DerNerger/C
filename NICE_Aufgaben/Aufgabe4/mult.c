#include <stdio.h>

int mult(int x, int y)
{
    int result = 0;
    int i = 0;
    while(i < sizeof(int) * 8)
    {
        if(x & 1<<i)
        {
            int newY =  y<<i;
            result += newY;
        }
        i++;
    }
    return result;
}

int main(void)
{
    int a, b;
    printf("%s", "Zahl1: ");
    scanf("%d", &a);
    printf("%s", "Zahl2: ");
    scanf("%d", &b);
    printf("%s", "Ergebis: ");
    printf("%d * %d = %d\n", a, b, mult(a, b));
}
