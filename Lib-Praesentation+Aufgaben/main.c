#include "swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[]){
  char* ap,* bp;
  ap = (char*) malloc(sizeof(char));
  bp = (char*) malloc(sizeof(char));

  *ap = 'a';
  *bp = 'B';

  printf("%c %c\n", *ap,*bp);
  swap(ap,bp);
  printf("%c %c\n", *ap,*bp);
}
