#include "Vector.h"

int main(void)
{
    int i;
    for(i = 0; i < 16; i++)
        append(i);
    printf("Size = %d\n", size());
    print();

    append(1);
    printf("Size = %d\n", size());
    print();

    printf("-------------------------------------------------\n");
    for( i = 0; i < 17; i++)
        printf("%d, ", getelem());
    printf("\n");

    for(i = 0; i < size(); i++)
        printf("%d, ", findelem(i, 0));
    printf("\n");

    reserve(5);
    print();
    printf("Cap = %d, size = %d \n", capacity(), size());


    printf("-------------------------------------------------\n");
    append(5);
    printf("Cap = %d, size = %d \n", capacity(), size());
}
