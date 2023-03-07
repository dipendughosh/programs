#include<conio.h>
#include<iostream.h>

int a=0;
void main()
{   clrscr();
	void fibo(int,int);
	fibo(0,1);
	getch();
}

void fibo(int p,int q)
{   a++;
	cout<<p<<"\t"<<q<<"\n";
	int temp=(p+q);
	p=q;
	q=temp;
	while(a<=10) fibo(p,q);
}