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

void toOct(stack *s,stackelem d)
{
	int divide = d;
	do{
		push(s, divide % 8);
		divide = divide / 8;
	}while(divide != 0);
	int res;
	while(s->top != s->base)
	{
		pop(s,  &res);
		printf("%d",res);
	}
}

void handlebracket(stack *s,char *text)
{
	int text_length;
	text_length = strlen(text);
	int i = 0;
	char c;
	int temp;
	printf("text:%s\n",text);
	while(i<text_length)
	{
		c = *(text+i);
		switch(c)
		{
			case '{':
				push(s, (int)c);
				break;
			case '(':
				push(s, (int)c);
				break;
			case ')':
				pop(s, &temp);
				if((char)temp!='(')
				{
					printf("\nError handle )\n");
				}
				break;
			case '}':
				pop(s, &temp);
				if((char)temp!='{')
				{
					printf("\nError handle }\n");
				}
				break;
			default:
				printf("[%c]  ",c);
				break;
		}
		i++;
	}


}


int main(int argc, char *argv[])
{
	stack s;
	stack_init(&s);
	handlebracket(&s,"{({hello})}");
	return 0;

}
/*
	int e;
	get_top(&s, &e);
	printf("res = %d\n",e);
	------
	int i = 1;
	while(1)
	{
		struct timeval tv;
		tv.tv_sec = 0;
		tv.tv_usec = 10000;
		select(0, NULL, NULL, NULL, &tv);
		printf("i=%d\n",i);
		push(&s, i);	
		i++;
	}
	-------------
	toOct(&s, 16);
	printf("\n%o",16);

*/
