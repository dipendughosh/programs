#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	float meter,bill=1,unit=100,paisa=40,t,m;
	float convert(float);
	cout<<"Enter your unit ";
	cin>>meter;
	t = meter;
	do
	{   if(meter<unit)
		{
			m = meter;
		}
		else
		{
			m = unit;
		}
		bill=(m*paisa);
		meter-=unit;
		paisa+=10;
		unit+=100;
	}while(meter>0);
	bill+=5000;
	cout<<"total bill for "<<t<<" units is "<<convert(bill);
	getche();
}
float convert(float b)
{
	total = b/100;
	return b;
}




