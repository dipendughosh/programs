//LEARNING POINTERS
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main() {
	int x,y,*ptr1,*ptr2;clrscr();
	cout<<"Enter a number : "; cin>>x;
	y=x+10; ptr2=&y;
	ptr1 = &x;
	cout<<"\nAddress of x("<<x<<") is "<<ptr1<<endl;
	cout<<"Address of y("<<ptr2<<") is "<<ptr2<<endl;
	cout<<"\nValue of *x("<<*ptr1<<") is "<<*ptr1<<endl;
	printf(	"%u\n",ptr1);
	cout<<"Value of *y("<<*ptr2<<") is "<<*ptr2<<endl;
	getche();
	ptr2 = ptr1+2;
	ptr1++;
	//ptr2 = ptr1+6;
	cout<<"\nAddress of ptr1+=4 is "<<ptr1<<endl;
	cout<<"Address of ptr2=ptr1+2 is "<<ptr2<<endl;
	cout<<"\nValue of *ptr1++ is "<<*ptr1<<endl;
	printf(	"%u\n",ptr1);
	cout<<"Value of *ptr2++ is "<<*ptr2<<endl;
	printf(	"%u\n",ptr1);
	getche();
	}


