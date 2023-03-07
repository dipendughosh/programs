#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{   clrscr();
		char string[80],reverse[80];
		int i,len;
		cout<<"Enter a string:";
		gets(string);
		len=strlen(string);
		for( i=len-1;i>=0;i--)
		{		cout<<string[i];

		}
		getche();
}