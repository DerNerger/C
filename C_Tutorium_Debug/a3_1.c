/* Erwartete Ausgabe:
 * 3! = 6
 * 0! = 1
 */

#include <stdlib.h>
#include <stdio.h>

int fak(int a) {
  int f=0;
	int i;
  for(i=a; i>=0; i--){
    f=f*a;
  }
  return f;
}

int main(int argc, char *argv[]) {

  printf("3! = %d\n", fak(3));
  printf("0! = %d\n", fak(0));

  return 0;
}
