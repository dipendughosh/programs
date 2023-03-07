#include<conio.h>
#include<stdlib.h>
#include<iostream.h>

class bank
{		int accno;
		float bal;
	public:
		bank()
		{	accno=101;
			bal=0.;
		}
		void read()
		{  //	cout<<"Enter account number : ";  cin>>accno;
			cout<<"Enter opening balance : ";  cin>>bal;
		}
		int refer()
		{   return bal;
		}

};

class savings:public bank
{		float p,in,amt,dep,wit;
		char ch;
	public:
		savings()
		{  // bank::bank();
			bank::read();
			p=bank::refer();
			cout<<"The rate of interest in savings account is 10% \n";
		}
		void deposit()
		{	cout<<"Deposit amount ? ";  cin>>dep;
			p+=dep;
		}
		void withdrawal()
		{   cout<<"Withdrawal amount ? ";  cin>>wit;
			if (wit>p)
			{	cout<<"\nAMOUNT EXCEEDS BALANCE!";
				exit(0);
			}
			else p-=wit;
		}
		void calc()
		{	in=p*.1;
			amt=p+in;
		}
		void show()
		{	cout<<"\nPRINCIPAL = Rs. "<<p
				<<"\nINTEREST = Rs. "<<in
				<<"\nAMOUNT = Rs. "<<amt;
		}
}x;

class current:public bank
{		float p,dep,wit,in,amt;
		char ch;
	public:
		current()
		{ //	bank::bank();
			bank::read();
			p=bank::refer();
			cout<<"The rate of interest in current account is 5% \n";
		}
		void deposit()
		{	cout<<"Deposit amount ? ";  cin>>dep;
			p+=dep;
		}
		void withdrawal()
		{   cout<<"Withdrawal amount ? ";  cin>>wit;
			if (wit>p)
			{	cout<<"\nAMOUNT EXCEEDS BALANCE!";
				cout<<"\nYOUR SURPLUS AMOUNT IS TAKEN AS OVERDRAFT @ 3% p.a.\n";
				cout<<"\nTHE INTEREST TO BE DEPOSITED IS Rs."<<(wit-p)*.03;
			}
			else p-=wit;
		}
		void calc()
		{	in=p*.1;
			amt=p+in;
		}
		void show()
		{	cout<<"\nPRINCIPAL = Rs. "<<p
				<<"\nINTEREST = Rs. "<<in
				<<"\nAMOUNT = Rs. "<<amt;
		}
}y;


void main()
{   clrscr();
	char c1,c2;
	cout<<"WANT TO ACCESS CURRENT OR SAVINGS ? ";  cin>>c1;
	cout<<"WANT TO DEPOSIT OR WITHDRAW ? ";  cin>>c2;
	switch(c1)
	{	case 'c':{	if (c2=='d')  y.deposit();
					else if (c2=='w')  y.withdrawal();
					y.calc();
					y.show();
					break;
				 }
		case 's':{	if (c2=='d')  x.deposit();
					else if (c2=='w')  x.withdrawal();
					x.calc();
					x.show();
					break;
				 }
		default:cout<<"WRONG entry!!!";

	}
	getch();
}
