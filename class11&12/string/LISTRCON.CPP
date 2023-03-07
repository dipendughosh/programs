#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	char string1[80],string2[80];
	cout<<"\nEnter a string :";
	gets(string1);
	cout<<"\nEnter another string :";
	gets(string2);
	strcat(string1,string2);
	puts(string1);
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}