#include <stdio.h>
#include <stdlib.h>

void replace(char ** str, char old, char new)
{
    char * temp = *str;
    while(*temp != '\0')
    {
        if(*temp == old)
            *temp = new;
        temp++;
    }
}


int main(void)
{
    char * arr = (char*) malloc(100);
    scanf("%[^\n]s", arr); /* Einlesen der Zeichenkette +Blanks */
    replace(&arr, 'a', 'x');
    printf("%s\n", arr);

}
