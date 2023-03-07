// 2003 reading from array in order and binary search
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

class myarray
{	int n,arr[100];
	public:
		myarray() { n = 0; }
		void readarray();
		void displayarray();
		int binarysearch(int);
};
void myarray::readarray()
{	int p = 0, i = 0;
	cout<<"Enter the integer : "; cin >> n;
	cout<<"\nNow the numbers :\n";
	while ( i< n )
	{	cin >> arr[i];
		if ( arr[i] <= p ) continue;
		p = arr[i++];
	}
}
void myarray::displayarray()
{	for ( int i = 0; i < n; i++ )
	cout<<setw(3)<<arr[i];
}

int myarray::binarysearch(int value)
{  int first = 0, last = n, found = 0;
   int position = ( first + last ) / 2;

   while (( !found ) && last >= first )
   {    if ( value == arr[position]) found = 1;
		else
		{	if ( value > arr[position] )
			{	first = position;
				if( first == (n-1)) break;
			}
			else
			{	last = position;
				if( last == found ) break;
			}
			position = ( first + last ) / 2;
		}
   }
   return ( ( found ) ? ++position : -999 );
}

void main()
{   //clrscr();
	myarray test;
	int num;
	test.readarray();
	cout<<endl;
	test.displayarray();
	cout<<"\nEnter a number to search : "; cin>>num;
	cout<<"The position is : "<<test.binarysearch(num);
	getche();
}
