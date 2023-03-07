#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	double p=0.0,no;
	cout<<"\nENTER NUMBER ........";cin>>no;
	for(double i=0.0;i<(no);i+=0.00001)
	{	p=i*i;
		if(p>no)
		{
			cout<<"\nSQUARE ROOT IS....."<<i-0.00001<<"----"<<(i-0.00001)*(i-0.00001);
			break;
		}
	}
	getch();
}
