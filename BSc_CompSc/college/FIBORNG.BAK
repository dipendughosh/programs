//fibo series
//check if number is fibo
#include<stdio.h>
#include<conio.h>

void main()
{       long int n1,n,a,b,c,i,flag=0;
	clrscr();
	a=1;
	b=1;
	c=0;
	printf("Enter range ");
	scanf("%ld",&n);
	printf("Enter number to check ");
	scanf("%ld",&n1);
	printf("%ld\t%ld",a,b);
	for(i=2;i<n;i++)
	{       c=a+b;
		printf("\t%ld",c);
		a=b;
		b=c;
	}
	a=b=1;
	for(i=2;i<=n1;i++)
	{	c=a+b;
		a=b;
		b=c;
		if(n1==c)
			flag=1;
	}
	if(flag==1)
		printf("\n%d is a fibonacci number",n1);
	else
		printf("\n%d is not a fibonacci number",n1);
	getch();
}

