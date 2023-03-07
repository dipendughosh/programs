//Complex number using dynamic allocations

#include<iostream>

using namespace std;

//Class Complex
class comp
{	
//Begining of private scope
private:
	//Structure of a complex number:Real part-r,Imaginary part-i
	struct data
	{	
		float r,i;
	};
	//Pointer to point to one complex number
	data *no;
//Begining of public scope
public:
	//Default constructor to dynamically allocate space for a complex number
	comp()
	{	
		//Allocate space for a complex number
		try
		{	
			comp::no=new data;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation Failure";
			return;
		}
		//Initializing allocated space
		comp::no->r=0;
		comp::no->i=0;
	}
	//Prototypes of overloaded,friend and normal functions
	comp operator+(comp ob);
	comp operator-(comp ob);
	friend ostream&operator<<(ostream&,comp);
	friend istream&operator>>(istream&,comp&);
	//Destructor
	~comp()
	{
	}
};

//Overloaded function for '+' operator to add 2 complex numbers
comp comp::operator+(comp ob)
{
	//Declaring temporary object of the class comp to hold the result
	comp temp;
	temp.no->r=comp::no->r+ob.no->r;
	temp.no->i=comp::no->i+ob.no->i;
	//Returning the result
	return temp;
}

//Overloaded function for '-' operator to subtract 2 complex numbers
comp comp::operator-(comp ob)
{
	//Declaring temporary object of the class comp to hold the result
	comp temp;
	temp.no->r=comp::no->r-ob.no->r;
	temp.no->i=comp::no->i-ob.no->i;
	//Returning the result
	return temp;
}

//Overloaded function for '<<' operator to output the data in correct format
ostream &operator<<(ostream &out,comp ob)
{	
	//Formating the output
	if(ob.no->i<0)
		out<<ob.no->r<<ob.no->i<<"i";
	else
		out<<ob.no->r<<" + "<<ob.no->i<<"i";
	return out;
}

//Overloaded function for '>>' operator to input the data in correct format
istream &operator>>(istream &in,comp &ob)
{
	//Formatting the input
	cout<<"Give real part:- ";
	in>>ob.no->r;
	cout<<"Give imaginary part:- ";
	in>>ob.no->i;
	return in;
}

//Main Function
int main()
{	
	//Declaring objects of the comp class
	comp ob1,ob2,ob3,ob4;
	int c;
	char x;
	while(1)
	{
		cout<<"\nMENU";
		cout<<"\n1.Add Complex Numbers";
		cout<<"\n2.Subtract Complex Numbers";
		cout<<"\n\nEnter choice:- ";
		cin>>c;
		//Enter the first number
		cout<<"Enter First number --\n";
		cin>>ob1;
		//Enter the first number
		cout<<"Enter Second number --\n";
		cin>>ob2;
		switch(c)
		{
			case 1:	//Adding the 2 complex numbers
				ob3=ob1+ob2;
				//Displaying the result after addition
				cout<<"( "<<ob1<<" ) + ( "<<ob2<<" ) = ( "<<ob3<<" )\n";
				break;
			case 2:	//Subtracting the 2 complex numbers
				ob4=ob1-ob2;	
				//Displaying the result after subtraction
				cout<<"( "<<ob1<<" ) - ( "<<ob2<<" ) = ( "<<ob4<<" )\n";
				break;
			default:
				cout<<"Wrong Input\n";
				break;
		}
		cout<<"Do you want to contunie?(y/Y) ";
		cin>>x;
		if(x != 'y' && x != 'Y')
			break;
	}
	return 0;
}

