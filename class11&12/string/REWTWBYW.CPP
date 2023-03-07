//THANK YOU-INPUT
//UOY KNAHT-OUTPUT
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	char string[80];
	int len,i,j;
	cout<<"ENTER A STRING  ";
	gets(string);
	len=strlen(string);
	for(i=len-1;i>=0;i--)
		cout<<string[i];
	getche();
}