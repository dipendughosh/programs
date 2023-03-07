//Handling boundary exception of array
#include<iostream>

using namespace std;

//Template class
template<class x>
class Abc
{
//Begining of private scope
private:
	x a[10];
	int m;
//Begining of public scope
public:
	//Default constructor
	Abc()
	{
	}
	//Parameterized constructor
	Abc(int s)
	{
		int j;
		Abc::m=s;
		for(j=0;j<Abc::m;j++)
			Abc::a[j]=0;
	}
	//Subscript opertator overloaded
	int &operator[](int);
	//Destructor
	~Abc()
	{
	}
};

//Function to overload the subscript operator
template<class x>
x &Abc<x>::operator[](int j)
{
	if(j < 0 || j > m)
	{
		cout<<"Boundary exception";
		exit(1);
	}
	return a[j];
}

//Main function
int main()
{
	int sz,i,n;
	cout<<"Enter the size: ";
	cin>>sz;
	char ch;
	//User's choice to use ineger or float or string array
	cout<<"\n'i' for integer!";
	cout<<"\n'f' for float!";
	cout<<"\n'c' for character!";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	if(ch=='i')
	{
		Abc<int> ob(sz);
		cout<<"\nEnter elements of the array:- ";
		for(i=0;i<sz;i++)
			cin>>ob[i];
		cout<<"\nEnter position whose element is to be retrived:- ";
		cin>>n;
		cout<<ob[n];
		
	}
	else if(ch=='f')
	{
		Abc<int> ob(sz);
		cout<<"\nEnter elements of the array:- ";
		for(i=0;i<sz;i++)
			cin>>ob[i];
		cout<<"\nEnter position whose element is to be retrived:- ";
		cin>>n;
		cout<<ob[n];
	}
	else if(ch=='c')
	{
		Abc<int> ob(sz);
		cout<<"\nEnter elements of the array:- ";
		for(i=0;i<sz;i++)
			cin>>ob[i];
		cout<<"\nEnter position whose element is to be retrived:- ";
		cin>>n;
		cout<<ob[n];
	}
	else
		cout<<"\nERROR in choice!\n";
	return 0;	
}







