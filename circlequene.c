#include "circlequene.h"

STATUS init_circle_quene(circlequene *quene)
{
	quene->base = (elemtype *)malloc(MAXSIZE * sizeof(elemtype));
	if(quene->base==NULL){printf("init error!\n");return NOT;}
	quene->front = quene->rear = 0;
	return OK;
}

int QueneLength(circlequene *quene)
{
	return quene->rear - quene->base;
}


int main(int argc, char *argv[])
{
	circlequene quene;
	init_circle_quene(&quene);
	return 0;
}
