#include<stdio.h>
#include<conio.h>

void main()
{       int fact(int);
	int n,i;
	clrscr();
	printf("Enter range ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	       printf("%d = %d\n",i,fact(i));
	getch();
}
int fact(int x)
{	int i,f=1;
	for(i=1;i<=x;i++)
		f=f*i;
	return f;
}

