#include<iostream.h>
#include<conio.h>
#include<math.h>

class Account
{	protected:
	int accountNumber;
	double principal;
	public:
	Account()
	{
	}
	Account(int a,double p)
	{	accountNumber=a;
		principal=p;
	}
	void display()
	{	cout<<"\nAccount Number = "<<accountNumber<<"\nPrincipal = "<<principal;
	}
};

class Simple : public Account
{       private:
	int t;
	double r,si;
	public:
	Simple(int tt,double rr,int a,double p)
	{       Account::Account(a,p);
		t=tt;
		r=rr;
	}
	double interest()
	{       si=t*r*Account::principal/100;
		return si;
	}
	void display()
	{       cout<<"\n\tSimple Interest";
		Account::display();
		cout<<"\nRate = "<<r<<"\nTime = "<<t<<"\nInterest = "<<si;
	}
};

class Compound : public Account
{	private:
	int t;
	double r,ci;
	public:
	Compound(int tt,double rr,int a,double p)
	{       Account::Account(a,p);
		t=tt;
		r=rr;
	}
	double interest()
	{       ci=r/100;
		ci+=1;
		ci=pow(ci,t);
		ci*=Account::principal;
		ci-=Account::principal;
		return ci;
	}
	void display()
	{       cout<<"\n\n\tCompound Interest";
		Account::display();
		cout<<"\nRate = "<<r<<"\nTime = "<<t<<"\nInterest = "<<ci;
	}
};

void main()
{	clrscr();
	int t1,t2,a;
	double r1,r2,p;
	cout<<"\nEnter Account Number :- ";
	cin>>a;
	cout<<"Enter Principal :- ";
	cin>>p;
	cout<<"\nSimple Interest";
	cout<<"\nEnter Rate :- ";
	cin>>r1;
	cout<<"Enter Time :- ";
	cin>>t1;
	cout<<"\nCompound Interest";
	cout<<"\nEnter Rate :- ";
	cin>>r2;
	cout<<"Enter Time :- ";
	cin>>t2;
	Simple obj1(t1,r1,a,p);
	Compound obj2(t2,r2,a,p);
	obj1.interest();
	obj2.interest();
	obj1.display();
	obj2.display();
	getche();
}

































































































































