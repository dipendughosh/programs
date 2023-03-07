#include<iostream>


using namespace std;

class Abc
{     
public:
	int a;
};

main()
{   Abc b;
    Abc c;
    cout<<"Enter number : ";
    cin>>b.a;
    cout<<"Number = "<<b.a<<endl;
    cout<<"Enter number : ";
    cin>>c.a;
    cout<<"Number = "<<c.a<<endl;
}