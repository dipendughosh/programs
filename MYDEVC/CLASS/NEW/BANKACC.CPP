#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

const int max=10;
class bank
{   private:
		char name[51];
		float bal;
		float interest;
		int accno;
	public:
		void cust_info()
		{   int n;
			cout<<"Enter the number of customers ";
			cin>>n;
			for (int i=0;i<n;i++)
			{	cout<<"\nEnter customer's name : "; gets(c[i].name);
				cout<<"Enter his account number : "; cin>>c[i].accno;
			}
		}
		bank();
		void show();
		void withdrawal();
		void deposit();
		friend int check(bank,int);
};

bank::bank()
{   cout<<"\nEnter your name ==> "; gets(name);
	cout<<"\nDefault balance is Rs. 500 ";
	interest=5.0;
	bal=500;
}

void bank::deposit()
{   float d;
	cout<<"\nEnter the amount to be deposited ==> ";
	cin>>d;
	bal+=d;
}

void bank::show()
{   cout<<"\t\t\tACCOUNT DETAILS\n\n";
	cout<<"Name : ";  puts(name);
	cout<<"\nAccount number : "<<accno;
	cout<<"\nExisting Balance : Rs. "<<bal;
	cout<<"\nRate of Interest : "<<interest<<"%";
}
void bank::withdrawal()
{   float w;
	cout<<"\nEnter the amount to be withdrawn  ==> ";
	cin>>w;
	bal-=w;
}

void check(bank a,int p)
{   int a;
	do
	{
	clrscr();
	cout<<"\nEnter the amount to be withdrawn  ==> ";
	cin>>p;
	if(p>a.bal)
	{	cout<<"\nCould not withdraw.Your said amount exceeds your account balance."
			<<"\n1.Withdraw all the balance and close the account..."
			<<"\n2.Continue transaction...\n"
			<<"Choose your option.\n";
		cin>>a;
		continue;
	}


	subscriber.withdrawal();

int main()
{   bank subscriber,c[max];

	char z;
	float xx;
	cout<<"Type 'w' for Withdrawal and 'd' for Deposits.\n";
	cin>>z;
	if (z == 'd')  subscriber.deposit();
	else
	{/*   do
		{
		cout<<"\nEnter the amount to be withdrawn  ==> ";
		cin>>xx;
		if(xx>bal) cout<<"

	subscriber.withdrawal();*/
	subscriber.show();
	cout<<endl;
	getch();
	return 0;
}