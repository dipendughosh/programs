//OPERATOR OVERLOADING USING MEMBER FUNCTIONS(basic)

#include<iostream>

using namespace std;

class Abc
{
private:
	int x,y;
public:
	Abc();
	Abc(int);
	void show(int);
	Abc operator+(Abc);
	Abc operator-(Abc);
	Abc operator*(Abc);
	Abc operator/(Abc);
	Abc operator++();
	Abc operator++(int);
	Abc operator--();
	Abc operator--(int);
	~Abc();
};

Abc::Abc()
{
	Abc::x=0;
	Abc::y=0;
}

Abc::Abc(int c)
{
	cout<<"Data for object "<<c<<endl;
	cout<<"Enter 1st number :- ";
	cin>>x;
	cout<<"Enter 2nd number :- ";
	cin>>y;
}

void Abc::show(int c)
{
	cout<<"Data for object "<<c<<" are "<<Abc::x<<" "<<Abc::y<<endl;
}

Abc::~Abc()
{
}

//Addition
Abc Abc::operator+(Abc ob2)
{
	Abc temp;
	temp.x=Abc::x+ob2.x;
	temp.y=Abc::y+ob2.y;
	return temp;
}

//Subtraction
Abc Abc::operator-(Abc ob2)
{
	Abc temp;
	temp.x=Abc::x-ob2.x;
	temp.y=Abc::y-ob2.y;
	return temp;
}

//Multiplication
Abc Abc::operator*(Abc ob2)
{
	Abc temp;
	temp.x=Abc::x*ob2.x;
	temp.y=Abc::y*ob2.y;
	return temp;
}

//Division
Abc Abc::operator/(Abc ob2)
{
	Abc temp;
	temp.x=Abc::x/ob2.x;
	temp.y=Abc::y/ob2.y;
	return temp;
}

Abc Abc::operator++()
{	
	Abc temp;
	temp.x=++(Abc::x);
	temp.y=++(Abc::y);
	return temp;
}

Abc Abc::operator++(int x)
{	
	Abc temp;
	temp.x=(Abc::x)++;
	temp.y=(Abc::y)++;
	return temp;
}

Abc Abc::operator--()
{
	Abc temp;
	temp.x=--(Abc::x);
	temp.y=--(Abc::y);
	return temp;
}

Abc Abc::operator--(int x)
{	
	Abc temp;
	temp.x=(Abc::x)--;
	temp.y=(Abc::y)--;
	return temp;
}

int main()
{
	Abc o1(1),o2(2),o3;
	o1.show(1);
	o3=++o1;
	o3.show(3);
	o1.show(1);
	o2.show(2);
	o3=o2++;
	o3.show(3);
	o2.show(2);
	o1.show(1);
	o3=--o1;
	o3.show(3);
	o1.show(1);
	o2.show(2);
	o3=o2--;
	o3.show(3);
	o2.show(2);
	o3=o1+o2;
	cout<<"Addition"<<endl;
	o3.show(3);
	o3=o1-o2;
	cout<<"Subtraction"<<endl;
	o3.show(3);
	o3=o1*o2;
	cout<<"Multiplication"<<endl;
	o3.show(3);
	o3=o1/o2;
	cout<<"Division"<<endl;
	o3.show(3);
}


