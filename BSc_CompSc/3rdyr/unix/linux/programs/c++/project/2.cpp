//Using friend class to add two numbers

#include<iostream>

using namespace std;

//First class
class Abc                                
{
//Begining of private scope
private:
	//Declaring variable
	int x;                             
//Begining of public scope
public:                     
	//Default constructor
	Abc()                              
	{
		Abc::x=0;
	}
	//Prototype of member function
	void set(int);
	//Declaring second class as friend of the first
	friend class Xyz;                 
	//Destructor
	~Abc()
	{                                 
	}
};

//Declaring function of the first class to assign value to member variable
void Abc::set(int i)                    
{                                  
	Abc::x=i;
}

//Second class which is the friend of the first
class Xyz                             
{

//Begining of private scope
private:
	int y,s;                         
//Begining of public scope
public:                            
	//Default constructor
	Xyz()									  
	{
		Xyz::y=0;                    
	}
	//Prototypes of member functions
	void sety(int);
	void sum(Abc);                  
	void show(Abc);
	//Destructor
	~Xyz()
	{
	}
};

//Declaring function of the second class to assign value to member variable
void Xyz::sety(int j)                
{                               
	Xyz::y=j;
}

//Declaring function to perform addition of the member variables
void Xyz::sum(Abc ob)                  
{
	s=ob.x+y;
}

//Displaying the result
void Xyz::show(Abc ob)
{
	cout<<ob.x<<" + "<<Xyz::y<<" = "<<Xyz::s<<"\n";
}

//Main function
int main()
{
	//Declaring variables and objects
	int m;
	Abc ob1;
	Xyz ob2;
	cout<<"Enter 1st number: ";
	cin>>m;
	//Passing the first value to the first function
	ob1.set(m);
	cout<<"Enter 2nd number: ";
	cin>>m;
	//Passing the second value to the second function
	ob2.sety(m);
	//Calling the sum function
	ob2.sum(ob1);
	//Displaying the result
	ob2.show(ob1);
	return 0;
}
