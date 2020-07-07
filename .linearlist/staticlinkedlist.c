#include "staticlinkedlist.h"

void showList(Linkedlist L)
{
	printf("{");
	int i = L[0].cur; 
	for(int j = 0;j<L[0].e;j++)
	{
		printf("%d ",L[i].e);
		i = L[i].cur;
	}
	printf("}\n");
}

void fillList(Linkedlist L)
{
	for(int i = 0;i<MAX_SIZE;i++)
	{
		L[i].cur = i + 1;
		L[i].e = i;
	}
	L[0].e = MAX_SIZE - 1;
}

void locateElem2(Linkedlist L,elemtype e)
{
	int j = 0;//which
	int i = 0;//cur
	//O(n)
	while(j<MAX_SIZE)
	{
		i = L[i].cur;
		if(L[i].e == e)break;
		j++;
	}
	printf("i = %d\n",i);
}

void locateElem(Linkedlist L,elemtype e)
{
	int i = L[0].cur;
	while(i && (L[i].e != e))
	{
		i = L[i].cur;
	}
	printf("i = %d\n",i);
}

void deleteElem(Linkedlist L,elemtype e)
{
	int i = 0;
	while(L[L[i].cur].e != e)
	{
		i = L[i].cur;
	}
	L[i].cur = L[L[i].cur].cur;
	L[0].e --;
}

void initList(Linkedlist L)
{
	for(int i = 0;i < MAX_SIZE - 1; i++)	
	{
		L[i].cur = i + 1;
	}
	L[MAX_SIZE - 1].cur = 0;// return to head
}

int malloc_SL(Linkedlist L)
{
	int i = L[0].cur;
	if(i){
		
	} 
	return i;
}



int main(int argc, char *argv[])
{
	Linkedlist L;
	initList(L);
	return 0;
}

/*
	{
	//	L[0].cur = 1;
	//	L[1].e = 1;
	//	L[1].cur = 2;
	//	L[2].e = 2;
	//	L[2].cur = 3;
	}
	locateElem(L, 3);
	locateElem2(L, 3);
*/

/*
 *
 *
	fillList(L);
	deleteElem(L, 4);
	deleteElem(L, 66);
	showList(L);	
	locateElem(L, 65);
 * */
