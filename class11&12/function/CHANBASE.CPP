#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	void changebase(char [],int,int);
	char string[80];
	int len,i=0,a=0,num;
	cout<<"ENTER A NUMBER IN ANY BASE :";
	gets(string);
	cout<<"ENTER A NUMBER BETWEEN 1 - 16 :";
	cin>>num;
	len=strlen(string);
	for(i=0;i<len;i++)
	{	a=string[i];
		if((a-48)>=0 || (a-48)<=9)
		{	if((a-48)>=num)
			{	cout<<"\nINCORRECT ";
				exit(0);
			}
		}
		else if((a-55)>=10 || (a-55)<16)
		{	if((a-55)>=num)
			{       cout<<"\nINCORRECT ";
				exit(0);
			}
		}
		else if((a-87)>=10 || (a-87)<16)
		{	if((a-87)>=num)
			{       cout<<"\nINCORRECT ";
				exit(0);
			}
		}
	}
	changebase(string,num,len);
	cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
void changebase(char stringhold[80],int n,int l)
{       int x=0,s=0,c=0,i=0,a=0,b=0;
	for(i=(l-1);i>=0;i--)
	{	a=stringhold[i];
		if(a>=48 && a<=58)
		{	b=a-48;
			c=(pow(n,x))*b;
			s=s+c;
		}
		if(a>=65 && a<=70)
		{       b=a-55;
			c=(pow(n,x))*b;
			s=s+c;
		}
		if(a>=97 && a<=101)
		{       b=a-87;
			c=(pow(n,x))*b;
			s=s+c;
		}
		x++;
	}
	cout<<"THE NUMBER IS "<<s;
}