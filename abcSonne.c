#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
  char *p1 = "abc", *p2 = "Sonne";

  char * newChar = (char *) malloc( strlen(p1) + strlen(p2) + 1);

  char * temp = newChar;
  while (*p1)
  {
     *(newChar++)=*(p1++);
  }
  p1 = temp;

  strcat(p1, p2);
  printf("%s \n", p1);
  exit(EXIT_SUCCESS);
}
