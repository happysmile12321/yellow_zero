#include "quene.h"

/*
 *|-|--head node(<-q.rear  <- q.front)
 * */

status InitQuene(LinkedQuene *quene)
{
	quene->rear = (struct Node *)malloc(sizeof(struct Node));	
	quene->front = quene->rear;
	if(quene->front==NULL) {printf("malloc failed!\n");exit(1);}
	quene->front->next = NULL;
	printf("Init quene success!\n");
	return OK;
}

status DestroyQuene(LinkedQuene *quene)
{
	while(quene->front!=NULL)
	{
		quene->rear = quene->front->next;
		free(quene->front);
		quene->front = quene->rear;
	}	
	return OK;
}

status ClearQuene(LinkedQuene *quene)
{
	DestroyQuene(quene);	
	return OK;
}

int QueneLength(LinkedQuene *quece)
{
	int len = 0;		
	while(quece->front!=quece->rear)
	{
		quece->front = quece->front->next;
		len ++;
	}
	return len;
}

status GetHead(LinkedQuene *quece,elemtype *e)
{
	if(quece->front->next==NULL){printf("quene is empty!\n");return NOT;}
	*e = quece->front->next->e;
	return OK;
}


status EnQuene(LinkedQuene *quece,elemtype e)
{
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));
	if(node == NULL){printf("memory leak!!!\n");exit(1);}
	node->e = e;
	node->next = NULL;
	quece->rear->next = node;
	quece->rear = node;
	return OK;	
}

status PrintQuene(LinkedQuene *quece)
{
	printf("{ ");
	struct Node *tempPtr = quece->front->next;
	while(tempPtr!=NULL)
	{
		printf(" %d ",tempPtr->e);
		tempPtr = tempPtr->next;
	}
	printf("}\n");
	return OK;
}

/*
status DeleteQuene(LinkedQuene *quece,elemtype *e);
*/

status DeleteQuene(LinkedQuene *quece,elemtype *e)
{
	if(quece->front->next==NULL){printf("this quene is empty!\n");return NOT;}
	struct Node * node = quece->front->next->next;
	*e = quece->front->next->e;
	free(quece->front);
	quece->front->next = node;
	return OK;
}


int main(int argc, char *argv[])
{
	LinkedQuene quene;	
	InitQuene(&quene);
	EnQuene(&quene, 1);
	EnQuene(&quene, 2);
	EnQuene(&quene, 3);
	EnQuene(&quene, 4);
	EnQuene(&quene, 5);
	EnQuene(&quene, 6);
	EnQuene(&quene, 7);
	PrintQuene(&quene);
	return 0;
}
	//DestroyQuene(&quene);
	//int res = QueneLength(&quene);	
	//printf("length of quene is %d\n",res);
	//elemtype res;
	//GetHead(&quene, &res);
	//printf("res:%d\n",res);
	//elemtype res;
	//DeleteQuene(&quene, &res);
	//printf("delete %d\n",res);
