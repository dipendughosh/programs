//Different types of constructor(fuction over loading)

#include<iostream>
#include<cstring>

using namespace std;

class Abc
{	
private:
	int a,b;
	float c,d;
	char e[80],f[80];
public:
	Abc();
	Abc(int,int);
	Abc(float,float);
	Abc(char [],char []);
	~Abc();
};

//Default constructor
inline Abc::Abc()
{	
	cout<<"Constructor"<<endl;
}

//Function overloading
//Parameterized constructors
inline Abc::Abc(int a,int b)
{	
	cout<<"Constructor Int"<<endl;
	int c;
	Abc::a=a;
	Abc::b=b;
	c=Abc::a+Abc::b;
	cout<<Abc::a<<" + "<<Abc::b<<" = "<<c<<endl;
}

inline Abc::Abc(float c,float d)
{	
	cout<<"Constructor Float"<<endl;
	float a;
	Abc::c=c;
	Abc::d=d;
	a=Abc::c+Abc::d;
	cout<<Abc::c<<" + "<<Abc::d<<" = "<<a<<endl;
}

inline Abc::Abc(char e[],char f[])
{	
	cout<<"Constructor String"<<endl;
	int i,j,len;
	char b[160];
	len=strlen(e);
	j=0;
	for(i=0;i<=len;i++)
	{	Abc::e[i]=e[i];
		b[j++]=Abc::e[i];
	}
	j--;
	len=strlen(f);
	for(i=0;i<=len;i++)
	{	Abc::f[i]=f[i];
		b[j++]=Abc::f[i];
	}
	puts(Abc::e);
	puts(Abc::f);
	puts(b);
}

//Destructor
inline Abc::~Abc()
{	
	cout<<"Destructing"<<endl;
}

int main()
{	
	Abc o1(10,12);
	float a=12.50,b=25.79;
	Abc o2(a,b);
	Abc o3("Hello","World");
	return 0;
}
