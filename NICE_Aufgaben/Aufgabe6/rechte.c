#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
   int r;
   scanf("%o", &r);
   
   char arr[10];
   arr[0] = S_IRUSR & r ? 'r' : '-';
   arr[1] = S_IWUSR & r ? 'w' : '-';
   arr[2] = S_IXUSR & r ? 'x' : '-';
   arr[3] = S_IRGRP & r ? 'r' : '-';
   arr[4] = S_IWGRP & r ? 'w' : '-';
   arr[5] = S_IXGRP & r ? 'x' : '-';
   arr[6] = S_IROTH & r ? 'r' : '-';
   arr[7] = S_IWOTH & r ? 'w' : '-';
   arr[8] = S_IXOTH & r ? 'x' : '-';
   arr[9] = '\0';

   printf("%s\n", arr); 
   return 0; 
}
