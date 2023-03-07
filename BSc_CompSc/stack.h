#include <stdlib.h>
typedef enum{false,true}bool;
typedef struct node
{
	int data;
	struct node*link;
}stack;

void push(stack**s,int data)
{
	stack*t;
	if((t=(stack*)malloc(sizeof(stack)))==NULL)
	{
		printf("\n\tERROR: OVERFLOW.!!!");
		return;
	}
	t->link=(*s);
	t->data=data;
	(*s)=t;
}

int pop(stack**s)
{
	int d;
	stack*t;
	t=(*s);
	if(t==NULL)
	{
		printf("\n\tERROR: UNDERFLOW.!!!");
		return -6799999;
	}
	(*s)=(*s)->link;
	d=t->data;
	free(t);
	return d;
}

bool isempty(stack*s)
{
	return (s==NULL)?true:false;
}
