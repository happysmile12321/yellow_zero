#include "linkedlist.h"

//set head node
void init(Linkedlist **L){
	
	//save length of linkedlist
	(*L) = (Linkedlist *)malloc(sizeof(Linkedlist));
	if(!(*L)){printf("OVERFLOW!\n");return;}
	(*L)->next = NULL;	
	(*L)->data = 0;
	printf("init linkedlist success!\n");
}

void append(Linkedlist **L,elemtype e)
{
	Linkedlist *temp;
	temp = *L;
	while(temp->next!=NULL)	
	{
		temp = temp -> next;
	}
	temp->next = (Linkedlist *)malloc(sizeof(Linkedlist));	
	temp->next->data = e;
	temp->next->next = NULL;
	(*L)->data++;
}

void showList(Linkedlist **L)
{
	printf("{");
	Linkedlist* LPtr = (*L)->next;
	while(LPtr!=NULL)
	{
		printf("%d ",LPtr->data);
		LPtr = LPtr->next;
	}
	printf("}\n");
}
int isEmpty(Linkedlist **L)
{
	if((*L)->next == NULL){
		printf("Linkedlist is empty!\n");
		return TRUE;
	}
	return FALSE;
}


void getElem(Linkedlist **L,int which,elemtype *e)
{
	Linkedlist *temp = (*L)->next;
	int i = 1;
	while(temp && (i<which)){
		temp = temp->next;
		++i;
	}
	if(temp==NULL||i>which)
	{
		printf("Element not exits!\n");
		return;
	}
	*e = temp -> data;
	return;
}

void insertElem(Linkedlist **L,int which,elemtype e)
{
	Linkedlist *temp = *L;	
	int i = 0;		
	while(temp!=NULL && i < (which - 1))
	{
		temp = temp->next;
		++i;
	}
	if(temp==NULL||i>(which-1))
	{
		printf("insert position is not leagal\n");
		return;
	}
	Linkedlist *ePtr = (Linkedlist *)malloc(sizeof(Linkedlist));
	ePtr->data = e;
	ePtr->next = temp->next;
	temp->next = ePtr;
	(*L)->data++;
}

void deleteElem(Linkedlist **L,int which,elemtype *e)
{
	Linkedlist *temp = *L;	
	int i = 0;		
	while((temp->next)!=NULL && i < (which - 1))
	{
		temp = temp->next;
		++i;
	}
	if(temp->next==NULL||i>(which-1))
	{
		printf("delete position is not leagal\n");
		return;
	}
	*e = temp->next->data;
	Linkedlist *s = temp->next;
	temp->next = s->next;
	(*L)->data --;
	free(s);
}

void inputList(Linkedlist **L,int n)
{
	Linkedlist *lPtr = *L;
	lPtr = (Linkedlist *)malloc(sizeof(Linkedlist));
	if(!lPtr) exit(1);
	lPtr->next = NULL;
	lPtr->data = 0;
	//init done
	printf("Please input element:");
	for(int i = 0;i<n;i++){
		Linkedlist *s = (Linkedlist *)malloc(sizeof(Linkedlist));
		if(!s) exit(1);
		(*L)->data++;
		scanf("%d",&(s->data));
		s->next = lPtr->next;
		lPtr->next = s;
	}
	*L = lPtr;
}
void mergeList(Linkedlist **A,Linkedlist **B,Linkedlist **C)
{
	Linkedlist *APtr = (*A)->next;
	Linkedlist *BPtr = (*B)->next;
	Linkedlist *CPtr = *C;
	*C = CPtr;
	while((APtr!=NULL)&&(BPtr!=NULL))	
	{
		if(APtr->data <= BPtr->data)	
		{
			CPtr->next = APtr;
			CPtr = APtr;
			APtr = APtr->next;
		}else{
			CPtr->next = BPtr;
			CPtr = BPtr;
			BPtr = BPtr->next;
		}
	}
	(*C)->data = (*A)->data + (*B)->data;
	CPtr->next = APtr?APtr:BPtr;	
	return;
}



int main(int argc, char *argv[])
{
	Linkedlist *L;
	init(&L);


	return 0;
}

/*
	Linkedlist *L1,*L2;
	init(&L1);
	init(&L2);
	append(&L1, 80);	
	append(&L1, 20);	
	append(&L1, 30);	
	append(&L1, 40);	
	append(&L1, 50);	
	mergeList(&L,&L1,&L2);
*/
