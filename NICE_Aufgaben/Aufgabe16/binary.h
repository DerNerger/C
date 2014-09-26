#include <stdio.h>
#ifdef __GNUC__
    #ifndef __clang__
        #define B(x) 0b ## x
    #else
        #define B(x) strToInt(#x)
    #endif
#else
    #define B(x) strToInt(#x) 
#endif

int strToInt(const char * str)
{
    int length=0;
    const char * temp = str;
    while(*temp)
    {
        length++;
        temp++;
    }
    int back=0;
    int i;
    for(i = 0; i<length; i++)
    {
        back += (str[length-1-i] -'0')<<i;
    }
    return back;
}

/* old version
int strToInt(int x)
{
    int exp = 0;
    int back = 0;
    while(x>0)
    {
        back += ((x%10)<<exp);
        x/=10;
        exp++;
    }
    return back;
}
*/
