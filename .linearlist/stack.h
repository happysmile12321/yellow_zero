#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT_SIZE 80 
typedef int stackelem;
typedef struct{
	stackelem *base;
	stackelem *top;
	int stack_size;
}stack;
void stack_init(stack* s);
void get_top(stack* s,stackelem *e);
void push(stack* s,stackelem e);
void pop(stack* s,stackelem *e);
void toOct(stack *s,stackelem e);
