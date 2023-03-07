 //9
//VECTOR
//Max number,Min number,Remove duplicate(done)
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class vector             //declaring class
{	private:         //declaring private data members
	int arr[20],num,max1,min1,i,j,k,n;
	public:          //declaring public methods
	vector()
	{	n=0;
	}
	void getdata();
	void modify();
	void max();
	void min();
	void display();
	void display2();
	~vector()
	{
	}
};

void vector::getdata()  //method for entering data
{       cout<<"\nEnter elements of vector-->>\n";
	for(i=0;i<10;i++)
	{	cin>>arr[i];
	}
}

void vector::modify()  //method for removing duplicates
{       int a=10,b=10;
	for(i=0;i<a-1;i++)
	{	for(j=i+1;j<a;j++)
		{	if(arr[i]==arr[j])
			{	for(k=j;k<b;k++)
				{	arr[k]=arr[k+1];
					a=k;
				}
				b=a;
				n++;
			}
		}
	}
}

void vector::max()     //method for finding maximum number
{	max1=arr[0];
	for(i=1;i<10-n;i++)
		if(max1<=arr[i])
			max1=arr[i];
	cout<<"\nMaximum number is--> "<<max1<<"\n";
}

void vector::min()     //method for finding minimum number
{	min1=arr[0];
	for(i=1;i<10-n;i++)
		if(min1>=arr[i])
			min1=arr[i];
	cout<<"\nMinimum number is--> "<<min1<<"\n\n";
}

void vector::display2() //method for displaying original data
{	for(i=0;i<10;i++)
		cout<<arr[i]<<"\t";
}

void vector::display() //method for displaying data
{	for(i=0;i<10-n;i++)
		cout<<arr[i]<<"\t";
}
void main()            //main function
{	clrscr();
	vector obj;    //declaring object of class
	obj.getdata();
	obj.display2();
	obj.modify();
	obj.max();
	obj.min();
	obj.display();
	getche();
}

