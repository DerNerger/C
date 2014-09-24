#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char ** str_split(char str[16], char splitChar, int * size)
{
    int i, j, k;
    *size = 1;

    for(i = 0; i < 16; i++) /* Anzahl substrings ermitteln */
        if(str[i] == splitChar)
            (*size)++;

    char ** temp = (char **) malloc(sizeof(char *) * (*size)); 
    i = 0;
    for(j=0; j < (*size); j++)
    {
        int x = i; /* x = Anfang neuer substring */
        while(str[i] && str[i] != splitChar) i++ ;
        
        temp[j] = (char *) malloc(sizeof(char ) * (i-x));

      
        for(k = 0; k < i-x; k++)
           temp[j][k] = str[x+k];

        i++;
    }    
    return temp;
}

/*
int pow(int basis, int exp)
{
    int i;
    int back = 1;
    for(i = 0; i < exp; i++)
        back *= basis;
    return back;
}
*/

int parseInt(char * str)
{
    char * temp = str;
    while(*temp)
        temp++;
    temp--;
    int back = 0;
    int i = 0;
    while(temp >= str)
    {
        back += (*temp - '0')*pow(10, i++);
        temp--;
    }

    return back;
}

int ip_str2int(char adress[16])
{
    int size;
    char** splitted = str_split(adress, '.', &size);
    int back = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        back += parseInt(splitted[i])<<8*i;
    }
    return back;
}

int main(void)
{
    char adress[16];
    scanf("%s", &adress);
    int intAdress = ip_str2int(adress);
    printf("%0x\n", intAdress);

}
