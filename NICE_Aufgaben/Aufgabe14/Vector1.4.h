#define MAXSIZE 16
#define NOT_FOUND -1
#define START_SEARCH -1
#include <stdio.h>

#ifndef element_t
    #define element_t short int
#endif

unsigned int next;
unsigned int currentSize;
element_t arr[MAXSIZE];

unsigned size(void);
unsigned cap(void);
void append(element_t elem);
element_t getelem(void);
void reread(void);
#ifdef OLD_VERSION
    int findelem(element_t elem, unsigned int lastIndex);
#else
    int find(element_t elem);
#endif
void clear(void);
void printVector(void);
