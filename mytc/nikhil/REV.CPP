#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{   clrscr();
	char s[51],p;
	gets(s);
	int len=strlen(s);
	int j=len-1;
	clrscr();
	puts(s);
	cout<<"\n";
	for(int a=0;a<len/2;a++)
	{	p=s[a];
		s[a]=s[j-a];
		s[j-a]=p;
	}
	cout<<endl;
	puts(s);
	getch();
}