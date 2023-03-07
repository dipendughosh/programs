//Armstrong/Fibonacci/Prime/Exit : On choice (Menu)
#include<iostream.h>
#include<conio.h>
void main()
{	int ch;
	void arm(),fibo(),prime();
	do
	{	clrscr();
		cout<<"\n\tMENU";
		cout<<"\n\t====\n\n";
		cout<<"1. Armstrong Numbers\n";
		cout<<"2. Fibonacci Numbers\n";
		cout<<"3. Prime Numbers\n";
		cout<<"0. Exit\n";
		cout<<"\n	Please enter your choice : ";
		cin>>ch;
		switch(ch)
		{	case 1: arm(); break;
			case 2: fibo(); break;
			case 3: prime(); break;
		};
	} while(ch>0);
	//getche();
}
void arm(){cout<<"\nRunning arm()";getche();}
/*{	for(int i = 1; i <= 100; i++)
	{   int n = 0;
		while(i)
		{	int num;
			i / 10;
			}*/
void fibo(){cout<<"\nRunning Fibo";getche();}
void prime(){cout<<"\nRunning Prime";getche();}



