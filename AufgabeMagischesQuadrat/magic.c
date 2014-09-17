#include <stdio.h>

#ifndef SIZE
    #define SIZE 5 
#endif

#if SIZE%2==0
    #error Kantenlaenge muss ungerade sein
#endif

int isMagic(int arr[SIZE][SIZE])
{
    int sum = 0, i, j;
    for(i = 0; i < SIZE; i++)
        sum += arr[0][i];
    printf("Die Summe der 0-ten Zeile ist %d\n", sum);
    
    int currentSum;
    for(i = 1; i < SIZE; i++)
    {
        currentSum = 0;
        for(j = 0; j < SIZE; j++)
            currentSum += arr[i][j];
        printf("Die Summe der %d-ten Zeile ist %d\n", i, currentSum); 
        if(currentSum != sum)
            return 0;
    }

    for(i = 0; i < SIZE; i++)
    {
        currentSum = 0;
        for(j = 0; j < SIZE; j++)
            currentSum += arr[j][i];
        printf("Die Summe der %d-ten Spalte ist %d\n", i, currentSum); 
        if(currentSum != sum)
            return 0;
    }

    currentSum = 0;
    for(i = 0; i < SIZE; i++)
        currentSum += arr[i][i];
    printf("Die Summe der Diagonalen ist %d\n", currentSum); 
    if(currentSum != sum)
        return 0;

    currentSum = 0;
    for(i = 0; i < SIZE; i++)
        currentSum += arr[SIZE-1-i][i];
    printf("Die Summe der Gegendiagonalen ist %d\n", currentSum); 
    if(currentSum != sum)
        return 0;

    return 1;
}

void createMagic(int arr[SIZE][SIZE])
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            int a_ij, b_ij;
            if( ((i+j) % SIZE) % 2 == 0 )
		a_ij = ((i+j) % SIZE);
	    else
                a_ij = (SIZE + (i+j) % SIZE);

            if( ((i-j+SIZE)%SIZE) % 2 == 1)
		b_ij = SIZE * (((i-j+SIZE) % SIZE ) - 1);
            else
		b_ij = SIZE * (SIZE - 1 + (i - j + SIZE) % SIZE );
  
            arr[i][j] = 0.5 * (a_ij + b_ij); 
        }
    }
}

int main(void)
{
    /*
    int arr[5][5] = 
                          {{22, 5, 18, 1, 14},
                           {9, 17, 0, 13, 21},
		           {16, 4, 12, 20, 8}, 
			   {3, 11, 24, 7, 15}, 
			   {10, 23, 6, 19, 2}};*/
    int arr[SIZE][SIZE];
    createMagic(arr);
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
	for(j = 0; j < SIZE; j++)
		printf("%d, ", arr[i][j]);
        printf("\n");
    }
    
    int result = isMagic(arr);

    if(result)
        printf("Magic\n");
    else
        printf("not Magic\n");
    return 0;
}
