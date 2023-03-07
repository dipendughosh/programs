//nikhil bothra TO n.bothra
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	void name(char nam[],int);
	char n[101];
	cout<<"Enter your name : ";  gets(n);
	int len=strlen(n);
	name(n,len);
	getch();
}

void name(char nam[],int p)
{   int a=p-1,c=0,s=0,sub=0,count=0;
	char sur[51],ini[5];
	while(nam[a]!=' ')
	{   c++;
		sur[s++]=nam[a];
		a--;
	};
/*cout<<"\nc= "<<c;getche();*/
	sur[s]='\0';
	ini[sub++]=nam[0];
	count++;
	for(int y=0;y<p;y++)
	{
	if(nam[y]==' ')
	{
	ini[sub++]=nam[y+1];
	count++;
	}
	}
	ini[sub-1]='\0';
	for(int h=0;h<count-1;h++) {cout<<ini[h];cout<<'.';}
	for(int x=c-1;x>=0;x--) cout<<sur[x];
}