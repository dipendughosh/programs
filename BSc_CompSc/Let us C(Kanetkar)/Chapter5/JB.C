#include<stdio.h>
#include<conio.h>

void main()
{	void factor(int);
	int n;
	clrscr();
	printf("Enter number - ");
	scanf("%d",&n);
	factor(n);
	getch();
}

void factor(int n)
{       int a,i=2;
	while(n!=0)
	{	a=n%i;
		if(a==0)
		{	printf("%d",i);
			n=n/i;
		}
		else
			i++;
	}
}
