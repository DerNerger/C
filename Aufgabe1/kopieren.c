#include <stdio.h>

int main( void )   /* kopiert Standardeingabe */
{                  /*   zur Standardausgabe   */
  int c;

  while ( (c = getchar()) != EOF )
    putchar(c);
  return 0;
}
