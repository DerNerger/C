/* Erwartete Ausgabe:
 * 2*3*4 = 24
 */
 
#include <stdlib.h>
#include <stdio.h>

int mult(int a, int b) {
  if (a=1) return b;
  else return mult(a-1,b) + mult(1,b);
}

int main(int argc, char *argv[]) {
  int i=1;
  int result=i;

  int zahlen[]={2, 3, 4};

  while(i<3){
    result=mult(result, zahlen[i]);
    i++;
  }

  printf("2*3*4 = %d\n", result);

  return 0;
}
