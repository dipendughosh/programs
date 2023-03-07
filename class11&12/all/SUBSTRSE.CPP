#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	char string[80],substr[20];
	int len1,len2,i,j,flag=0,k;
	cout<<"ENTER A STRING : ";
	gets(string);
	cout<<"\nSUB STRING TO CHECK FOR :";
	gets(substr);
	len1=strlen(string);
	len2=strlen(substr);
	for(i=0;i<len1;i++)
	{       cout<<"\nI="<<i;
		if(string[i]==substr[0])
		{	for(j=i;j<len2;j++)
			{	if(string[j]==substr[j])
				{	flag=1;
				}
				else
				{	flag=0;
				}
			}
		}
		if(flag==1)
		{       k=i;
			break;
		}
	}
	cout<<"\nSUB STRING IS IN POSITION :"<<k;
	getche();
}