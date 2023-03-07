//1-U+(1/2!*U^2)-(1/3!*U^3).....N
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	int m=-1,n,u;
	float sum,term,fcalc,pcalc;
	int factorial(int);
	int val_u(int,int);
	cout<<"Number of times(n) : ";  cin>>n;
	cout<<"\nValue of constant(u) : ";  cin>>u;
	cout<<"\n";
	for(int i=1;i<n;i++)
	{   fcalc=factorial(i);
		pcalc=val_u(u,i);
		term=m/fcalc*pcalc;
		sum+=term;
		m*=-1;
/*		if (term==u) cout<<m<<u;
		else
		{	if(m==1) cout<<"(1/"<<i++<<"!*"<<u<<"^"<<i++<<')';
			else cout<<"-(1/"<<i++<<"!*"<<u<<"^"<<i++<<')';
		} */
	}
	sum++;
	cout<<"\n\nSum = "<<sum;
	getch();
}

int factorial(int p)
{   int fact=1;
	while(p)  fact*=p--;
	return fact;
}

int val_u(int p,int q)
{	int a=1,prod=1;
	for(;a<=q;a++) prod*=p;
	return prod;
}