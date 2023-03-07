#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
void main()
{	clrscr();
	void search(char [],char);
	char string[80],lett;
	cout<<"ENTER A SENTENCE ";
	gets(string);
	cout<<"\nENTER LETTER TO SEARCH ";
	cin>>lett;
	search(string,lett);
	getche();
}
void search(char str[],char let)
{       int len,i,x=0,a[100];
	len=strlen(str);
	for(i=0;i<len;i++)
	{	if(str[i]==let||str[i]-32==let)
		{	a[x]=i;
			x++;
		}
	}
	cout<<"\nNUMBER OF TIMES "<<let<<" OCCURS = "<<x<<"\n";
	for(i=0;i<x;i++)
		cout<<a[i]<<"\t";
}