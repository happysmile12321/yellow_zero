#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 6
#define OK 1
#define NOT 0
typedef int elemtype;
typedef int STATUS;
typedef struct {
	elemtype *base;	
	int front;
	int rear;
}circlequene;

STATUS init_circle_quene(circlequene *quene);
int QueneLength(circlequene *quene);
