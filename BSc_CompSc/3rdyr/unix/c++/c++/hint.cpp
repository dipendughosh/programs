//To add huge integer number

#include <iostream>

using namespace std;

//Class to store the huge numbers
class HugeInt
{
//Begining of private scope
private:
	//Declaring class variables
	static const int SIZE=20;
	char buf[SIZE];
//Begining of public scope
public:
	//Default constructor
	HugeInt()
	{
		for(int i=0;i<HugeInt::SIZE;i++)
			buf[i]='0';
	}
	//Prototypes of the friend functions
	friend istream& operator>>(istream&,HugeInt&);
	friend ostream& operator<<(ostream&,HugeInt);
	friend HugeInt operator+(HugeInt,HugeInt);
	//Destructor
	~HugeInt()
	{
	}
};

//Operator '>>' overload function
istream& operator>>(istream&in,HugeInt&ob)
{
	string tmp;
	in>>tmp;
	int i,j;
	for(i=ob.SIZE-1,j=tmp.length()-1;
			i>=0 && j>=0;i--,j--)
		ob.buf[i]=tmp[j];
	for(;i>=0;i--)
		ob.buf[i]='0';
	return in;
}

//Operator '<<' overload function
ostream& operator<<(ostream&out,HugeInt ob)
{
	int i;
	for(i=0;ob.buf[i]=='0' && i<ob.SIZE;i++);
	if(i==ob.SIZE)out<<'0';
	for(;i<ob.SIZE;i++)
		out<<ob.buf[i];
	return out;
}

//Operator '+' overload function
HugeInt operator+(HugeInt ob1,HugeInt ob2)
{
	HugeInt tmp;
	for(int i=HugeInt::SIZE-1,cy=0;i>=0;i--)
	{
		int a=ob1.buf[i]-'0';
		int b=ob2.buf[i]-'0';
		int c=a+b+cy;
		cy=c/10;
		tmp.buf[i]=c%10+'0';
	}
	return tmp;
}

//Function main
int main()
{
	//Declaring objects of the class
	HugeInt x[40],s;
	int i,n;
	cout<<"Enter number of numbers :- ";
	cin>>n;
	//Entering values
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i<<" number : - ";
		cin>>x[i];
	}
	//Adding the values entered
	for(i=0;i<n;i++)
		s=s+x[i];
	cout<<"Sum = "<<s<<"\n";
	return 0;
}
