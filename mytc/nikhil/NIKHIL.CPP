#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<iomanip.h>

void main()
{   clrscr();
	cout<<"Enter a string ==> "; gets(s);
	cout<<"/n";
	len=strlen(s);
	if(len%2==0)
	{	mid=(len/2)+1;
		for(int i=len;i>=mid;i--)	s[i]=s[i-1];
		s[mid-1]='*';
		puts(s);
	}
	else puts(s);
