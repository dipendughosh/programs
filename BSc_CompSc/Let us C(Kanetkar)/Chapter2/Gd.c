#include<stdio.h>
#include<conio.h>

void main()
{       float h,c,t;
	clrscr();
	printf("Enter Value of Hardness :- ");
	scanf("%f",&h);
	printf("Enter Value of Carbon Content :- ");
	scanf("%f",&c);
	printf("Enter Value of Tensile Strength :- ");
	scanf("%f",&t);
	if(h>50 && c>0.7 && t>5600)
		printf("\nGrade is 10");
	else if(h>50 && c>.7)
		printf("\nGrade is 9");
	else if(c>.7 && t>5600)
		printf("\nGrade is 8");
	else if(h>50 && t>5600)
		printf("\nGrade is 7");
	else if(h>50 || c>.7 || t>5600)
		printf("\nGrade is 6");
	else
		printf("\nGrade is 5");
	getch();
}

