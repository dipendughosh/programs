#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	void func();
	func();
	getche();
}

void func()
{	char n[25];
	cout<<"\nYour name please :\n";
	cin.getline(n,25);
	int len=strlen(n);
	clrscr();
	puts(n);
	cout<<"\n";
	cout.write("Hello",7).write(n,len);
}