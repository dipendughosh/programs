#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{	//clrscr();
	void check(char [],int);
	char n[15];
	int b;
	cout<<"Enter a number : ";  gets(n);
	cout<<"Enter the base : ";  cin>>b;
	check(n,b);
}

void check(char num[],int base)
{	int i=0,j=0,flag=0;
	char nos[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	for(;num[i]!='\0';i++)
	{   for(;j<base;j++)
		{	if(num[i]==nos[j])  flag=1;
			else flag=0;
		}
		if(flag==0)
		{	cout<<"\n\nERROR";
			getch();
			exit(0);
		}

	}
	cout<<"\n\nSUCCESS.";
	getch();
}
