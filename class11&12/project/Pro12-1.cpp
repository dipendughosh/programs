/*1
Convert any hexadecimal number or octal number(done)
to decimal & binary equivqalents*/
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	void base(char [80],int);
	int check(char [80],int);
	char str[80];
	int len,x=0,n,c;
	cout<<"\n1.Hexadecimal to Decimal & Binary ";
	cout<<"\n2.Octal to Decimal & Binary ";
	cout<<"\nEnter choice ";
	cin>>c;
	switch(c)
	{	case 1:
			cout<<"\nEnter the number ";
			gets(str);
			n=16;
		break;
		case 2:
			cout<<"\nEnter the number";
			gets(str);
			n=8;
		break;
		default:
			cout<<"\nWrong choice";
	}
	x=check(str,n);
	if(x==1)
	{	base(str,n);
	}
	if(x==0)
	{	cout<<"\nWrong input  ";
		getch();
		exit(0);
	}
	getche();
}

int check(char stringhold[80],int end)
{       int len,i=0,a=0,b=0,x=0;
	len=strlen(stringhold);
	for(i=0;i<len;i++)
	{	a=stringhold[i];
		if(a>='0' && a<='9')
		{	b=a-48;
			if(b<end)
			{	x=1;
			}
			else
			{       x=0;
				break;
			}
		}
		else if(a>='A' && a<='F')
		{       b=a-55;
			if(b<end)
			{	x=1;
			}
			else
			{       x=0;
				break;
			}
		}
		else if(a>='a' && a<='f')
		{       b=a-87;
			if(b<end)
			{	x=1;
			}
			else
			{	x=0;
				break;
			}
		}
		else
		{	x=0;
			break;
		}
	}
	return x;
}

void base(char stringhold[80],int end)
{       void binary(int );
	int a,b,x=0,lenl,i,str[80];
	double s=0,c;
	lenl=strlen(stringhold);
	for(i=(lenl-1);i>=0;i--)
	{	a=stringhold[i];
		if(a>=48 && a<=58)
		{	b=a-48;
			c=(pow(end,x))*b;
			s=s+c;
			str[x]=s+48;
		}
		if(a>=65 && a<=70)
		{       b=a-55;
			c=(pow(end,x))*b;
			s=s+c;
			str[x]=s+48;
		}
		if(a>=97 && a<=101)
		{       b=a-87;
			c=(pow(end,x))*b;
			s=s+c;
			str[x]=s+48;
		}
		x++;
	}
	cout<<"\n";
	puts(stringhold);
	cout<<"converted to decimal from base "<<end<<" is "<<s;
	binary (s);
}

void binary(int x)
{	int r,y=0;
	long sum[80];
	cout<<"\nThe binary num is ";
	while (x!=0)
	{	r=x%2;
		x=x/2;
		sum[y]=r;
		y++;
	}
	for(int i=y-1;i>=0;i--)
		cout<<sum[i];
}