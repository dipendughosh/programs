#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char string[80];
	int i,len;
	cout<<"\nEnter a string :";
	gets(string);
	len=strlen(string);
	for(i=0;i<len;i++)
	{	if(islower(string[i]))
		{	string[i]=toupper(string[i]);
			cout<<string[i];
		}
		else//if(isupper(string[i]))
		{	string[i]=tolower(string[i]);
			cout<<string[i];
		}
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}