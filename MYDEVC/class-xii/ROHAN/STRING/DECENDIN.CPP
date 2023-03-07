//ARRANGING THE STRING IN DESENDING ORDER OF WORD LENGTH.
//DATE:	19/03/2005
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	char a[500];
	int c[500],b[500];
	int s=0,p=0,q=1,temp;
	void prn(char[],int,int);
	void swap(int[],int[],int,int);
	cout<<"\nEnter string...";gets(a);
	b[0]=0;
	for(int i=0;i<strlen(a);i++)
	{      	if(a[i]!=' '&& a[i]!='.')
		{
			s++;
		}
		else
		{
			c[p++]=s;
			s=0;
			b[q++]=i+1;

		}

	}
	for(i=0;i<p-1;i++)
	{
		for(int j=i+1;j<p;j++)
		{
			if(c[j]>=c[i])
			{
				swap(c,b,i,j);

			}
		}
	}
	for(i=0;i<p;i++)
	{
		prn(a,c[i],b[i]);
	}
	cout<<".";
	getch();
}
void prn(char x[],int len,int start)
{
	int p=0;
	for(int i=1;i<=len;i++)
	{
		cout<<x[start+p];
		p++;
	}
	cout<<" ";
}
void swap(int c[],int b[],int i,int j)
{
	int temp;
	temp=c[i];
	c[i]=c[j];
	c[j]=temp;
	temp=b[i];
	b[i]=b[j];
	b[j]=temp;
}