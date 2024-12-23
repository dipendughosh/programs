//Addition of two huge integer

#include<iostream.h>
#include<string.h>

//using namespace std;

class HugeInteger
{
private:
	char arr[20];
	int n;
public:
	HugeInteger()
	{
		int i;
		n=20;
		for(i=0;i<HugeInteger::n;i++)
			arr[i]='0';
			
	}
	friend istream &operator>>(istream &,HugeInteger &);
	friend ostream &operator<<(ostream &,HugeInteger);
	friend HugeInteger operator+(HugeInteger,HugeInteger);
	~HugeInteger()
	{
	}
};

istream &operator>>(istream &in,HugeInteger &ob)
{
	int len,i,j;
	char temp[20];
	in>>temp;
	len=strlen(temp);
	for(i=ob.n,j=len;i>=0 && j>=0;i--,j--)
	{
		ob.arr[i]=temp[j];
	}
	for(;i>=0;i--)
	{
		ob.arr[i]='0';
	}
	return in;
}

ostream &operator<<(ostream &out,HugeInteger ob)
{
	int i;
	for(i=0;ob.arr[i]=='0' && i<ob.n;i++)
		if(i==ob.n)
			out<<'0';
	for(;i<ob.n;i++)
		out<<ob.arr[i];
	return out;
}

HugeInteger operator+(HugeInteger ob1,HugeInteger ob2)
{
	int i,c=0,a,b,s;
	HugeInteger temp;
	for(i=temp.n-1;i>=0;i--)
	{
		a=ob1.arr[i]-48;
		b=ob2.arr[i]-48;
		s=a+b+c;
		c=s/10;
		s=s%10;
		temp.arr[i]=s+48;
	}
	return temp;
}

int main()
{
	int n,i;
	HugeInteger ob[5],sum;
	cout<<"Enter number of numbers:- ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>ob[i];
	for(i=0;i<n;i++)
		sum=sum+ob[i];
	cout<<"\n"<<sum<<"\n";
	return 0;
}
			
