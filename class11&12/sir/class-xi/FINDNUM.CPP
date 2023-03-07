#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

//void binsearch(int [500]);
void main()
{	clrscr();
	void input(int [500]);
	int arr[500];
	input(arr);

	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

void input(int array[500])
{       cout<<"\nEnter Elements of array-->>";
	do
	{	cin>>array[x];
		x++;
	}
	while (array[x]!=99);
	x--;
	cout<<"\nNumber of elements entered = "<<x;
}
/*#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

int main()
{	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
	return(0);
	
}*/
