#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

class stringop
{	char txt[100];
	int len;
	public:
	stringop();
	void readstring();
	char caseconvert(int);
	void circulardacode();
}

stringop::stringop()
{
}

void stringop::readstring()
{	cout<<"\nEnter the string:\n";
	gets(txt);
	len=strlen(txt);
}

char stringop::caseconvert(int a)
{       int i;
	if(a>=65 && a<=90)
		a=a+32;
	if(a>=97 && a<=122)
		a=a-32;

	return (char)a;
}

void stringop::circulardacode()
{       int i,a;
	for(i=0;i<len;i++)
	{	a=txt[i];
		txt[i]=caseconvert(a);
		if(txt[i]=='z')
			txt[i]='a';
		if(txt[i]=='Z')
			txt[i]='A';
		else
			txt[i]=(txt[i])+1;
	}
	puts(txt);
}
void main()
{	clrscr();
	stringop s;
	s.readstring();
	s.circulardacode();
	getche();
}
