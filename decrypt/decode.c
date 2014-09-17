#include <stdio.h>
#include <stdlib.h>

const char arr[5][5] = {{'M', 'O', 'N', 'S', 'E'}
                       ,{'R', 'A', 'T', 'B', 'C'}
                       ,{'D', 'F', 'G', 'H', 'I'}
                       ,{'K', 'L', 'P', 'Q', 'U'}
                       ,{'V', 'W', 'X', 'Y', 'Z'}};

int c1;
int c2;
char chars[100000];
int next = 0;
int c1IsUpper;
int c2IsUpper;

char getCharOnPosition(int a, int b)
{
    return arr[a][b];
}

char* getDecrypt(int a1, int a2, int b1, int b2)
{
    static char result[2];
    /*printf("%d, %d, %d, %d", a1, a2, b1, b2);*/
    if ( a1 == b1) /* selbe Zeile */
    {
        result[0] = getCharOnPosition(a1, (a2+4)%5);
        result[1] = getCharOnPosition(b1, (b2+4)%5);
    }
    else if ( a2 == b2 ) /* selbe Spalte */
    {
        result[0] = getCharOnPosition((a1+4)%5, a2);
        result[1] = getCharOnPosition((b1+4)%5, b2);
    } 
    else /*rest */
    {
        result[0] = getCharOnPosition(a1, b2);
        result[1] = getCharOnPosition(b1, a2);
    }
    return result;
}

int* findChar(char elem)
{
    elem = toupper(elem);
    if(elem == 'J')
        elem = 'I';
    static int back[2];
    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(arr[i][j] == elem)
            {
                back[0] = i;
                back[1] = j;
                return back;
            }
        }
    }
    return NULL;
}

void readChars(void)
{
    int c = getchar();
    while( !isalpha(c) )
    {
        if(c == EOF)
        {
            chars[next]='\0';
            printf("%s", chars);
            exit(0);
        }
        chars[next++] = c;
        c = getchar();
    }
    c1=next;
    chars[next++] = c;
    c=getchar();
    while( !isalpha(c) )
    {
        if(c == EOF)
        {
            chars[next]='\0';
            printf("%s", chars);
            exit(0);
        }
        chars[next++] = c;
        c = getchar();
    }
    c2=next;
    chars[next++] = c;
}

int main(void)
{
    int a1, a2, b1, b2, *koords;
    while(1)
    {
        readChars();
        koords=findChar(chars[c1]);
        c1IsUpper = isupper(chars[c1]);
        a1=koords[0]; 
        a2=koords[1]; 
        koords=findChar(chars[c2]);
        c2IsUpper = isupper(chars[c2]);
        b1=koords[0]; 
        b2=koords[1]; 
        char *result = getDecrypt(a1, a2, b1, b2);
        chars[c1]=result[0];
        chars[c2]=result[1];
        if(!c1IsUpper)
            chars[c1]=tolower(chars[c1]);
        if(!c2IsUpper)
            chars[c2]=tolower(chars[c2]);
    }
}
