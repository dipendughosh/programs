//LEARNING TO WRITE SIMPLE FUNCTIONS
# include <iostream.h>
# include <conio.h>

void main()
{	clrscr();
	int first,second;
	void sum(int,int),diff(int,int);
	int swap(int,int);
	cout<<"\nEnter first number : "; cin>>first;
	cout<<"Enter second number : "; cin>>second;
	swap(first,second);
	cout<<"\nFirst number : "<<first;
	cout<<"\nSecond number : "<<second;
   /*	sum(first,second);
	diff(first,second);

	//cout<<"\nThe sum is : "<<sum(first,second);*/
	getch();
}

int swap(int f,int s)
{	int temp;
	temp = f;
	f = s;
	s = temp;
	return (f,s);
}

void sum(int f, int s)
{	int third;
	third = f + s;
	cout<<"\nThe sum is : "<<third;
}

void diff(int f, int s)
{	int third;
	third = f - s;
	cout<<"\nThe difference is : "<<third;
}







