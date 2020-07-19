#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define NOT 0
typedef int status;
typedef int elemtype;
struct Node{
	elemtype e;
	struct Node *next;
};
typedef struct {
	struct Node * front;
	struct Node * rear;
}LinkedQuene;
status InitQuene(LinkedQuene *quece);
status DestroyQuene(LinkedQuene *quece);
status ClearQuene(LinkedQuene *quece);
status QueneEmpty(LinkedQuene *quece);
int QueneLength(LinkedQuene *quece);
status GetHead(LinkedQuene *quece,elemtype *e);
status EnQuene(LinkedQuene *quece,elemtype e);
status DeleteQuene(LinkedQuene *quece,elemtype *e);
status PrintQuene(LinkedQuene *quece);
