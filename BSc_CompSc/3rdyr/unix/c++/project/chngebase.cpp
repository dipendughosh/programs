//To convert a number given in a one base to any other base

#include<iostream>
#include<new>
#include<exception>
#include<string.h>
#include<math.h>

using namespace std;

//Template class convert
template<class type>
class convert
{
//Begining of Private scope
private:
	//Declaring variables
	char string[80],stringhold[80];
	type n1,n2;
//Begining of public scope
public:
	//Default constructor
	convert()
	{
		string[0]=NULL;
		stringhold[0]=NULL;
		n1=0;
		n2=0;
	}
	//Constructor to initialize variables
	convert(char *s,type n1,type n2)
	{
		strcpy(string,s);
		convert::n1=n1;
		convert::n2=n2;
	}
	//Prototype declaration of the member functions
	int check();
	void change();
	void display();
	void temp_type();
	//Destructor
	~convert()
	{
	}
};

//Declaring variables and function
template<class type>
int convert<type>::check()
{	
	//Declaration of variables
	int len,i,a,f=0;
	len=strlen(convert<type>::string);
	//Loop to check if input is a valid input
	for(i=0;i<len;i++)
	{	
		a=convert<type>::string[i];
		//Checking digits
		if((a-48)>=0 && (a-48)<=9)
		{	
			if((a-48)>=n1)
			{	
				cout<<"\nINCORRECT\n\aRe-enter\n";
				f=1;
				break;
			}
		}
		//Checking alphabetes in upper cases
		else if((a-55)>=10 && (a-55)<16)
		{	
			if((a-55)>=n1)
			{ 
			  	cout<<"\nINCORRECT\n\aRe-enter\n";
				f=1;
				break;
			}
		}
		//Checking alphabetes in lower cases
		else if((a-87)>=10 && (a-87)<16)
		{	
			if((a-87)>=n1)
			{
				cout<<"\nINCORRECT\n\aRe-enter\n";
				f=1;
				break;
			}
		}
	}
	return f;
}

//Function to change entered number from old base to new base
template<class type>
void convert<type>::change()
{       //Declaring variables
	int s=0,c,i,a,b,y=0,len,j;
	char d;
	len=strlen(convert<type>::string);
	//Loop to convert number from given base to decimal
	for(i=(len-1);i>=0;i--)
	{	a=convert<type>::string[i];
		if(a>=48 && a<=58)
		{	b=a-48;
			c=(pow(n1,y))*b;
			s=s+c;
		}
		if(a>=65 && a<=70)
		{       b=a-55;
			c=(pow(n1,y))*b;
			s=s+c;
		}
		if(a>=97 && a<=102)
		{       b=a-87;
			c=(pow(n1,y))*b;
			s=s+c;
		}
		y++;
	}
	y=0;
	//Loop to convert the number from decimal to the new base
	while(s!=0)
	{	b=s%n2;
		s=s/n2;
		if(b>=0 && b<=9)
		{	convert<type>::stringhold[y]=b+48;
			y++;
		}
		if(b>9 && b<16)
		{	convert<type>::stringhold[y]=b+55;
			y++;
		}
	}
	convert<type>::stringhold[y]='\0';
	len=strlen(convert<type>::stringhold);
	//Reversing the output number
	for(i=0,j=len-1;i<len/2;i++,j--)
	{	
		d=convert<type>::stringhold[i];
		convert<type>::stringhold[i]=convert<type>::stringhold[j];
		convert<type>::stringhold[j]=d;
	}
}

//To display the entered number and the converted number
template<class type>
void convert<type>::display()
{
	cout<<"The entered number = "<<convert<type>::string<<" in base "<<n1<<"\n";
	cout<<"The converted number = "<<convert<type>::stringhold<<" in base "<<n2<<"\n";
}

//Choice of the user
template<class type>
void convert<type>::temp_type()
{
	//Declaring variables
	char s[80];
	int n;
	n=check();
	if(n==0)
	{
		change();
		display();
	}
}

//Main function
int main()
{
	char s[80];
	cout<<"\nEnter a number in any Base(between 1-16) : ";
	cin>>s;
	int n1,n2;
	cout<<"Enter the Base of the number : ";
	cin>>n1;
	cout<<"Enter the Base to which to convert the entered number : ";
	cin>>n2;
	convert<int> a(s,n1,n2);
	a.temp_type();
	return 0;
}
