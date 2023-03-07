//THANK YOU -INPUT
//YOU THANK-OUTPUT
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{   clrscr();
		char string1[80],string2[80];
		int i,l,k,j,x=0;
		cout<<"Enter a string:";
		gets(string1);
		l=strlen(string1);
		//string2[0]=' ';
		for(i=0;i<=l;i++)
			string2[i]=string1[i];
		k=l;
		for(i=l;i>=0;i--)
		{	if(string2[i]==' ' || i==0)
			{	for(j=i;j<=k;j++)
				{	string1[x]=string2[j];
					++x;
				}
				k=i;
			}
		 }
		 string1[x]='\0';
		 puts(string1);
		 getch();
}