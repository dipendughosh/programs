//dollar to rupee and vice versa

#include<iostream>

using namespace std;

template<class x>
class Rupee
{
};

template<class x>
class Dollar
{
};

template<>
class Dollar<float>;

template<>
class Rupee<float>
{
private:
//public:
	float r;
public:
	Rupee()
	{
		r=0.0;
	}
	Rupee(float x)
	{
		Rupee::r=x;
	}
	void set_r(float x)
	{
		Rupee::r=x;
	}
	~Rupee()
	{
	}
	friend void d_to_r(Rupee<float>&,Dollar<float>&);
	friend void r_to_d(Rupee<float>&,Dollar<float>&);
	friend void display(Rupee<float>,Dollar<float>);
/*	friend void d_to_r(Rupee&,Dollar&);
	friend void r_to_d(Rupee&,Dollar&);
	friend void display(Rupee,Dollar);*/
};

template<>
class Dollar<float>
{
private:
//public:
	float d;
public:
	Dollar()
	{
		d=0.0;
	}
	Dollar(float x)
	{
		Dollar::d=x;
	}
	void set_d(float x)
	{
		Dollar::d=x;
	}
	~Dollar()
	{
	}
	friend void d_to_r(Rupee<float>&,Dollar<float>&);
	friend void r_to_d(Rupee<float>&,Dollar<float>&);
	friend void display(Rupee<float>,Dollar<float>);
/*	friend void d_to_r(Rupee&,Dollar&);
	friend void r_to_d(Rupee&,Dollar&);
	friend void display(Rupee,Dollar);*/
};

void r_to_d(Rupee<float> &ob1,Dollar<float> &ob2)
{
	ob2.d=ob1.r/44;
}

void d_to_r(Rupee<float> &ob1,Dollar<float> &ob2)
{
	ob1.r=ob2.d*44;
}

void display(Rupee<float> ob1,Dollar<float> ob2)
{
	cout<<"Rupee = "<<ob1.r<<"\nDollar = "<<ob2.d<<"\n";
}
/*
void r_to_d(Rupee &ob1,Dollar &ob2)
{
	ob2.d=ob1.r/44;
}

void d_to_r(Rupee &ob1,Dollar &ob2)
{
	ob1.r=ob2.d*44;
}

void display(Rupee ob1,Dollar ob2)
{
	cout<<"Rupee = "<<ob1.r<<"\nDollar = "<<ob2.d<<"\n";
}*/
int main()
{
	float r,d;
	Rupee<float> ob1;
	Dollar<float> ob2;
/*	Rupee ob1;
	Dollar ob2;*/
	cout<<"Enter Rupee : - ";
	cin>>r;
	ob1.set_r(r);
	r_to_d(ob1,ob2);
	display(ob1,ob2);
	cout<<"Enter Dollor : - ";
	cin>>d;
	ob2.set_d(d);
	d_to_r(ob1,ob2);
	display(ob1,ob2);
	return 0;
}
