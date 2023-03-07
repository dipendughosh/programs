#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	//finding corect base of not
	clrscr();
	char no[25];
	int base,p,x;
	cout<<"\nENTER NUMBER WITHIN A LIMIT OF 1-16th BASE..........";
	gets(no);
	cout<<"\nENTER BASE..........................................";cin>>base;
	if(base<=10)
	{
		for(int i=0;i<strlen(no);i++)
		{
			p=(int)(no[i]);
			p=p-48;
			if(p>=base)
			      x=1;
		}
	}
	else
	{
		for(int i=0;i<strlen(no);i++)
		{
			p=(int)(no[i]);
			p=p-55;
			if(p>=base)
			      x=1;
		}

	}
	if(x==1)
	{
		cout<<"\nINCORECT BASE.......";
	}
	else
	{
		cout<<"\nCORRECT BASE........";
	}
	getch();
}
