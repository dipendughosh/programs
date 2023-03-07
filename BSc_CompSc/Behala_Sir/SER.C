//1,8,2,10,3,12,4,.......
#include<stdio.h>
#include<conio.h>

void main()
{       int i,j;
	clrscr();
	for(i=1,j=8;i<=10 && j<=26;i++,j+=2)
		printf("%d\t%d\t",i,j);

	getch();
}

