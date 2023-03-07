#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{		clrscr();
		char string[80];
		int i,j,len,c=1;
		cout<<"ENTER A STRING :";
		gets(string);
		len=strlen(string);
		for(i=len-1,j=0; i>=0;i--,j++)
		{	if (string[j]==string[i])
				c=1;
			else
			{	c=0;
				break;
			}
		}
		if (c==1)
			cout<<"pallindrom";
		else
			cout<<"not pallindrom";

		getche();
}