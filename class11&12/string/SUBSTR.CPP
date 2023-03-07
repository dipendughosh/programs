#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int check(char [],char []);
	char str[80],sub[80],hold[80];
	int len,i,j=0,x=0;
	cout<<"\nEnter a string : ";
	gets(str);
	cout<<"\nEnter substring to search for : ";
	gets(sub);
	len=strlen(str);
	for(i=0;i<len;i++)
	{	if(str[i]!=' ' || str[i]!='\0')
		{	hold[x]=str[i];
			x++;
		}
		if(str[i]==' ' || str[i]=='\0')
		{	j=check(hold,sub);
			x=0;
		}
		if(j==1)
		{	cout<<"\nIn position "<<(i-(strlen(sub))+1);
		}
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
int check(char a[80],char b[80])
{	int len1,len2,i,j;
	len1=strlen(a);
	len2=strlen(b);
	if(len1==len2)
	{	for(i=0;i<len1;i++)
		{	if(a[i]==b[i])
			{	j=1;
			}
			else
			{	j=0;
				break;
			}
		}
	}
	if(len1!=len2)
	{	j=0;
	}
	return j;
}