//6
//string(done)
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

struct string
{	char str[180];
};

string operator +(string,string);
void main()
{	clrscr();
	string a,b,c;
	cout<<"\nEnter String 1->\n";
	gets(a.str);
	cout<<"\nEnter String 2->\n";
	gets(b.str);
	c=a+b;
	cout<<"\nCONCATENATED STRING-->>>>>>------------->\n";
	cout<<"\n"<<c.str;
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

string operator +(string a,string b)
{	string c;
	int len1,len2,n=0,i,j;
	len1=strlen(a.str);
	len2=strlen(b.str);
	for(i=0;i<len1;i++)
	{	c.str[n]=a.str[i];
		n++;
	}
	c.str[n]=' ';
	n++;
	for(i=0;i<len2;i++)
	{	c.str[n]=b.str[i];
		n++;
	}
	c.str[n]='\0';
	return c;
}






























































































































