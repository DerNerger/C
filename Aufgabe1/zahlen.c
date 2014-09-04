#include <stdio.h>
#include "mydef.h"
 
int main( void )   /* gibt die ganzen Zahlen   */
{                  /*   von 1 bis 5 aus        */
  int i;
 
  printf("LIMIT = %d\n", LIMIT);
  i = 1;
  while ( i <= LIMIT )
  {
    printf("%d\n", i);
    i = i + 1;
  }
  return 0;   /* oder:  exit(EXIT_SUCCESS);    */
}
