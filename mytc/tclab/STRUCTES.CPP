#include<iostream.h>
#include<conio.h>
struct length
{	int feet;
	int inches;
};
void main()
{	length obj;
	length *ptrobj;
	clrscr();
	cout<<"Enter feet : "; cin>>obj.feet;
	cout<<"Enter inches : "; cin>>obj.inches;
	cout<<"\nfeet : "<<obj.feet;
	cout<<"\tinches : "<<obj.inches;
	ptrobj = new length;
	ptrobj->feet = 33;
	ptrobj->inches = 11;
	delete ptrobj;
	cout<<"\nfeet2 : "<<ptrobj->feet;
	cout<<"\tinches2 : "<<ptrobj->inches;
	getche();
}

