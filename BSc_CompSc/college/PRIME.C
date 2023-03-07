//prime till n
//check if a number is prime
#include<stdio.h>
#include<conio.h>

void main()
{       int i,n,j,b,c,k,n1,flag;
	clrscr();
	printf("Enter Range - ");
	scanf("%d",&n);
	printf("Enter number to check - ");
	scanf("%d",&n1);
	printf("\nPrime numbers are-");
	for(j=2;j<=n;j++)
	{       c=0;
		for(i=1;i<=(j/2);i++)
		{	b=j%i;
			if(b==0)
				++c;
		}
		if(c==1)
			printf("\t%d",j);
	}
	c=0;
	for(i=1;i<=(n1/2);i++)
	{	b=n1%i;
		if(b==0)
			++c;
	}
	if(c==1)
		printf("\n%d is a prime number",n1);
	else
		printf("\n%d is not a prime number",n1);

	getch();
}

