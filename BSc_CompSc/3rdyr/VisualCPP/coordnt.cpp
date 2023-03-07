

#include<iostream>
#include<cmath>



using namespace std;



class coordinate

{
private:
	struct point
	{	
		double x,y;
	};
	point p1,p2;
	double deg,len;
public:
	coordinate();
	void calculate(double,double,double,double);
	void show();
	~coordinate();
};

coordinate::coordinate()
{
	coordinate::p1.x=0.0;
	coordinate::p2.y=0.0;
	coordinate::deg=0.0;
	coordinate::len=0.0;
}

void coordinate::calculate(double x,double y,double deg,double len)
{
	coordinate::p1.x=x;
	coordinate::p1.y=y;
	coordinate::deg=deg;
	coordinate::len=len;
	deg=coordinate::deg*22/7/180;
	coordinate::p2.x=coordinate::len*cos(deg)+coordinate::p1.x;
	coordinate::p2.y=coordinate::len*sin(deg)+coordinate::p1.y;
}

void coordinate::show()
{
	cout<<"The point from ("<<coordinate::p1.x<<","
	    <<coordinate::p1.y<<") at a distance of "
	    <<coordinate::len<<" and at an angle of "
	    <<coordinate::deg<<" is ("<<coordinate::p2.x
	    <<","<<coordinate::p2.y<<")"<<endl;
}

coordinate::~coordinate()
{
}

int main()
{
	coordinate o1;
	double x,y,deg,len;
	cout<<"Enter x coordinate :- ";
	cin>>x;
	cout<<"Enter y coordinate :- ";
	cin>>y;	
	cout<<"Enter angle at which the other point lies :-";
	cin>>deg;
	cout<<"Enter the distance at which the other point lies :-";
	cin>>len;
	o1.calculate(x,y,deg,len);
	o1.show();
	return 0;
}

