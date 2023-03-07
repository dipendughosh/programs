#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{   clrscr();
	void ltor(char,int);
	void ttob(char,int);
	char name[50];
	long i;
	int col = 32;
	cout<<"Enter your name : "; gets(name);
	int len = strlen(name);
	col+=len;
	for(i = len-1; i >= 0; i--, col--)
	{   if(name[i] == ' ') continue;
		ltor(name[i],col);
		ttob(name[i],col);
		cout<<(char) 7;
	}
	getch();
}

void ltor(char c, int cl)
{   long w;
	for(int x = 1; x < cl; x++)
	{
		for(w = 0; w < 1000000; w++);
		gotoxy(x,8); cout<<c;
		for(w = 0; w < 1000000; w++);
		gotoxy(x,8); cout<<" ";
	}
}

void ttob(char c, int cl)
{	long w;
	for(int x = 8; x <= 20; x++)
	{
		for(w = 0; w < 3000000; w++);
		gotoxy(cl,x); cout<<c;
		for(w = 0; w < 3000000; w++);
		gotoxy(cl,x); cout<<" ";
	}
	gotoxy(cl,x); cout<<c;
}



