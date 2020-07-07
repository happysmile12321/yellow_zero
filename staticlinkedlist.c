#include "staticlinkedlist.h"


int main(int argc, char *argv[])
{
	Linkedlist L;
	(L+1)->e = 99;
	printf("%d\n",L[1].e);
	return 0;
}
