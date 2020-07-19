#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int elemtype;
typedef struct{
	elemtype* elem;//base address of sqlist(sequence list)
	int length;//current length of element
	int listsize;//the capacity of sqlist
}SqList;

void init(SqList *L);
void addelement(SqList *L,elemtype e);
void addelementbywhichelement(SqList *L,int which,elemtype e);
void deleteelementbywhichelement(SqList *L,int which,elemtype *e);
void showSqlist(SqList *L);
void merge(SqList *A,SqList B);
