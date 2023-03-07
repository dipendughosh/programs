//Float function.overload all the operators.

#include<iostream>

using namespace std;

class Float
{
private:
	float a;
public:
	Float();
	Float(float);
	Float operator+(Float &);
	Float operator-(Float &);
	Float operator*(Float &);
	Float operator/(Float &);
	void show();
	~Float();
};

Float::Float()
{
	Float::a=0;
}

Float::Float(float x)
{
	Float::a=x;
}

Float Float::operator+(Float &ob)
{
	Float temp;
	temp.a=Float::a+ob.a;
	return temp;
}

Float Float::operator-(Float &ob)
{
	Float temp;
	temp.a=Float::a-ob.a;
	return temp;
}

Float Float::operator*(Float &ob)
{
	Float temp;
	temp.a=Float::a*ob.a;
	return temp;
}

Float Float::operator/(Float &ob)
{
	Float temp;
	temp.a=Float::a/ob.a;
	return temp;
}

void Float::show()
{
	cout<<"Output - "<<Float::a<<endl;
}

Float::~Float()
{
}

int main()
{
	float x;
	cout<<"Enter value of 1st object - ";
	cin>>x;
	Float ob1(x);
	ob1.show();
	cout<<"Enter value of 2nd object - ";
	cin>>x;
	Float ob2(x);
	ob2.show();
	Float ob3;
	cout<<"+ "<<endl;
	ob3=ob1+ob2;
	ob3.show();
	cout<<"- "<<endl;
	ob3=ob1-ob2;
	ob3.show();
	cout<<"* "<<endl;
	ob3=ob1*ob2;
	ob3.show();
	cout<<"/ "<<endl;
	ob3=ob1/ob2;
	ob3.show();
	return 0;
}
