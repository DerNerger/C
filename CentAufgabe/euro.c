#include <math.h>
#include "euro.h"
#include <stdlib.h>

char* eurtostr(eur_t euro)
{
   char *arr ;
   if(euro < 100 && euro > -100)
   {
      int start = 0, length = 5;
      if(euro < 0)
      {
          start = 1;
          length = 6;
      }
      arr = (char *) malloc(length * sizeof(char) );
      if(euro < 0)
          arr[0] = '-';
      arr[start + 1] = '0';
      arr[start + 2] = ',';
      arr[start + 3] = euro / 10 +'0';
      arr[start + 4] = euro % 10 +'0';
      arr[start + 5] = '\0';
   }
   return arr;
}
