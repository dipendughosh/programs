//Example of no pointer but reference(call by reference)

#include<iostream>

using namespace std;

void swap(int &a,int &b)
{	int t;
	t=a;
	a=b;
	b=t;
}


int main()
{	int x,y;
	cout<<"Enter 1st number:- ";
	cin>>x;
	cout<<"Enter 2nd number:- ";
	cin>>y;
	cout<<"Before swaping-"<<endl;
	cout<<"1st number :- "<<x<<endl;
	cout<<"2nd number :- "<<y<<endl;
	swap(x,y);
	cout<<"After swaping-"<<endl;
	cout<<"1st number :- "<<x<<endl;
	cout<<"2nd number :- "<<y<<endl;
	return 0;
}
