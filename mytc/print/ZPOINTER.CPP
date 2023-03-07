//learning pointers
#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int x,y;
	int *ptr1;    int *ptr2;
	x=10;
	ptr1= &x;
	cout<<"\n ptr1 "<<ptr1<<"\t *ptr1 "<<*ptr1;
	*ptr1= *ptr1+1;
	y= *ptr1;
	cout<<"\n Now y= "<<y;
	cout<<"\n *ptr1+1 " ; (*ptr1)++;   //IF WE DO *PTR1++ THEN *PRT1 WILL BE 0
	y=*ptr1;
	cout<<"\n Now y="<<y;
	cout<<"\n (*ptr1)++";
	(*ptr1)++;
	cout<<"\n Now y=";
	y=*ptr1;
	cout<<y;
	++*ptr1;
	cout<<"\n ++*ptr1  "<<*ptr1;
	ptr2=ptr1;
	cout<<"\n pointer 1="<<*ptr1;
	cout<<"\n pointer 2="<<*ptr2;
	getche();
 }

