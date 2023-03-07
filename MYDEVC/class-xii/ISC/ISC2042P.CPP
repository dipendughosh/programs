#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

class str
{	char string[80],string1[80];
	int len;
	public:
	str();
	void getdata();
	void showdata();
	void decode();
	void reverse();
	~str();
};

str::str()
{
}

void str::getdata()
{	cout<<"Enter coded data";
	gets(string);
}

void str::reverse()
{       int i,j;
	char temp;
	len=strlen(string);
	for(i=0,j=(len-1);i<(len-1)/2;i++,j--)
	{	temp=string[i];
		string[i]=string[j];
		string[j]=temp;
	}
}

void str::decode()
{       int i,x=0,a,b,c;
	for(i=0;i<len-1;i++)
	{	if(string[i]>'1')
		{	a=string[i]-48;
			b=string[i+1]-48;
			i=i+1;
			b=(a*10)+b;
			string1[x]=b;
			x++;
		}
		if(string[i]=='1')
		{	a=string[i]-48;
			b=string[i+1]-48;
			c=string[i+2]-48;
			i=i+2;
			c=(a*100)+(b*10)+c;
			string1[x]=c;
			x++;
		}
	}
	string1[x]='\0';
}

void str::showdata()
{	cout<<"\nEncoded Message:\n"<<string;
	cout<<"\nTne Decoded Message:\n"<<string1;
}

str::~str()
{
}

void main()
{	clrscr();
	str obj;
	obj.getdata();
	obj.reverse();
	obj.decode();
	obj.showdata();
	getche();
}
