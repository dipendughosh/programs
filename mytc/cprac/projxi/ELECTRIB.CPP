#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int meter,bill=0,unit=100,paisa=40,t,m;
	int convert(int);
	cout<<"Enter your unit ";
	cin>>meter;
	t = meter;
	int s=meter;
	if(meter>300)
	{
		meter=300;
		s-=300;
	}
	do
	{   if(meter<unit)
		{
			m = meter;
		}
		else
		{
			m = unit;
		}
		bill+=(m*paisa);
		paisa+=10;
		unit+=200;
	}while(meter>0);
	s*=60;
	if(s>0)
	{
		bill+=s;
		bill+=5000;
	}
	bill+=5000;
	cout<<bill<<"\n";
	int bl = bill/100;
	cout<<"total bill for "<<t<<" units is Rs "<<bl<<"."<<convert(bill)<<"paisa";
	getche();
}
int convert(int b)
{
	int total = b%100;
	return total;
}




