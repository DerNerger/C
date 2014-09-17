#include "euro.h"
#include <stdio.h>

int main(void)
{
    eur_t x = 3232;
    char *result = eurtostr(x);
    int i;
    for(i = 0; i < 5; i++)
       printf("%c", result[i]);
    printf("\n");
    return 0; 
}
