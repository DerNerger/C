/***
  Typische Anwendungen der Bit-Operatoren:

  1.) Bit setzen:

            0110 0 01   value                  | | 0  1                            
          | 0000 1 00   1<<2                  ---+--------                         
           ----------                          0 | 0  1                           
            0110 1 01                          1 | 1  1                          
                                                                       
          value | (1<<2) 

  2.) Bit loeschen:

            0110 1 01   value                  & | 0  1                            
          & 1111 0 11   ~(1<<2)               ---+--------                         
           ----------                          0 | 0  0                           
            0110 0 01                          1 | 0  1                          
                                                                       
          value & ~(1<<2)   

  3.) Bit testen:

            0110 1 01   value                  & | 0  1                            
          & 0000 1 00   (1<<2)                ---+--------                         
           ----------                          0 | 0  0                           
            0000 1 00                          1 | 0  1                          
                                                                       
          value & (1<<2)                                               
                                                                       


***/
#include <stdio.h>

enum class_t {Ziffer, Kleinbuchstabe, Grossbuchstabe, hexZiffer};

char ctype[128];   /* globales Feld */


int setbit(int n, int val)
{
  return (1<<n) | val;
}

int clearbit(int n, int val)
{
  return ~(1<<n) & val;
}

int isBuchstabe(int c)
{
  return ctype[c] & setbit(Kleinbuchstabe,setbit(Grossbuchstabe, 0));
}


int main(void)
{
  char zeichen[] = { '0', 'a', 'A' };
  int i;

  ctype['0'] = setbit(hexZiffer,setbit(Ziffer, 0)); 
  ctype['a'] = setbit(hexZiffer,setbit(Kleinbuchstabe, 0)); 
  ctype['A'] = setbit(hexZiffer,setbit(Grossbuchstabe, 0));

  for (i = 0; i < 3; i++)
  {
    printf("Das Zeichen %c ist ", zeichen[i]);
    if (isBuchstabe(zeichen[i]) == 0)
      putchar('k');
    printf("ein Buchstabe.\n");
  }
   
  return 0;
}
