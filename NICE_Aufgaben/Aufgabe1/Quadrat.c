#define SIZE 5
#include <stdio.h>
int check(int arr[][SIZE])
{
    int sum = 0;
    int currentSum = 0;
    int i, j;
    for(i = 0;i< SIZE; i++)
        sum += arr[0][i];

    /*Zeilen */
    for(i=1; i < SIZE; i++)
    {
    currentSum = 0;

    for(j=0; j < SIZE; j++)
        currentSum += arr[i][j];
        
    if(currentSum != sum)
        return 0;
    }

    /*Spalten*/
    for(i=0; i < SIZE; i++)
    {
        currentSum = 0;
        for(j=0; j < SIZE; j++)
            currentSum += arr[j][i];
        if(currentSum != sum)
            return 0;
    }

    /*Hauptdiagonale*/
    currentSum = 0;
    for(i=0; i < SIZE; i++)
        currentSum+=arr[i][i];

    if(currentSum != sum)
        return 0;


    /*Nebendiagonale*/
    currentSum = 0;

    for(i= 0; i < SIZE; i++)
        currentSum += arr[SIZE-i-1][i];
    if(currentSum != sum)
        return 0;
    return 1;
}

int main(void)
{
    int arr[][SIZE] = {{22, 5, 18, 1, 14}
                      ,{9, 17, 0, 13, 21}
                      ,{16, 4, 12, 20, 8}
                      ,{3, 11, 24, 7, 15}
                      ,{10, 23, 6, 19, 2}};
    int isSquare = check(arr);
    if(isSquare)
        printf("%s", "Das angegebene Quadrat ist ein Magisches Quadrat\n");
    else
        printf("%s", "Das angegebene Quadrat ist kein Magisches Quadrat\n");
}
