#include<stdio.h>
#include<conio.h>

void main()
{       char a;
	clrscr();
	printf("Enter a character ");
	scanf("%c",&a);
	if(a>=65 && a<=90)
		printf("\nIt is a Capital Letter");
	else if(a>=97 && a<=122)
		printf("\nIt is a Small Letter");
	else if(a>=48 && a<=57)
		printf("\nIt is a Digit");
	else if(a>=0 && a<=47 || a>=58 && a<=64 || a>=91 && a<=96 || a>=123 && a<=12)
		printf("\nIt is a Special Character");
	getch();
}

