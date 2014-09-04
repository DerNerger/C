#include <sys/stat.h>
#include <stdio.h>

int printRechte(int z)
{
    int arr[10];
    arr[0] = z & S_IRUSR ? 'r' : '-';
    arr[1] = z & S_IWUSR ? 'w' : '-';
    arr[2] = z & S_IXUSR ? 'x' : '-';
    arr[3] = z & S_IRGRP ? 'r' : '-';
    arr[4] = z & S_IWGRP ? 'w' : '-';
    arr[5] = z & S_IXGRP ? 'x' : '-';
    arr[6] = z & S_IROTH ? 'r' : '-';
    arr[7] = z & S_IWOTH ? 'w' : '-';
    arr[8] = z & S_IXOTH ? 'x' : '-';
    arr[9] = "\0";
    printf("%s"arr);
}

int main(void)
{
    int input;
    scanf("%d", &input);
    printRechte(input);
}
