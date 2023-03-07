/*To find if a train arrives on in an hour of the day or half-hour 
of the day or it comes on a saturday or never on Sundays or on holidays*/
//Including header files
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>

//Using the std namespace
using namespace std;

//Main function
int main()
{
	//Declaring and initializing variables
	int a,b,c,d,i,f;
	char ch[4];
	a=b=c=d=0;

	//Displaying the four cases and asking user for input
	cout<<"Enter four cases:\n";
	cout<<"If a case does not occur,enter z:\n";
	cout<<"case A:It is rush hour\n";
	cout<<"case B:It is Saturday\n";
	cout<<"case C:It is holiday\n";
	cout<<"case D:It is Sunday\n";
	cout<<"Enter your combination of type of the day:- ";

	for(i=1;i<=4;i++)
		cin>>ch[i];
	
	//Converting the desired input in binary format
	for(i=1;i<=4;i++)
	{
		switch(ch[i])
		{
			case 'A': 
			case 'a':
					a=1;
					break;
			case 'B':
			case 'b':
					b=1;
					break;
			case 'C':
			case 'c':
					c=1;
					break;
			case 'D':
			case 'd':
					d=1;
					break;
			case 'Z':
			case 'z':
					break;
		}
	}
	//Finding the absolute values for case c and case d
	c=abs(1-c);
	d=abs(1-d);
	//Findind the valid combination
	f=(b & ~c)|(a & ~c & ~d);
	
	//Displaying the result
	if(f==0)
		cout<<"Trains do not arrive half hour\n";
	else
		cout<<"Trains arrive at half hour\n";
	
	getch();
	
	return 0;
}