#include <iostream>

#include <new>


using namespace std;


class Ex

{
	int no;

	string msg;

public:

	Ex(int,string);

	int get_no();

	string get_msg();

};


Ex::Ex(int no,string msg)

{
	Ex::no=no;

	Ex::msg=msg;

}


int Ex::get_no()

{
	return Ex::no;

}

string Ex::get_msg()

{
	return Ex::msg;

}


class Arr

{
	int *ar;

	int size;

public:
	Arr(int);

	int& operator[](int);

	int get_size();

	~Arr();

};

Arr::Arr(int size)

{
	try

	{
	
		Arr::ar=new int[size];

		Arr::size=size;

	}

	catch(bad_alloc e)

	{
	
		Arr::ar=NULL;

		Arr::size=0;

		throw new Ex(10,"Invalid size.");

	}

}


int Arr::get_size()

{
	
	return Arr::size;

}


Arr::~Arr()

{
	if(Arr::size)

		delete ar;

}


int& Arr::operator[](int i)

{
	if(i<0)

		throw new Ex(12,"Lower bound exception.");

	if(i>=Arr::size)

		throw new Ex(11,"Upper bound exception.");

	return Arr::ar[i];

}


main()

{
	
	int n;

	cout<<"Give size:";

	cin>>n;

	try
	{

		Arr a(n);

		cout<<"Give elements:-"<<endl;

		for(int i=0;i<a.get_size();i++)

			cin>>a[i];

		cout<<"Given elements:-"<<endl;

		for(int i=0;i<=a.get_size();i++)

			cout<<a[i]<<endl;

	}
	
	catch(Ex*e)

	{
	
		cerr<<"Err no."<<e->get_no()<<':'<<e->get_msg()<<endl;

	}

}
