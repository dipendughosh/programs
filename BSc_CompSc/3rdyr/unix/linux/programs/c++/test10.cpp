//Inheritance
//comments are not possible,illegal use
#include<iostream>

using namespace std;

class base
{
private:
	int z;
	int a;
protected:
	int b;
public:
	base(int z)
	{
		base::z=z;
		cout<<"Base Constructor "<<base::z<<endl;
	}
	void get(int a,int b)
	{
		cout<<"Base Get"<<endl;
		base::a=a;
		base::b=b;
	}
	void show()
	{
		cout<<"Base Show"<<endl;
		cout<<"a = "<<base::a<<" b = "<<base::b<<endl;
	}
	~base()
	{
		cout<<"Base Destructor "<<base::z<<endl;
	}
};

class derived1:public base
{
private:
	int y;
	int c;
protected:
	int d;
public:
	derived1(int y):base(y)
	{
		derived1::y=y;
		cout<<"Derived1 Constructor "<<derived1::y<<endl;
	}
	void get(int c,int d)
	{
		cout<<"Derived1 Get"<<endl;
		derived1::c=c;
		derived1::d=d;
	}
	void show()
	{
		cout<<"Derived1 Show"<<endl;
		cout<<"c = "<<derived1::c<<" d = "<<derived1::d<<endl;
	}
	~derived1()
	{
		cout<<"Derived1 Destructor "<<derived1::y<<endl;
	}
};

class derived2:protected base
{
private:
	int x;
	int e;
protected:
	int f;
public:
	derived2(int x):base(x)
	{
		derived2::x=x;
		cout<<"Derived2 Constructor "<<derived2::x<<endl;
	}
	void get(int e,int f)
	{
		cout<<"Derived2 Get"<<endl;
		derived2::e=e;
		derived2::f=f;
	}
	void show()
	{
		cout<<"Derived2 Show"<<endl;
		cout<<"e = "<<derived2::e<<" f = "<<derived2::f<<endl;
	}
	~derived2()
	{
		cout<<"Derived2 Destructor "<<derived2::x<<endl;
	}
};

class derived3:private base
{
private:
	int w;
	int g;
protected:
	int h;
public:
	derived3(int w):base(w)
	{
		derived3::w=w;
		cout<<"Derived3 Constructor "<<derived3::w<<endl;
	}
	void get(int g,int h)
	{
		cout<<"Derived3 Get"<<endl;
		derived3::g=g;
		derived3::h=h;
	}
	void show()
	{
		cout<<"Derived3 Show"<<endl;
		cout<<"g = "<<derived3::g<<" h = "<<derived3::h<<endl;
	}
	~derived3()
	{
		cout<<"Derived3 Destructor "<<derived3::w<<endl;
	}
};

int main()
{
	int a,b;
	cout<<"Public Derived 1 Class"<<endl;
	derived1 o1(1);
	cout<<"Enter a :- ";
	cin>>a;
	cout<<"Enter b :- ";
	cin>>b;
	o1.base::get(a,b);
	int c,d;
	cout<<"Enter c :- ";
	cin>>c;
	cout<<"Enter d :- ";
	cin>>d;
	o1.derived1::get(c,d);
	o1.base::show();
	o1.derived1::show();
/*
	cout<<"Protected Derived 2 Class"<<endl;
	derived2 o2(2);*/
	/*cout<<"Enter a :- ";
	cin>>a;
	cout<<"Enter b :- ";
	cin>>b;*/
	//o2.base::get(a,b);
	/*int e,f;
	cout<<"Enter e :- ";
	cin>>e;
	cout<<"Enter f :- ";
	cin>>f;
	o2.derived2::get(e,f);
	//o2.base::show();
	o2.derived2::show();

	cout<<"Private Derived 3 Class"<<endl;
	derived2 o3(3);*/
	/*cout<<"Enter a :- ";
	cin>>a;
	cout<<"Enter b :- ";
	cin>>b;*/
	//o2.base::get(a,b);
	/*int g,h;
	cout<<"Enter g :- ";
	cin>>g;
	cout<<"Enter h :- ";
	cin>>h;
	o3.derived3::get(g,h);
	//o2.base::show();
	o3.derived3::show();*/

	return 0;
}