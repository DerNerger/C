#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char ** arr  <=>
char *arr[]  <!=>
char (*arr)[]
*/


char ** replace(char (*old)[], char (*sub)[], char (*new)[])
{

    int i, j;
    for(i = 0; i < strlen(*old); i++)
    {
        int match = i;
        for(j = 0; j < strlen(*sub); j++)
        {
            if((*old)[i+j] != (*sub)[j])
            {
                match = -1;
                break;
            }
        }
        if(match != -1);
            for(j = 0; j < strlen(*sub); j++)
                (*old)[i+j] = (*new)[j];
    }


    return NULL;
}

int main(void)
{
    
    char arr[100];
    char arr2[100];
    char arr3[100];

    scanf("%s", arr);
    scanf("%s", arr2);
    scanf("%s", arr3);

    printf("%s\n", arr);
    printf("%s\n", arr2);
    printf("%s\n", arr3);

    replace(&arr, &arr2, &arr3);
  
    printf("%s", *arr);
}
