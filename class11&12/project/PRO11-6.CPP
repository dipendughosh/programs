//library function change case
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char str[20],a;
	int i;
	cout<<"Enter a string :";
	gets(str);
	cout<<"Enter a character :";
	cin>>a;
	for(i=0;str[i]!='\0';i++)
	{	if(str[i]==a || str[i]==(a-32))
		{	if(islower(str[i]))
			{	str[i]=toupper(str[i]);
				cout<<str[i];
			}
			else if(isupper(str[i]))
			{	str[i]=tolower(str[i]);
				cout<<str[i];
			}
		}
		else
			cout<<str[i];
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}