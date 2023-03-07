//Largest number

#include<iostream>

using namespace std;

class Abc
{	
private:
	int a,b;
	static int i;
public:
	Abc()
	{	i++;
		cout<<"Constructing - "<<i<<endl;
		Abc::a=0;
		Abc::b=0;
	}
	void getdata(int x,int y)
	{	Abc::a=x;
		Abc::b=y;
	}
	void lrgest()
	{	if(Abc::a>Abc::b)
			cout<<"Greatest of the entered numbers is :- "<<Abc::a<<endl;
		else if(Abc::a<Abc::b)
			cout<<"Greatest of the entered numbers is :- "<<Abc::b<<endl;
		else
			cout<<"Both numbers equal"<<endl;
	}
	~Abc()
	{	cout<<"Destructing - "<<i<<endl;
		i--;
	}
};

int Abc::i;

int main()
{	Abc o1,o2,o3;
	int x,y;
	cout<<"Enter data for 1st object - "<<endl;
	cout<<"Enter 1st number : - ";
	cin>>x;
	cout<<"Enter 2nd number : - ";
	cin>>y;
	o1.getdata(x,y);
	cout<<"Enter data for 2nd object - "<<endl;
	cout<<"Enter 1st number : - ";
	cin>>x;
	cout<<"Enter 2nd number : - ";
	cin>>y;
	o2.getdata(x,y);
	cout<<"Enter data for 3rd object - "<<endl;
	cout<<"Enter 1st number : - ";
	cin>>x;
	cout<<"Enter 2nd number : - ";
	cin>>y;
	o3.getdata(x,y);
	o1.lrgest();
	o2.lrgest();
	o3.lrgest();
	return;
}




