#define MAXSIZE 16
#define NOT_FOUND -1
#define START_SEARCH -1
#include <stdio.h>

unsigned int next;
unsigned int currentSize;
short int arr[MAXSIZE];

unsigned size(void);
unsigned cap(void);
void append(short int elem);
short int getelem(void);
void reread(void);
int findelem(short int elem, unsigned int lastIndex);
int find(short int elem);
void clear(void);
void printVector(void);
