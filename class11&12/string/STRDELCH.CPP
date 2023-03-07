#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	void delstr(char [],int);
	char string[80];
	int num;
	cout<<"Enter a string : ";
	gets(string);
	cout<<"Enter number of character you want to delete : ";
	cin>>num;
	delstr(string,num);
	cout<<"\n\aPRESS ANY KEY TO CONTINUE ............\a";
	getche();
}
void delstr(char stringhold[80],int n)
{	int m,len;
	len=strlen(stringhold);
	m=len-n;
	stringhold[m]='\0';
	puts(stringhold);
}