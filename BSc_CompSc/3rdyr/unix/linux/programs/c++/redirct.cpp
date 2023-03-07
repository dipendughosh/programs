#include <iostream>
using namespace std;
class comp
{
	int i,r;
public:
	comp(){}
	comp(int i,int r)
	{
		comp::i=i;
		comp::r=r;
	}
	friend ostream&operator<<(ostream&,comp);
	friend istream&operator>>(istream&,comp&);
};
ostream&operator<<(ostream&out,comp c)
{
	out<<c.r<<"+"<<c.i<<"i";
	return out;
}

istream&operator>>(istream&in,comp&c)
{
	cout<<"Give real:";
	in>>c.r;
	cout<<"Give img:";
	in>>c.i;
	return in;
}
main()
{
	comp a;
	cin>>a;
	cout<<"Given value:"<<a<<endl;
}
