#include <stdio.h>
#include "Vector1.5.h"


const char chars[5][5] = {{'M', 'O', 'N', 'S', 'E'}
                       ,{'R', 'A', 'T', 'B', 'C'}
                       ,{'D', 'F', 'G', 'H', 'I'}
                       ,{'K', 'L', 'P', 'Q', 'U'}
                       ,{'V', 'W', 'X', 'Y', 'Z'}};

int *getPosition(char c)
{
    int i,j;
    static int posi[2];
    for(i = 0; i<5; i++)
        for(j = 0; j<5; j++)
            if(chars[i][j] == c)
            {
                posi[0] = i;
                posi[1] = j;
                return posi;
            }
    return NULL;
}

char * decrypt(char a, char b)
{
    int * posi = getPosition(a);
    int a1 = posi[0];
    int a2 = posi[1];
    posi = getPosition(b);
    int b1 = posi[0];
    int b2 = posi[1];
    static char back[2];

    if(a1 == b1)
    {
        a2 = (a2+4)%5;
        b2 = (b2+4)%5;
    }
    else if(a2 == b2)
    {
        a1 = (a1+4)%5;
        b1 = (b1+4)%5;
    } 
    else
    {
        int temp = b2;
        b2 = a2;
        a2 = temp;
    }
    back[0] = chars[a1][a2];
    back[1] = chars[b1][b2];
    return back;
}

char check(char c)
{
    c = toupper(c);
    if(c == 'J')
        c = 'I';
    return c;
}

int main(void)
{
    char c;
    int i;
    int currentPosi = 0;
    char buffer = '0';
    int aIsUpper, bIsUpper;

    while( (c=getchar()) != EOF )
    {
        if(isalpha(c))
        {
            if(buffer!='0')
            {
                bIsUpper = isupper(c);
                char * p = decrypt(buffer, check(c));
                reread();
                for(i=0; i<currentPosi; i++)
                    putchar(getelem());
                if(aIsUpper)
                    putchar(p[0]);
                else
                    putchar(tolower(p[0]));
                while( (c=getelem()) != NOT_FOUND)
                    putchar(c);
                if(bIsUpper)
                    putchar(p[1]);
                else
                    putchar(tolower(p[1]));
                clear();
                currentPosi=0;
                buffer = '0';
            }
            else
            {
                buffer = check(c);
                aIsUpper = isupper(c);
            }
        }
        else
        {
            append(c);
            if(buffer == '0')
                currentPosi++;
        }
    }
    reread();
    for(i=0; i<currentPosi; i++)
        putchar(getelem());
    if(buffer != '0')
        if(aIsUpper)
            putchar(buffer);
        else
            putchar(tolower(buffer));
    while( (c=getelem()) != NOT_FOUND)
        putchar(c);
    printf("\n\n");
}
