#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{       int i=0,a,n,s=0,t;
	clrscr();
	printf("Enter number :- ");
	scanf("%d",&n);
	while(n!=0)
	{	a=n%8;
		t=pow(10,i);
		s=s+(a*t);
		n=n/8;
		i++;
	}
	printf("\n%d",s);

	getch();
}

