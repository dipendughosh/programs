#include<iostream.h>

//using namespace std;

class cmplx
{
	int rl;
	float img;
public:
	cmplx()
	{
		cmplx::rl=0;
		cmplx::img=0.0;
	}
	cmplx(int r,float i)
	{
		cmplx::rl=r;
		cmplx::img=i;
	}
	friend ostream &operator<<(ostream &,cmplx);
	friend istream &operator>>(istream &,cmplx &);
	~cmplx()
	{
	}
};

ostream &operator<<(ostream &out,cmplx obf)
{
	out<<obf.rl<<" + "<<obf.img<<"i";
	return out;
}

istream &operator>>(istream &in,cmplx &obf)
{
	cout<<"Enter real part:- ";
	in>>obf.rl;
	cout<<"Enter image part:- ";
	in>>obf.img;
	return in;
}

int main()
{
	cmplx ob;
	cout<<"Give data:-\n";
	cin>>ob;
	cout<<ob<<endl;
	return 0;
}