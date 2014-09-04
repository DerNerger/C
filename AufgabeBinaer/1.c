#include <stdio.h>

int mult(int x, int y)
{
    int ergebnis = 0, i = 0;
    while(i < sizeof(int)*8 )
    {
        if(x & 1<<i)
        {
            ergebnis += y << i;
	}
        i++;
    }
    return ergebnis;
}

int main(void)
{
    int x = mult(-10,2);
    printf("%d\n", x);
}
