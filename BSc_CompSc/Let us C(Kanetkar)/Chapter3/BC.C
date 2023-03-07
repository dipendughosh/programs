#include<stdio.h>
#include<conio.h>

void main()
{       int i,x,y,s=1;
	clrscr();
	printf("Enter Number :- ");
	scanf("%d",&x);
	printf("Enter Power :- ");
	scanf("%d",&y);
	for(i=0;i<y;i++)
		s=s*x;
	printf("\n%d ^ %d = %d",x,y,s);

	getch();
}

