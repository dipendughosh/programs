//marks of a studnt entrd output division
#include<stdio.h>
#include<conio.h>

void main()
{       int m1,m2,m3,m4,m5;
	float s;
	clrscr();
	printf("Enter marks student:-\n");
	printf("Sub1 = ");
	scanf("%d",&m1);
	printf("Sub2 = ");
	scanf("%d",&m2);
	printf("Sub3 = ");
	scanf("%d",&m3);
	printf("Sub4 = ");
	scanf("%d",&m4);
	printf("Sub5 = ");
	scanf("%d",&m5);
	s=m1+m2+m3+m4+m5;
	s=s/5;
	if(s>=60)
		printf("\nDivision 1");
	if(s<=59 && s>=50)
		printf("\nDivision 2");
	if(s<=49 && s>=40)
		printf("\nDivision 3");
	if(s<40)
		printf("\nFail");

	getch();
}

