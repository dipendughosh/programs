#include<stdio.h>
#include<conio.h>

void main()
{       int a,b;
	clrscr();
	printf("Enter marks in A:- ");
	scanf("%d",&a);
	printf("Enter marks in B:- ");
	scanf("%d",&b);
	if(a>=55 && b>=45)
		printf("\nDegree Awarded");
	else if(a>=45 && a<55 && b>=55)
		printf("\nDegree Awarded");
	else if(a>=65 && b<45)
		printf("\nReappear in B");
	else
		printf("\nFail");

	getch();
}

