#include <stdio.h>
#include <stdlib.h>
#define strSize 10

int main(void)
{
    /*char arr[strSize];*/
    char * arr = (char *) malloc(strSize);
    scanf("%s", arr);
    printf("Eingabe = %s\n", arr);
}
