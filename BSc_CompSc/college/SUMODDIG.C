//sum of odd digits
#include<stdio.h>
#include<conio.h>

void main()
{       long int n,a,s2=0,i;
	clrscr();
	printf("Enter number ");
	scanf("%ld",&n);
	while(n>0)
	{	a=n%10;
		s2=s2*10;
		s2=s2+a;
		n=n/10;
	}
	n=s2;
	s2=0;
	i=1;
	while(n>0)
	{	a=n%10;
		if(i%2!=0)
			s2=s2+a;
		i++;
		n=n/10;
	}
	printf("\nSum of digits in the odd position = %ld",s2);
	getch();
}

