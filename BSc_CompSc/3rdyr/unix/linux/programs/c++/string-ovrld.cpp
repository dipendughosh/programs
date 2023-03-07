//string overload ==,!=,+,<<,>>
#include<iostream>
#include<string.h>

using namespace std;

class str
{
private:
	char st[80];
	int len;
public:
	str()
	{
		st[0]=NULL;
		len=0;
	}
	str(char *s)
	{
		strcpy(str::st,s);
		len=strlen(str::st);
	}
	str operator+(str);
	int operator==(str);
	int operator!=(str);
	friend ostream&operator<<(ostream&,str);
	friend istream&operator>>(istream&,str&);
	~str()
	{
	}
};

str str::operator+(str ob)
{
	str temp;
	strcpy(temp.st,str::st);
	strcat(temp.st," ");

	strcat(temp.st,ob.st);
	return temp;
}

int str::operator==(str ob)
{
	int i=0;
	if(strcmp(str::st,ob.st)==0)
		i=1;
	return i;
}
int str::operator!=(str ob)
{
	int i=0;
	if(strcmp(str::st,ob.st)!=0)
		i=1;
	return i;
}
ostream &operator<<(ostream &out,str ob)
{
	out<<ob.st;
	return out;
}
istream &operator>>(istream &in,str &ob)
{
	in>>ob.st;
	return in;
}

int main()
{
	str ob1,ob2,ob3;
	cout<<"\nEnter string 1 = ";
	cin>>ob1;
	cout<<"\nEnter string 2 = ";
	cin>>ob2;
	cout<<"\nString 1 = "<<ob1;
	cout<<"\nString 2 = "<<ob2;
	ob3=ob1+ob2;
	cout<<"\nString 3 = "<<ob3;
	if(ob1==ob2)
		cout<<"\nEqual";
	if(ob1!=ob2)
		cout<<"\nNot Equal";
	cout<<"\n";
	return 0;
}
