#include <stdio.h>

int main(void)
{
    short int s = 10;
    int i, j=25, n = 1, a = 5, b = 2, c = 4;
    long int k = 3L;
    float x;
    double d = 3.2, y = 2.3, z = 0.0;

    /*x = d * (i = ((int) 2.9 + 1.1 ) / d );*/
    /*int test = 1 + 3 * (n += s << 1) / 5;*/
    /*int test = ++ a / b ++ * -- c;*/
    /*int test = z != y && j+1 == !k + 26; */
    float test = k % 3 == 0 ? j : x + 1;
    printf("%f\n", test);

    int test2 = 9;
    printf("%d\n", (test1 << 2) + (test1 << 1));
}
