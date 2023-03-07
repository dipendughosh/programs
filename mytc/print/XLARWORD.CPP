#include<conio.h>
//2 find how many types of notes in a certain amt.
#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{	clrscr();
	int den[9]={1000,500,100,50,20,10,5,2,1},r,t=0;
	int denc[9],plus=0,i;
	int den_count(int,int);
	cout<<"\nEnter the amount : "; cin>>r;
	for(;t<9;t++)
	{	i=den_count(den[t],r);
		r=r-(i*den[t]);
		denc[t]=i;
		i=0;
	}
	for(int s=0;s<9;s++)
	{
		cout<<endl<<"Rupees "<<den[s]<<". "<<"Notes : "<<denc[s];
		plus+=denc[s];
	}
	cout<<endl<<"Minimum notes : "<<plus;
	getche();
}

int den_count(int p,int q)
{   if(q>p)
	{	int a=q/p;
		return a;
	}
	else return 0;
}