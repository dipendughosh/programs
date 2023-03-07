#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	float a=0,b=0,d=0,t=0,s=0;
	cout<<"\nEnter distance between stations->";
	cin>>d;
	cout<<"\nEnter speed of train [ A ]->";
	cin>>a;
	cout<<"\nEnter speed of train [ B ]->";
	cin>>b;
	s=a+b;
	s=s*1000/3600;
	d=d*1000;
	while(d>=s)
	{	t++;
		d=d-s;
	}
	a*=t;
	a=a*3600/1000;
	b*=t;
	b=b*3600/1000;




	cout<<"\nA->"<<a;
	cout<<"\nB->"<<b;


	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
