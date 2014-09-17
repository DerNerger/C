#define STARTSIZE 16
#include <stdio.h>
#include <stdlib.h>
#define START_SEARCH 0
#define NOT_FOUND -1

unsigned size(void);

unsigned capacity(void);

void append(short int elem);

void print(void);

short int getelem(void);

void reread();

void clear();

int findelem(short int elem, int last);

void reserve(int newSize);
