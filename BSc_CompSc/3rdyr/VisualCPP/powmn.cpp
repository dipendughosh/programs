//M^N

#include<iostream>
#include<cmath>

using namespace std;

class Abc
{	
private:
	int m,n,e;
public:
	Abc();
	void getdata(int,int);
	void showdata();
	~Abc();
};

Abc::Abc()
{	
	cout<<"Constructing"<<endl;
	m=0;
	n=0;
	e=0;
}

void Abc::getdata(int m,int n)
{
	Abc::m=m;
	Abc::n=n;
	Abc::e=pow(m,n);
}

void Abc::showdata()
{	
	cout<<Abc::m<<" ^ "<<Abc::n<<" = "<<Abc::e<<endl;
}

Abc::~Abc()
{	
	cout<<"Destructing"<<endl;
}

int main()
{	
	Abc obj;
	int m,n;
	cout<<"Program to calculate m^n"<<endl;
	cout<<"Enter m :- ";
	cin>>m;
	cout<<"Enter n :- ";
	cin>>n;
	obj.getdata(m,n);
	obj.showdata();
	return;
}
