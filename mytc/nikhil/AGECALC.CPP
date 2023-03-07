#include<conio.h>
#include<iostream.h>

void main()
{   clrscr();
	int a=14020;
	int d,m,y;
	y=(a/365);
	if(a%365>30)
	{	m=((a%365)/30);
		d=(a-(365*y)-(m*30));
	}
	else d=(a%365);
	cout<<"\n\nd: "<<d<<" m: "<<m<<" y: "<<y;
	getch();
}