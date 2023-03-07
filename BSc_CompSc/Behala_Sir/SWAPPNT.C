#include<stdio.h>
#include<conio.h>

void main()
{       void swap(int *,int *);
	int x,y;
	clrscr();
	printf("Enter value of x ");
	scanf("%d",&x);
	printf("Enter value of y ");
	scanf("%d",&y);
	swap(&x,&y);
	printf("\nx=%d \ny=%d ",x,y);
	getch();
}
void swap(int *a,int *b)
{	int c;
	c=*a;
	*a=*b;
	*b=c;
}

