#include<iostream.h>
#include<conio.h>

class student
{
	private:
		int roll, marks;  // member vars
	public:
		void getdata()                  // mem func
		{	cout<<"Enter roll : "; cin>>roll;
			cout<<"Marks      : "; cin>>marks;
		}
		void arrange()                  // mem func

		void showdata()                 // mem func
		{	cout<<"Roll : "<<roll<<"\t"<<"Marks : "<<marks;	}
};

void main()
