#include<stdio.h>
#include<conio.h>

void main()
{       int s,c,s1,c1;
	clrscr();
	printf("Enter customer needs:-\n");
	printf("Enter stock:-");
	scanf("%d",&s);
	printf("Enter credit:-");
	scanf("%d",&c);
	printf("Enter company details:-\n");
	printf("Enter stock:-");
	scanf("%d",&s1);
	printf("Enter credit:-");
	scanf("%d",&c1);
	if(s<=s1 && c<=c1)
		printf("\nSupplt will be sent");
	else if(c>c1)
		printf("\nNo Supply");
	else if(s>=s1 && c<=c1)
		printf("\nBalance will be sent soon");
	getch();
}

