#include <stdio.h>
#include <stdlib.h>

#define N 50

void sel_sort_permutation(float a[], int length, float *perm[N])
{
  int min, i, j;
  float* help;

  for (i = 0; i < length; i++)
    perm[i] = &a[i];
  for (i = 0; i < (length-1); i++)
  {
    min = i;
    for (j = (i+1); j < length; j++)
    {
      if ( *perm[j] < *perm[min] )
        min = j;
    }
    help= perm[min];
    perm[min] = perm[i];
    perm[i] = help;
  }
}


int main( void )
{
  float list[N];
  // float ** permutation = malloc(N*sizeof(float *));
  float * permutation[N] ;
  int i, rc = 1, len;

  /* Feld einlesen */
  for (i = 0; (i < N) && (rc == 1); i++)
  {
    rc = scanf("%f", &list[i]);
  }

  len = (rc == 1) ? i : i-1;
  sel_sort_permutation(list, len, permutation);
  for (i = 0; i < len; i++)
    printf("list[%2d] = %f\n", i, *permutation[i]);
  printf("\n");

  return 0;
}
