#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int elemtype;
struct Node{
	elemtype data;	
	struct Node *next;
};
typedef struct Node Linkedlist;
void init(Linkedlist **L);
void append(Linkedlist **L,elemtype e);
void showList(Linkedlist **L);
int isEmpty(Linkedlist **L);
void getElem(Linkedlist **L,int which,elemtype *e);
void insertElem(Linkedlist **L,int which,elemtype e);
void deleteElem(Linkedlist **L,int which,elemtype *e);
void inputList(Linkedlist **L,int n);
void mergeList(Linkedlist **A,Linkedlist **B,Linkedlist **C);
