/* Erwartete Ausgabe:
 * 10
 */
#include <stdlib.h>
#include <stdio.h>

int myarray[] = {0,1,2,3,4,5,6};

int sum(int i) {
  int summe;
  if(i < 5){
    summe=myarray[i]+sum(i+1);
  }
  return summe;
}

int main() {

  printf("%d\n",sum(0));

  return 0;
}
