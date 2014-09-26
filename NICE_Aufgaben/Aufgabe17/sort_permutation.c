#include <stdio.h>

#define N 50


void sel_sort_permutation(float a[], int length, int perm[])
{
  int min, i, j;
  int help;

  for (i = 0; i < length; i++)
    perm[i] = i;
  for (i = 0; i < (length-1); i++)
  {
    min = i;
    for (j = (i+1); j < length; j++)
    {
      if ( a[perm[j]] < a[perm[min]] )
        min = j;
    }
    help = perm[min];
    perm[min] = perm[i];
    perm[i] = help;
  }
}


int main( void )
{
  float list[N];
  int permutation[N];
  int i, rc = 1, len;

  /* Feld einlesen */
  for (i = 0; (i < N) && (rc == 1); i++)
  {
    rc = scanf("%f", &list[i]);
  }

  len = (rc == 1) ? i : i-1;
  sel_sort_permutation(list, len, permutation);
  for (i = 0; i < len; i++)
    printf("list[%2d] = %f\n", permutation[i], list[permutation[i]]);
  printf("\n");

  return 0;
}
