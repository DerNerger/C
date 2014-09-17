#include <stdio.h>
#include "vector.h"


int main( void )
{
  int i, pos;

  append(1); 
  append(2); 
  append(3);   

  for (i = 0; i<size(); i++)
    printf("%d\n", getelem());

  reread();
  printf("%d\n", getelem()); /* --> 1 */

  append(2);
  /* 1  2  3  2  */
  pos = findelem(2,START_SEARCH);  /* --> 2 (1) */
  printf("1. Vorkommen der Zahl 2: %d\n", pos);
  pos = findelem(2,pos);  /* --> 4 (3) */  
  printf("2. Vorkommen der Zahl 2: %d\n", pos);              

  if (findelem(2,pos) != NOT_FOUND) /* --> NOT_FOUND */
    printf("Zahl 2 ist mehr als 2-mal im Vektor enthalten.\n");

  return 0;
}
