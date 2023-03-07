//find largest no of nos from keyboard
#include<iostream.h>
#include<conio.h>
void main()
{   clrscr();
		char ch='y';
		int n,max;
		cout<<"Enter a number ";
		cin>>max;
		do
		{	cout<<"\nEnter a number ";
			cin>>n;
			if(n>=max)
				max=n;
		cout<<"\nDo You want to continue (YES-y) (NO-n) ";
		cin>>ch;
		}while(ch=='y');
		cout<<"The largest number is "<<max;
		getche();
}

