// check whether a given string is palindrome or not.

#include<stdio.h>
#include<conio.h>
#define max 100

void main()
{
char str[max];
int l,i;
clrscr();
printf("\n\tEnter a string : ");
gets(str);
l=strlen(str);
for(i=0;i<l;i++)
	{
	if(str[i]!=str[l-1-i])
		{
		printf("\n\tNot a Palindrome.");
		getch();
		exit();
		}	//end of if
	}	//end of for
printf("\n\tPalindrome.");
getch();
}