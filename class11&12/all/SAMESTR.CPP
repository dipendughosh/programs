#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	char s1[80],s2[80];
	int len1,len2,i,f;
	cout<<"ENTER 1st STRING ";
	gets(s1);
	cout<<"\nENTER 2nd STRING ";
	gets(s2);
	len1=strlen(s1);
	len2=strlen(s2);
	if(len1==len2)
	{	for(i=0;i<len1;i++)
		{	if(s1[i]==s2[i])
			{	f=1;
			}
			else
			{	f=0;
				break;
			}
		}
	}
	if(f==1)
	{	cout<<"\nYES";
	}
	else
	{	cout<<"\nNO";
	}
	getche();
}