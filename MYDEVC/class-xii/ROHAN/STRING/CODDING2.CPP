#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	char a[500],c[500];
	int p;
	cout<<"\nEnter string--->";gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		p=(int)a[i];
		if(p>=65 && p<=90)
			c[i]=(char)(p+32);
		else
		{
			if(p>=97 && p<=122)
				c[i]=(char)(p-32);

			else
				c[i]=(char)p;
		}
	}
	c[i]='\0';
	cout<<c;
	for(i=0;i<strlen(c);i++)
	{




	getch();
}
