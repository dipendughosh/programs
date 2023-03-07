#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	char string1[80],string2[80],string3[160];
	int len1,len2,i,x=0;
	cout<<"Enter 1st string ";
	gets(string1);
	cout<<"Enter 2nd string ";
	gets(string2);
	len1=strlen(string1);
	len2=strlen(string2);
	for(i=0;i<len1;i++)
	{	string3[x]=string1[i];
		++x;
	}
	string3[x]=' ';
	++x;
	for(i=0;i<len2;i++)
	{	string3[x]=string2[i];
		++x;
	}
	string3[x]='\0';
	puts(string3);
	getche();
}