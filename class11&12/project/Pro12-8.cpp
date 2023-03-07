//5
//Displaying geust list in a party(done)
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class counter        //declaring class
{	private:     //declaring private data members
	int count;
	public:      //declaring public methods
	counter()
	{	count=0;
	}
	void inccount();
	void givecount(counter,counter,counter);
	~counter()
	{
	}
};

void counter::inccount() //method for increment of counter
{	count++;
}
			//method for displaying data
void counter::givecount(counter obj1,counter obj2,counter obj3)
{       cout<<"\nNo. of ladies"<<obj1.count;
	cout<<"\nNo. of gentlemen"<<obj2.count;
	cout<<"\nNo. of children"<<obj3.count;
	cout<<"\nTotal guest"<<obj1.count+obj2.count+obj3.count;
}

void main()            //main function
{	clrscr();
	counter obj1,obj2,obj3,obj4; //class objects
	char guest[80];              //declaring variable
	int len,i;                   //declaring variables
	cout<<"\nEnter guest list->\ng or G - Gentlemen\nl or L - Ladies\nc or C - children\n\t";
	gets(guest);
	len=strlen(guest);
	for(i=0;i<len;i++)           //loop for increment of counter
	{	if(guest[i]=='l' || guest[i]=='L')
			obj1.inccount();
		else if(guest[i]=='g' || guest[i]=='G')
			obj2.inccount();
		else if(guest[i]=='c' || guest[i]=='C')
			obj3.inccount();
		else
		{	cout<<"\nWRONG INPUT";
			continue;
		}
	}
	obj4.givecount(obj1,obj2,obj3);//calling display method for output
	getche();
}

