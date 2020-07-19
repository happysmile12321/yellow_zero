#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT_SIZE 80 
#define TRUE 1
#define FALSE 0
typedef int STATUS;
typedef char stackelem;
typedef struct{
	stackelem *base;
	stackelem *top;
	int stack_size;
}stack;
void stack_init(stack* s);
void get_top(stack* s,stackelem *e);
void push(stack* s,stackelem e);
void pop(stack* s,stackelem *e);
void emptystack(stack* s);
STATUS isempty(stack *s);
void lineedit(stack* s);
