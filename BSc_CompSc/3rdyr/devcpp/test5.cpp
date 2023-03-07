//Class Global and local

#include<iostream>
#include<cconio>

using namespace std;

class Abc
{
private:
	int a;
public:
	Abc(int);
	~Abc();
};

Abc o1(1),o2(2),o3(3);

Abc::Abc(int x)
{
	Abc::a=x;
	cout<<"Constructing - "<<Abc::a<<endl;
}

Abc::~Abc()
{
	cout<<"Destructing - "<<Abc::a<<endl;
}

int main()
{
	Abc o4(4),o5(5),o6(6);
	cout<<"In main"<<endl;
	return 0;
	getche();
}