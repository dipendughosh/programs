#include<stdio.h>
#include<conio.h>

void main()
{       int n,x,i;
	int prime(int);
	clrscr();
	printf("Enter +ive int number - ");
	scanf("%d",&n);
	for(i=2;i<n/2;i++)
	{	if(n/i==0)
		{	x=prime(i);
			if(x==1)
				printf("%d ",i);
		}
	}
	getch();
}
int prime(int a)
{	int b,c,i;
	for(i=1;i<=(a/2);i++)
	{	b=a%i;
		if(b==0)
			++c;
	}
	if(c==1)
		return(1);
	else
		return(0);
	return(0);
}