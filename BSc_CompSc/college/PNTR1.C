#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>


void main()
{       int *p,n,i;
	clrscr();
	printf("Enter number of elements:- ");
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	printf("Enter Elements\n");
	for(i=1;i<n;i++);
		scanf("%d",(p+i));
	printf("Entered Elements are:-");
	for(i=1;i<n;i++);
		printf("\t%d",*(p+i));
	getch();
}

