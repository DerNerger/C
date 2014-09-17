#include <stdio.h>


int main( void ) {
  int c;
  int zustand = 0;

  while ( (c = getchar()) != EOF ) {
    switch ( zustand ) {
    case 0:            /* auﬂerhalb von Zeichen- und Stringkonstanten         */   
             switch ( c ) {
               case '"':   putchar(c);
                           zustand = 1;
                           break;
               case '\'':  zustand = 3;
                           break;
             }
             break;
      case 1:            /* innerhalb eines Strings, jedoch nicht nach \      */ 
             putchar(c);
             switch ( c ) {
               case '\\':  zustand = 2;
                           break;
               case '"':   putchar('\n');
                           zustand = 0;
                           break;
             }
             break;
      case 2:            /* Zeichen nach \ innerhalb eines Strings            */ 
             putchar(c);
             zustand = 1;
             break;
      case 3:       /* innerhalb einer Zeichenkonstante, jedoch nicht nach \  */ 
             switch ( c ) {
               case '\\':  zustand = 4;
                           break;
               case '\'':  zustand = 0;
                           break;
             }
             break;
      case 4:            /* Zeichen nach \ innerhalb einer Zeichenkonstante   */ 
             zustand = 3;
             break;
    }
  }
  if ( zustand != 0 )
    printf("\nerror: unterminated string or character constant at eof\n");

  return 0;
}
