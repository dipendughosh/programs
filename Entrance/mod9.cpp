//modulo 9 without division by 9

#include<iostream>

using namespace std;

class mod9
{
private:
	int n1,n2;
	int add_digit();
public:
	mod9();
	void getdata();
	void display();
	~mod9();
};

mod9::mod9()
{
	n1=0;
	n2=0;
}

void mod9::getdata()
{
	cout<<"Enter number whose modulo is to be found: ";
	cin>>n1;
}

int mod9::add_digit()
{
	int a,s;
	a=n1;
	while(a>9)
	{
		s=0;
		while(a!=0)
		{
			s=s+a%10;
			a=a/10;
		}
		a=s;
	}
	if(a==9)
		return 0;
	else
		return s;
}

void mod9::display()
{
	n2=add_digit();
	if(n2==0)
		cout<<n1<<" Divisible by 9"<<endl;
	else
		cout<<"Modulo 9 of "<<n1<<" = "<<n2<<"\n";
}

mod9::~mod9()
{
}

int main()
{
	mod9 ob;
	ob.getdata();
	ob.display();
	return 0;
}