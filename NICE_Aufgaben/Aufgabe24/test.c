#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char * arr = (char *) malloc(100);
    scanf("%[^\n]s", arr); /* Schreibt blanks mit in arr */
    /*scanf("%s", arr);  Schreibt blanks nicht mit in arr */
    printf("%s\n", arr);
}
