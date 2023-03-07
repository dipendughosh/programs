//calcutta is our city. input:cut.  output:calxxxta is our city.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	char s[51],w[11];
	int check(int,int,char[],char[]);
	void print(char[],int,int);
	int c=0;
	cout<<"Enter a string  : ";  gets(s);
	cout<<"\nEnter a word : ";  gets(w);
	clrscr();
	puts(s);
	cout<<endl;
	int len=strlen(w);
	for(int i=0;s[i]!='\0';i++)
	{   if(s[i]==' ') i++;
		if(s[i]==w[0])
		{	c=check(len,i,s,w);
			if(c==1) print(s,len,i);
//			else break;
		}
	}
	getche();
}


int check(int p,int q,char a[],char b[])
{   int y=0,flag=1,x=0;
	while(x<p)
	{	if(a[q++]==b[y++])  flag=1;
		else {flag=0;break;}
		x++;
	};
	return flag;
}


void print(char a[],int p,int q)
{	int x=0,y=0;
	for(;a[x]!='\0';x++)
	{	if(x!=q++) cout<<a[x];
		else
		{	while(y<p)
			{	cout<<'x';
				y++;
			};
		}
		x+=p;
	}
}