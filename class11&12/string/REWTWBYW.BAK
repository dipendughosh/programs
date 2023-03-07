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
	char string[80],reverse[80];
	int len,i,j,x=0,k;
	cout<<"ENTER A STRING  ";
	gets(string);
	len=strlen(string);
	k=0;
	for(i=0;i<=len;i++)
	{	if(string[i]==' '||string[i]=='\0')
		{	for(j=i;j>=k;j--)
			{	reverse[x]=string[j];
				++x;
			}
			k=i;
		}
	}
	//reverse[x]='\0';
	puts(reverse);
	getche();
}