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
	cout<<"Enter number of words you want to delete : ";
	cin>>num;
	delstr(string,num);
	cout<<"\n\aPRESS ANY KEY TO CONTINUE ............\a";
	getche();
}
void delstr(char stringhold[80],int n)
{	int len,i,x;
	len=strlen(stringhold);
	x=0;
	for(i=len-1;i>=0;i--)
	{	if(stringhold[i]==' ')
			x++;
		if(x==n)
		{	stringhold[i]='\0';
			break;
		}
	}
	x=0;
	while(stringhold[x]!='\0')
	{	cout<<stringhold[x];
		x++;
	}
}