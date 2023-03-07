#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{	long int n,s=0,i=0,a;
	clrscr();
	printf("Enter a number ");
	scanf("%ld",&n);
	while(n>0)
	{	a=n%10;
		a=a+1;
		if(a>9)
			a=0;
		if(i==0)
			s=s+a;
		else
		{	a=a*pow(10,i);
			s=s+a;
		}
		n=n/10;
		i++;
	}
	printf("\nThe number is = %ld",s);
	getch();
}

