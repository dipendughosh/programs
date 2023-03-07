#include<stdio.h>
#include<conio.h>

void main()
{	int r,s,a;
	clrscr();
	printf("Enter age of Ram ");
	scanf("%d",&r);
	printf("Enter age of Sam ");
	scanf("%d",&s);
	printf("Enter age of Ajay ");
	scanf("%d",&a);
	if(r<a && r<s)
		printf("\nRam");
	else if(s<a && s<r)
		printf("\nSam");
	else
		printf("\nAjay");
	getch();
}

