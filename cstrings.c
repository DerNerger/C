#include <stdio.h>
enum Zustaende
{
    outside_str_or_char, inside_str, escape_inside_str, inside_char, escape_inside_char
};

int main( void ) {
  int c;
  enum Zustaende zustand = outside_str_or_char;

  while ( (c = getchar()) != EOF ) {
    switch ( zustand ) {
    case outside_str_or_char:            /* außerhalb von Zeichen- und Stringkonstanten         */   
             switch ( c ) {
               case '"':   putchar(c);
                           zustand = inside_str;
                           break;
               case '\'':  zustand = inside_char;
                           break;
             }
             break;
      case inside_str:            /* innerhalb eines Strings, jedoch nicht nach \      */ 
             putchar(c);
             switch ( c ) {
               case '\\':  zustand = escape_inside_str;
                           break;
               case '"':   putchar('\n');
                           zustand = outside_str_or_char;
                           break;
             }
             break;
      case escape_inside_str:            /* Zeichen nach \ innerhalb eines Strings            */ 
             putchar(c);
             zustand = inside_str;
             break;
      case inside_char:       /* innerhalb einer Zeichenkonstante, jedoch nicht nach \  */ 
             switch ( c ) {
               case '\\':  zustand = inside_char;
                           break;
               case '\'':  zustand = outside_str_or_char;
                           break;
             }
             break;
      case escape_inside_char:            /* Zeichen nach \ innerhalb einer Zeichenkonstante   */ 
             zustand = inside_char;
             break;
    }
  }
  if ( zustand != outside_str_or_char )
    printf("\nerror: unterminated string or character constant at eof\n");

  return 0;
}
