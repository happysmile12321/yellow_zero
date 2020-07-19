#include "stack.h"
/*
 *|     |top
 *|e    |
 *|e    |
 *|e    |
 *|e    |
 *|e    |base
 Actually,top pointer always point the last in elem's tail addr.
 * */

void stack_init(stack* s)
{
	s->base = (stackelem *)malloc(STACK_INIT_SIZE * sizeof(stackelem));
	if(s->base == NULL){printf("init error\n");return;}
	s->top = s->base; 
	s->stack_size = STACK_INIT_SIZE;		
	printf("init success!\n");
}

void emptystack(stack *s)
{
	s->base = s->top;
}

void get_top(stack* s,stackelem *e)
{
	if(s->top == s->base){printf("\nStack is empty,error!\n");return;}
	*e = *(s->top-1);
}

void push(stack* s,stackelem e)
{
	if((s->top-s->base)==s->stack_size)	
	{
		s->base = (stackelem *)realloc(s->base, s->stack_size + STACK_INCREMENT_SIZE);
		if(s->base==NULL){printf("Not enough space to malloc\n");return;}
		s->stack_size += STACK_INIT_SIZE;
	}
	*(s->top) = e;
	s->top ++;
}

void pop(stack* s,stackelem *e)
{
	if(s->top == s->base){printf("Stack is empty,error!\n");return;}
	*e = *(s->top-1);
	s->top --;
}

STATUS isempty(stack* s)
{
	return (s->base==s->top)?TRUE:FALSE;	
}


void lineedit(stack* s)
{
	FILE *file = fopen("file", "r");
	char ch;
	char temp;
		if(file!=NULL){
			while((ch=getc(file))!=EOF){
				switch(ch)
				{
					case '#':
						pop(s, &temp);
						break;
					case '@':
						emptystack(s);
						break;
					case '\n':
						printf("\nline start:\n");
						while(!isempty(s))	
						{
							pop(s, &temp);
							printf("%c",temp);
						}
						printf("\nline end\n");
						break;
					default:
						push(s, ch);

				}//end switch
			}//end while
		}//end if
}



int main(int argc, char *argv[])
{
	stack s;
	stack_init(&s);
	lineedit(&s);
	return 0;

}
