//multiplication table
#include<stdio.h>
#include<conio.h>


void main()
{  	int i,j;
	clrscr();
	for(i=1;i<=10;i++)
		printf("\t%d",i);
	printf("\n");
	for(i=1;i<=10;i++)
	{	printf("%d\t",i);
		for(j=1;j<=10;j++)
			printf("%d\t",i*j);
		printf("\n");
	}
	getch();
}

