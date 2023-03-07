//get set with and without reference(function returning reference)

#include<iostream>

using namespace std;

class Abc
{
private:
	int i,j;
public:
	int get_i();
	void set_i(int);
	int& ref_get_set_j();
};

inline int Abc::get_i()
{	
	return Abc::i;
}

inline void Abc::set_i(int i)
{	
	Abc::i=i;
}

inline int& Abc::ref_get_set_j()
{
	return Abc::j;
}

int main()
{	
	int i,j;
	Abc o1,o2;
	cout<<"Enter value of i-";
	cin>>i;
	o1.set_i(i);
	cout<<"Value of i = "<<o1.get_i()<<endl;
	cout<<"Enter value of j-";
	cin>>j;
	o2.ref_get_set_j()=j;
	cout<<"Value of j = "<<o2.ref_get_set_j()<<endl;
	return;
}