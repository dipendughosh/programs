//Printing a string n number of times

#include<iostream>

using namespace std;

class Abc
{
private:
	int n;
public:
	Abc();
	void getdata(int);
	void print();
	~Abc();
};

Abc::Abc()
{
	cout<<"Constructing"<<endl;
	n=0;
}

void Abc::getdata(int num)
{	
	Abc::n=num;
}

void Abc::print()
{	
	int i;
	for(i=0;i<Abc::n;i++)
		puts("Hello World");
}

Abc::~Abc()
{
	cout<<"Destructing"<<endl;
}

int main()
{	Abc o1;
	int num;
	cout<<"Enter number :- ";
	cin>>num;
	o1.getdata(num);
	o1.print();
	return;
}




