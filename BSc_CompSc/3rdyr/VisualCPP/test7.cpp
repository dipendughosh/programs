//OPERATOR OVERLOADING USING Friend FUNCTIONS

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
	friend Abc operator+(Abc,Abc);
	friend Abc operator+(Abc,int);
	friend Abc operator+(int,Abc); 
	friend Abc operator-(Abc,Abc);
	friend Abc operator*(Abc,Abc);
	friend Abc operator/(Abc,Abc);
	friend Abc operator++(Abc &);
	friend Abc operator++(Abc &,int);
	friend Abc operator--(Abc &);
	friend Abc operator--(Abc &,int);
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
Abc operator+(Abc ob1,Abc ob2)
{
	Abc temp;
	temp.x=ob1.x+ob2.x;
	temp.y=ob1.y+ob2.y;
	return temp;
}

Abc operator+(Abc ob1,int x)
{
	Abc temp;
	temp.x=ob1.x+x;
	temp.y=ob1.y+x;
	return temp;
}

Abc operator+(int x,Abc ob1)
{
	Abc temp;
	temp.x=ob1.x+x;
	temp.y=ob1.y+x;
	return temp;
}

//Subtraction
Abc operator-(Abc ob1,Abc ob2)
{
	Abc temp;
	temp.x=ob2.x-ob1.x;
	temp.y=ob2.y-ob1.y;
	return temp;
}

//Multiplication
Abc operator*(Abc ob1,Abc ob2)
{
	Abc temp;
	temp.x=ob1.x*ob2.x;
	temp.y=ob1.y*ob2.y;
	return temp;
}

//Division
Abc operator/(Abc ob1,Abc ob2)
{
	Abc temp;
	temp.x=ob1.x/ob2.x;
	temp.y=ob1.y/ob2.y;
	return temp;
}

Abc operator++(Abc &ob1)
{	
	Abc temp;
	temp.x=++ob1.x;
	temp.y=++ob1.y;
	return temp;
}

Abc operator++(Abc &ob1,int x)
{	
	Abc temp;
	temp.x=ob1.x++;
	temp.y=ob1.y++;
	return temp;
}

Abc operator--(Abc &ob1)
{
	Abc temp;
	temp.x=--ob1.x;
	temp.y=--ob1.y;
	return temp;
}

Abc operator--(Abc &ob1,int x)
{	
	Abc temp;
	temp.x=ob1.x--;
	temp.y=ob1.y--;
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
	Abc o4(4);
	o4.show(4);
	o4=o4+10;
	o4.show(4);
	o4=10+o4;
	o4.show(4);
}


