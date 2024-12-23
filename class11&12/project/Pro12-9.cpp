//8
//String concatenation,reverse of string,copy sring(done)
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class string          //declaring class
{	private:      //declaring private data embers
	char str1[80],str2[80],str3[80],str4[160];
	int i,j,len;
	public:       //declaring public methods
	string()
	{
	}
	void initialise();
	void getdata();
	void displaydata(string,string,string );
	void reverse();
	void copy();
	void concatenate(string,string);
	~string()
	{
	}
};

void string::initialise()//initialising all strings to "\0"
{       len=0;
	for(i=0;i<180;i++)
		str1[i]='\0';
		str2[i]='\0';
		str3[i]='\0';
		str4[i]='\0';
}

void string::getdata()   //method for entering string
{	cout<<"\nEnter a string->\n";
	gets(str1);
	for(i=0;i<80;i++)
	{	if(str1[i]=='\0')
			break;
		else
			++len;
	}
}

void string::reverse()   //reversing entered string
{       int x=0;
	for(i=len-1;i>=0;i--)
	{	str2[x]=str1[i];
		x++;
	}
	str2[x]='\0';
}

void string::copy()     //coping entered string
{	for(i=0;i<=len;i++)
	{	str3[i]=str1[i];
	}
}

void string::concatenate(string obj1,string obj2)//concateing two strings
{       int x=0;
	for(i=0;i<obj1.len;i++)
		str4[i]=obj1.str1[i];
	str4[i]=' ';
	for(j=i+1;j<=(obj1.len+obj2.len);j++)
	{	str4[j]=obj2.str1[x];
		x++;
	}
	str4[j++]='\0';
}

void string::displaydata(string obj1,string obj2,string obj3)//displaying data
{	cout<<"\nOriginal string->\n\t"<<obj1.str1;
	cout<<"\nReversed string->\n\t"<<obj1.str2;
	cout<<"\nCopied string->\n\t"<<obj1.str3;
	cout<<"\nConcatenated string is->\n\t"<<str4;
}

void main()                  //main function
{	clrscr();
	string obj1,obj2,obj3;//declaring class objects
	obj1.initialise();
	obj1.getdata();
	obj1.reverse();
	obj1.copy();
	cout<<"\Enter string to be concatenated->";
	obj2.getdata();       //calling method for 2nd string
	obj3.concatenate(obj1,obj2);
	obj3.displaydata(obj1,obj2,obj3);
	getche();
}

