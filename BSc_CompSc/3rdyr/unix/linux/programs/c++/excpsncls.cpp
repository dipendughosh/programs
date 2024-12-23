//if allocation failure give message

#include<iostream>
#include<string.h>

using namespace std;

class Ex
{
public:
	char msg[50];
	int no;
	Ex(char *st,int x)
	{
		strcpy(Ex::msg,st);
		Ex::no=x;
	}
	int get_no()
	{
		return Ex::no;
	}
	char get_msg()
	{
		return Ex::msg;
	}
	~Ex()
	{
	}
};

class vector
{
private:
	int *p,size;
public:
	vector()
	{
		p=NULL;
		size=0;
	}
	vector(int);
	vector operator+(vector);
	int &operator[](int);
	~vector()
	{
		delete p;
	}
};

vector::vector(int sz)
{
	try
	{
		vector::p=new int[sz];
	}
	catch(bad_alloc ba)
	{
		vector::p=NULL;
		vector::size=0;
		Ex e("Invalid size",sz);
		throw e;
	}
	vector::size=sz;
}

int &vector::operator[](int i)
{
	if(i>vector::size)
	{
		Ex e("UPPER BOUND ERROR",i);
		throw e;
	}
	if(i<vector::size)
	{
		Ex e("LOWER BOUND ERROR",i);
		throw e;
	}
	return p[i];
}
int main()
{
	int sz,i;
	cout<<"Enter size of vector:- ";
	cin>>sz;
//	vector ob1(sz);
	try
	{
		vector ob1(sz);
	}
	catch(Ex e)
	{
		cout<<e.get_no()<<":"<<e.msg()<<endl;
		return 0;
	}
	for(i=0;i<sz;i++)
	{
		try
		{
			cin>>ob1[i];
		}
		catch(Ex e)
		{
			cout<<e.get_no<<":"<<e.get_msg<<endl;
		}
	}
	for(i=0;i<sz;i++)
	{
		try
		{
			cout<<ob1[i]<<" ";
		}
		catch(Ex e)
		{
			cout<<e.get_no<<":"<<e.get_msg<<endl;
		}
	}
	return 0;
}




