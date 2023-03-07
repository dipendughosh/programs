//na dekhe huge int

#include<iostream.h>
#include<string.h>
//using namespace std;

class hugeint
{
private:
	char arr[20];
	int n;
public:
	hugeint()
	{
		int i;
		n=20;
		for(i=0;i<n;i++)
			arr[i]='0';
	}
	friend ostream &operator<<(ostream &,hugeint);
	friend istream &operator>>(istream &,hugeint &);
	friend hugeint operator+(hugeint,hugeint);
	~hugeint()
	{
	}
};

istream &operator>>(istream &in,hugeint &ob)
{
	int j,i,len;
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

ostream &operator<<(ostream &out,hugeint ob)
{
	int i;
	for(i=0;i<ob.n && ob.arr[i]=='0';i++)
	{
		if(i==ob.n)
			out<<'0';
	}
	for(;i<ob.n;i++)
	{
		out<<ob.arr[i];
	}
	return out;
}

hugeint operator+(hugeint ob1,hugeint ob2)
{
	hugeint temp;
	int i,a,b,c=0,s;
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
	hugeint x[10],s;
	int n,i;
	cout<<"Enter number of numbers:- ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"x["<<i<<"] = ";
		cin>>x[i];
	}
	for(i=0;i<n;i++)
	{
		s=s+x[i];
	}
	cout<<"Sum = "<<s<<endl;
	return 0;
}
