#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".sqllist.h"
#define OVERFLOW -2
#define INIT_SIZE 100
#define ADD_SIZE 10



void init(SqList *L)
{
	L->elem = (elemtype *)malloc(INIT_SIZE * sizeof(elemtype));
	if(L->elem==NULL){printf("INIT FAILED!\n");exit(OVERFLOW);}
	printf("INIT_SUCCESS!\n");
	L->length = 0;
	L->listsize = INIT_SIZE;
}

void addelement(SqList *L,elemtype e)
{
	if(L->length == L->listsize)
	{
		if(realloc(L->elem, L->listsize+ADD_SIZE)==NULL){
			printf("No more free space!\n");
			exit(OVERFLOW);
		}
		L->listsize = L->listsize + ADD_SIZE;
	}
	//(elem's base address + length)'s value  = e
	*(L->elem + L->length)=e;
	L->length++;
	printf("added elemtype %d in the list!\n",e);
	return;
}
void addelementbywhichelement(SqList *L,int which,elemtype e){
	if(which<1||which>(L->length+1))			
	{
		printf("插入位置不合法!\n请输入范围为:%d~%d的位置。\n",1,L->length+1);
		return;
	}
	if(L->length == L->listsize)
	{
		if(realloc(L->elem, L->listsize+ADD_SIZE)==NULL){
			printf("No more free space!\n");
			exit(OVERFLOW);
		}
		L->listsize = L->listsize + ADD_SIZE;
	}
	elemtype *ePtr = L->elem + which - 1;
	elemtype *EndPtr = L->elem + L->length - 1;
	while(EndPtr!=ePtr-1){
		*(EndPtr+1)=*(EndPtr);
		-- EndPtr;
	}
	*ePtr = e;
	L->length++;
	printf("插入元素%d成功!\n",e);
	return;
} 
void deleteelementbywhichelement(SqList *L,int which,elemtype* e)
{
	if(which<1||which>L->length)			
	{
		printf("删除位置不合法!\n请输入范围为:%d~%d的位置。\n",1,L->length);
		return;
	}
	elemtype *ePtr = L->elem + which - 1;
	elemtype *EndPtr = L->elem + L->length - 1;
	*e = *ePtr;
	while(ePtr!=EndPtr)
	{
		*ePtr = *(ePtr+1);
		++ePtr;
	}
	L->length--;
	printf("删除元素%d成功!\n",*e);
}
void showSqlist(SqList *L)
{
	int i = 1;	
	printf("{");
	while(i<=L->length){
		printf("%d ",*(L->elem+i-1));
		i++;	
	}
	printf("}\n");
}

void merge(SqList *A,SqList B)
{
	for(int i=0;i<B.length;i++){
		elemtype e = *(B.elem+i);
		int j=0;
		while(j<A->length-1){
			if(e==*(A->elem+j))break;
			j++;
			if((e!=*(A->elem+j))&&(j==A->length-1)){
				addelement(A,e);
				break;
			}
		}
	}
}



int main(int argc, char *argv[])
{
	SqList L;//point at the first element of sqlist
	init(&L);	
	int a,b,c,d,e;
	a = 32;b=33;c=43;d=42;e=98;
	addelement(&L, a);
	addelement(&L, b);
	addelement(&L, c);
	addelement(&L, d);
	addelement(&L, e);
	//addelementbywhichelement(&L, 3, 77);
	//showSqlist(&L);
	int res;
	//deleteelementbywhichelement(&L, 3, &res);
	//showSqlist(&L);
	SqList B;	
	init(&B);	
	a=1;b=2;c=3;d=4;e=98;
	addelement(&B, a);
	addelement(&B, b);
	addelement(&B, c);
	addelement(&B, d);
	addelement(&B, e);
	merge(&L, B);
	showSqlist(&L);
	return 0;
}






































/*
	SqList B;	
	init(&B);	
	a=1;b=2;c=3;d=4;e=98;
	addelement(&B, a);
	addelement(&B, b);
	addelement(&B, c);
	addelement(&B, d);
	addelement(&B, e);
	merge(&L, B);
 *
 * */
