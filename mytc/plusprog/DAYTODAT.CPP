//day number from date
#include<iostream.h>
#include<conio.h>
void main()
{   int num,date,daynum = 5,i = 1;
	clrscr();
	do
	{	cout<<"Enter a number ( Less than 31 ) : "; cin>>num;
	} while(num > 30);
	date = num + 1;
	while(i++ <= date)
	{	daynum++;
		if(daynum > 7) daynum = 1;
		cout<<"\ndate "<<i<<"\tdaynum "<<daynum;
	}
			//daynum ? 1 , 7 : --daynum;
	if(daynum = 1) daynum = 7;
	else --daynum;

	cout<<"\nThe day number will be : "<< daynum;
	getche();
}



