//To check if a entered string is a pallindrome or not
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{	char string[80];
	int i,j=0,len=0,c=1;
	clrscr();
	printf("Enter a string :- ");
	gets(string);
	len=strlen(string);
	for(i=len-1,j=0;i>=len/2;i--,j++)
		if (string[j]!=string[i])
			c=0;
	if (c==1)
		printf("The entered string is a pallindrom");
	else
		printf("The entered string is not a pallindrom");
	getch();
}