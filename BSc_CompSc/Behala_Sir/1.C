//s=1+2+3+4+...........+n(done)
#include<stdio.h>
#include<conio.h>

void main()
{	int n,i,s=0;
	clrscr();
	printf("Enter value of n :- ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		s=s+i;
	printf("\nS = %d",s);
	i=1;
	s=0;
	while(i<=n)
	{	s=s+i;
		i=i+1;
	}
	printf("\nS = %d",s);
	getch();
}

