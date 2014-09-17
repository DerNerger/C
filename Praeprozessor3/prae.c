#define ELEM_LEN 21

#define GANS "
#include <stdio.h>

#define FUN2(Y, X) FUN(Y,X) 
#define FUN(Y, X) Y##% ## X ## s ## Y
#define ELEM_FORM FUN2(GANS, ELEM_LEN)

int main(void)
{
    char arr[ELEM_LEN];
    printf(ELEM_FORM, arr);
}
