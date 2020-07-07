#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef int elemtype;
typedef struct {
	elemtype e;	
	int cur;	
}Linkedlist[MAX_SIZE];
void showList(Linkedlist L);
void fillList(Linkedlist L);
void locateElem(Linkedlist L,elemtype e);
void locateElem2(Linkedlist L,elemtype e);
void deleteElem(Linkedlist L,elemtype e);
void initList(Linkedlist L);
int malloc_SL(Linkedlist L);
