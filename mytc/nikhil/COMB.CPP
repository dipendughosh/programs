#include<conio.h>
#include<iomanip.h>
#include<iostream.h>
int fact(int);
void main()
{   clrscr();
	int comb(int,int),j;
	for(int i=0;i<6;i++)
	{	for(j=1;j<5;j++)
			cout<<setw(2)<<" ";
		for(j=1;j<5;j++)
			cout<<setw(4)<<comb(i,j);
		cout<<endl;
	}
	getch();
}


int comb(int n,int r)
{   int c=1;
	for(int i=1;i<=r;i++,n--)
		c*=(n/i);
	return c;/*

	if(n<0 || r<0 || r>n)
	return 0;
	return ((fact(n)/fact(r))/fact(n-r));*/
}

int fact(int p)
{   int fact=1;
	while(p)
	  fact*=p--;
	return fact;
}