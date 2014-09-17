#ifdef __GNUC__
    #ifndef __clang__
        #define B(x) 0b ## x
    #else
        #define B(x) myFun(x)
    #endif
#else
    #define B(x) myFun(x)
#endif

int myFun(int x)
{
    int i = 0;
    int result=0;
    while( x > 0 )
    {
        result +=  (x%10)<<i;
        x/=10;
        i++;
    }
    return result;
    return 0;
}
