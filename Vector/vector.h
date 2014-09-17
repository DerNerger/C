#define CAPACITY 16
#define NOT_FOUND 16
#define START_SEARCH 0
/* #define OLD_VERSION*/
#define element_t short int

unsigned size (void);
unsigned capacity (void);
void append (element_t elem);
element_t getelem(void);
int findelem (element_t elem, int lastfound);
/* Aufgabe 2:
#ifdef OLD_VERSION
    int findelem (element_t elem, int lastfound);
#else
    int sind(element_t elem);
#endif
*/
void clear(void);
int find(element_t elem);
