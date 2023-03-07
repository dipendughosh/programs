//Copy constructor

#include<iostream>
#include<cstring>

using namespace std;

class Abc
{
private:
	char name[40];
	int rl,a,b,c,tot;
	float avg;
public:
	Abc();
	Abc(char [],int,int,int,int);
	Abc(const Abc &);
	void set(char [],int,int,int,int);
	void disp();
	~Abc();
};

//default constructor
inline Abc::Abc()
{
	cout<<"Default constructor"<<endl;
}

//parameterized constructor
inline Abc::Abc(char name[],int rl,int a,int b,int c)
{	
	strcpy(Abc::name,name);
	Abc::rl=rl;
	Abc::a=a;
	Abc::b=b;
	Abc::c=c;
	Abc::tot=a+b+c;
	Abc::avg=Abc::tot/3;
	cout<<"Const: "<<Abc::rl<<endl;
}

inline void Abc::set(char name[],int rl,int a,int b,int c)
{	
	strcpy(Abc::name,name);
	Abc::rl=rl;
	Abc::a=a;
	Abc::b=b;
	Abc::c=c;
	Abc::tot=a+b+c;
	Abc::avg=Abc::tot/3;
	cout<<"Set: "<<Abc::rl<<endl;
}

//Copy constructor
inline Abc::Abc(const Abc &o)
{	
	strcpy(Abc::name,"high");
	Abc::rl=o.rl;
	Abc::a=o.a;
	Abc::b=o.b;
	Abc::c=o.c;
	Abc::tot=o.a+o.b+o.c;
	Abc::avg=Abc::tot/3;
	cout<<"Copy Const: "<<Abc::rl<<endl;
}

inline void Abc::disp()
{	
	cout<<"Name- "<<name<<endl
		<<"Roll No.- "<<rl<<endl
		<<"Mrk 1- "<<a<<endl
		<<"Mrk 2- "<<b<<endl
		<<"Mrk 3- "<<c<<endl
		<<"Tot- "<<tot<<endl
		<<"Avg- "<<avg<<endl;
}

//Destructor
inline Abc::~Abc()
{
	cout<<"Dest"<<Abc::rl<<endl;
}

Abc fnc(Abc x)
{
	cout<<"Fnc "<<endl;
	return x;
}

int main()
{	
	char name[80];
	int a,b,c,rl;
	cout<<"Obj 1"<<endl;
	cout<<"Enter name - ";
	gets(name);
	cout<<"Enter roll number- ";
	cin>>rl;
	cout<<"Enter mrks 1 - ";
	cin>>a;
	cout<<"Enter mrks 2 - ";
	cin>>b;
	cout<<"Enter mrks 3 - ";
	cin>>c;
	Abc o1(name,rl,a,b,c);
	o1.disp();
	cout<<"----------------------------------"<<endl<<"Obj 2"<<endl;
	fflush(stdin);
	Abc o2;
	cout<<"Enter name - ";
	gets(name);
	cout<<"Enter roll number- ";
	cin>>rl;
	cout<<"Enter mrks 1 - ";
	cin>>a;
	cout<<"Enter mrks 2 - ";
	cin>>b;
	cout<<"Enter mrks 3 - ";
	cin>>c;
	o2.set(name,rl,a,b,c);
	o2.disp();
	cout<<"----------------------------------"<<endl<<"Obj 3"<<endl;
	Abc o3=o2;
	o3.disp();
	cout<<"----------------------------------"<<endl<<"Obj 4"<<endl;
	Abc o4;
	o4=o3;
	o4.disp();
	cout<<"----------------------------------"<<endl<<"Obj 5"<<endl;
	Abc o5;
	o5=fnc(o1);
	o5.disp();
	return;
}