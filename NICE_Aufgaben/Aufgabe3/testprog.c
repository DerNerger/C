#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char * str1 = (char * ) malloc(100); 
    /*str1 = "bla bla bla dies ist str1";*/
    printf("%s\n", str1);
    printf("%s\n", "Dies ist Testausgabe 1");
    scanf("%s", str1);
    printf("%s\n", "Dies ist Testausgabe 2");
    printf("%s\n", str1);
}
