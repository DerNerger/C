#include <stdio.h>
#include <stdlib.h>

int backtracing(int n) {
    if(n==0) return 0;
    else return backtracing(n-1) + 1;
}

int main(int argc, char **argv){

  int array[]={1,2,3333,4,5}; // Inhalt eines arrays ansehen und modifizieren
    
  int *a=array; // adressen vergleichen

  char c = 'c'; //verschiedene variablen anzeigen, verschiedene Darstellungsformate, speicherbereich…
  char string[] = "Hallo Matse!";
  double d = 3.14d;

  char *arg0=argv[0]; //Inhalt ansehen und zeigen, wie die argumente übergeben werden
  char *arg1=argv[1];
  int  arg2=atoi(argv[2]);
 
  printf("Bitte irgendein Zahl eingeben: ");
  scanf("%d",a); //Zeigen wie die Konsoleneingabe funktioniert
 
  int i = backtracing(7); //Stack/backtrace anschauen

  for(i=0; i!=1; i+=1){ //endlose Schleife finden und korrigieren.
      i-=2;
  }
   
}