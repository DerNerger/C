#include "euro.h"

int stellen(int i)
{
    if(i < 0)
        i *= -1;
    int stellen = 0;
    while(i > 0)
    {
        stellen++;
        i/=10;
    }
    return stellen;
}

char * eurtostr(euro_t a)
{
    char * str;
    if(a < 100){
        str = (char *) malloc(sizeof(char) * 5);
        str[0]='0';
        str[1]=',';
        str[2]=(char) (a/10)+'0';
        str[3]=(char) (a%10)+'0';
        str[4]='\0';
    }
    else{
        int s = stellen(a)-2;
        int punkte = s/3;
        if(s%3==0)
            punkte--;
        /* s = stellen ohne cent, 4 weil 2 centstellen + komma + \0*/
        int sum_stellen = s+punkte+4;
        str = (char *) malloc( sum_stellen * sizeof(char));
        str[sum_stellen-1] = '\0';
        int i = 1;
        int nextDot=100;
        while(a > 0)
        {
            if(i==3)
            {
                str[sum_stellen-i-1] = ',';
                nextDot=3;
            }
            else if(nextDot==0){
                str[sum_stellen-i-1] = '.';
                nextDot=3;
            }
            else
            {
                str[sum_stellen-i-1] = a%10 + '0';
                nextDot--;
                a/=10;
            }
            i++;
        }
    }
    return str;
}
