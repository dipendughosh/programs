//asci of smal chars
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void main()
{       int i;

	clrscr();
	for(i='a';i<='z';i++)
		printf("%c-%d\t",i,i);
	getch();
}

