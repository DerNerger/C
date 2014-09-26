#include <stdio.h>
#include "euro.h"

int main(void)
{
    euro_t a = 2;
    euro_t b = 10;
    euro_t c = 100;
    euro_t d = 1250099;
    euro_t e = 1234567890;
    

    char * str1 = eurtostr(a);
    printf("%d = %s\n", a, str1);
    char * str2 = eurtostr(b);
    printf("%d = %s\n", b, str2);
    char * str3 = eurtostr(c);
    printf("%d = %s\n", c, str3);
    char * str4 = eurtostr(d);
    printf("%d = %s\n", d, str4);
    char * str5 = eurtostr(e);
    printf("%d = %s\n", e, str5);
}
