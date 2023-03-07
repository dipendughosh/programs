//pallindrom integer
#include<stdio.h>
#include<conio.h>

void main()
{       long int n,n1,a,s=0;
	clrscr();
	printf("Enter a number - ");
	scanf("%ld",&n);
	n1=n;
	while(n1>0)
	{	a=n1%10;
		s=s*10;
		s=s+a;
		n1=n1/10;
	}
	if(n==s)
		printf("\nPallindrome");
	else
		printf("\nNot Pallindrome");
	getch();
}

