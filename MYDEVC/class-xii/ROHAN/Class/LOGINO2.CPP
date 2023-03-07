#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class login
{
	int hr,min;
	public:
		login()
		{
			cout<<"\nEnter login time...-->(hr/min)";cin>>hr>>min;
		}
		long convert()
		{
			return((hr*60)+(min));
		}
};
class logout
{
	int hr,min;
	float rate;
	long total;
	login time;
	public:
		logout()
		{
			cout<<"\nEnter logout time....-->(hr/min)";cin>>hr>>min;
			rate=.50;
		}
		void convert()
		{
			total=(hr*60)+(min);
			if(total<time.convert())
			total+=(24*60);
		}
		void calcrate()
		{
			cout<<"\nBill is ..........Rs--> "<<((total-time.convert())*rate);
		}
};
void main()
{
	clrscr();
	logout obj1;
	obj1.convert();
	obj1.calcrate();
	getch();
}



