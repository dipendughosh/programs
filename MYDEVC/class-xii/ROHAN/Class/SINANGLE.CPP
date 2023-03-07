# include<iostream.h>  //provided x is 0<=x<=90
# include<conio.h>
# include<math.h>
class trig
{
	double x;
	public:
		void getdata()
		{
			cout<<"\n Enter angle....";cin>>x;
			x=(3.1415926535897932384626433832795/180.0)*x;
			cout<<"\n X in radians is -->"<<x<<endl;
		}
		long factorial(int);
		double sin(double);
		void print();
};
void trig::print()
{
	cout<<" Answer-->  "<<(sin(x)/100000);
}
long trig::factorial(int xx)
{
	long p=1;
	for(int i=1;i<=xx;i++)
	{
		p*=i;
	}
	return p;
}
double trig::sin(double angle)
{
	double s=0.;
	int h;
	long temp;
	int sign=1;
	for(int i=1;i<35;i+=2)
	{
		   s=s+((pow(angle,i)/factorial(i))*sign);
		   sign=sign*-1;
	}
	s=s*(pow(10,6));
	temp=(long)s;h=temp%10;temp=temp/10;
	if(h>4)	temp++;
	return temp;
}
void main()
{
	clrscr();
	trig obj;
	obj.getdata();
	obj.print();
	getch();
}
