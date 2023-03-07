//sum of digits,if pallindrom,reverse digit
#include<stdio.h>
#include<conio.h>

void main()
{       int n,n1,a,s1=0,s2=0;
	clrscr();
	printf("Enter a number - ");
	scanf("%d",&n);
	n1=n;
	while(n1>0)
	{	a=n1%10;
		s1=s1+a;
		s2=s2*10;
		s2=s2+a;
		n1=n1/10;
	}
	printf("\nSum of digits = %d\nReverse = %d",s1,s2);
	if(n==s2)
		printf("\nPallindrome");
	else
		printf("\nNot Pallindrome");
	getch();
}

