//shrthand notations

#include<iostream>

using namespace std;

class Abc
{
private:
	int x,y;
public:
	Abc();
	Abc(int,int);
	~Abc();
	void show();
	Abc operator+=(Abc);
	Abc operator+=(int);
};

Abc::Abc()
{
	x=0;
	y=0;
}

Abc::Abc(int x,int y)
{
	Abc::x=x;
	Abc::y=y;
}

Abc::~Abc()
{
}


Abc Abc::operator+=(Abc o1)
{
	Abc::x=Abc::x+o1.x;
	Abc::y=Abc::y+o1.y;
}

Abc Abc::operator+=(int a)
{
	Abc::x=Abc::x+a;
	Abc::y=Abc::y+a;
}

void Abc::show()
{
	cout<<"x = "<<Abc::x<<" y = "<<Abc::y<<endl;
}
int main()
{
	Abc o1(2,3),o2(4,5),o3;
	o1.show();
	o2.show();
	o1+=o2;
	o1.show();
	o1+=10;
	o1.show();
	return 0;
}
