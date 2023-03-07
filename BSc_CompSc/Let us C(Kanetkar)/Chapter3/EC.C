#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,n;
	double a=0,f,s;
	clrscr();
	printf("Enter value of n :- ");
	scanf("%d",&n);
	s=1;
	for(i=2;i<=n;i++)
	{       f=1;
		for(j=1;j<=i;j++)
			f=f*j;
		a=i/f;
		s=s+a;
	}
	printf("\nSum = %lf",s);
	getch();
}

