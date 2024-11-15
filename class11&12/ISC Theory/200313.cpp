//17
//Intersection & Union of 2 arrays(done)
#include<iostream.h>
#include<conio.h>

class set                      //declare class
{	 private:              //declare variables
	 int n,array[50];
	 public:               //declare protypes of class functions
	 set();
	 set(int);
	 void displayElement();
	 void readElement();
	 int getsize();
	 int has(int);
	 set intersection(set);
	 set unions(set);
	 ~set();
};

set set::set()                //default constructor
{	n=0;
}

set set::set(int nm)          //parameterized constructor
{	int i;
	n=nm;
	for(i=0;i<n;i++)
		array[i]=0;
}

void set::readElement()       //function to enter elements of array
{	int i;
	for(i=0;i<n;i++)
	{	cin>>array[i];
	}
}

void set::displayElement()    //function to display elements of array
{	int i;
	cout<<"[  ";
	for(i=0;i<n;i++)
	{	cout<<array[i]<<"  ";
	}
	cout<<"]";
}

int set::getsize()            //function to take size of array as input
{	int nm;
	cin>>nm;
	return nm;
}

int set::has(int ele)         //function to check if an element is present
{	int i;
	for(i=0;i<n;i++)
	{	if(ele==array[i])
		{	return 1;
		}
	}
	return 0;
}

set set::intersection(set d)  //function to find intersection of 2 arrays
{       cout<<"\n\tIntersection";
	int i,c,f,x=0;
	cout<<"\nEnter number of elements of 2nd array:";
	d.n=d.getsize();
	cout<<"Enter elements of 2nd array:\n";
	d.readElement();
	cout<<"Elements in 2nd array are:\t";
	d.displayElement();
	cout<<"\nCommon elements are:\t[  ";
	for(i=0;i<d.n;i++)    //loop to check if an element is present
	{	c=has(d.array[i]);
		if(c==1)
		{	cout<<d.array[i]<<"  ";
			x++;
		}
	}
	if(x==0)
		cout<<"No common elements?  ";
	cout<<"]";
	return 0;
}

set set::unions(set d)        //function to find union of 2 arrays
{	cout<<"\n\tUnion";
	int i,c,f;
	cout<<"\nEnter number of elements of 3rd array:";
	d.n=d.getsize();
	cout<<"Enter elements of 3rd array:\n";
	d.readElement();
	cout<<"Elements in 3rd array are:\t";
	d.displayElement();
	cout<<"\nAll elements are:\t[  ";
	for(i=0;i<n;i++)      //loop to find union of the arrays
	{	cout<<array[i]<<"  ";
	}
	for(i=0;i<d.n;i++)
	{	c=has(d.array[i]);
		if(c==0)
			cout<<d.array[i]<<"  ";
	}
	cout<<"]";
	return 0;
}

set set::~set()              //destructor
{
}

void main()                 //main function
{	clrscr();
	int nm;             //declaring variables
	cout<<"Enter number of elements of 1st array:";
	cin>>nm;
	set d(0);          //*creating class
	set a(nm);          //objects
	cout<<"Enter elements of 1st array:\n";
	a.readElement();
	cout<<"Elements in 1st array are:\n";
	a.displayElement();
	a.intersection(d);
	a.unions(d);
	getche();
}