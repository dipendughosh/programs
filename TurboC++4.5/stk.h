#include<stdio.h>
int arr[10],tp=-1;
void push(int a)
{  if(tp==10)
	{	printf("FULL stack");
		return;
	}
	tp++;
	arr[tp]=a;
	return;
}

int pop()
{	int a;
	if(tp==-1)
	{	printf("EMPTY stack");
		return(0);
	}
	a=arr[tp];
	tp--;
	return(a);
}
