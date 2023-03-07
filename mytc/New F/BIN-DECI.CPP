//JHAMELA!!
//to change a binary no to decimal
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{	clrscr();
	float bin1,bin2;
	int copy,no=0,d,c=0;
	cout<<"\n binary no ? ";	cin>>bin1;
	copy=bin1;		bin2=bin1-copy;
	while(copy)
	{	d= copy % 10;
		no+= (d* pow(2,c++));
		copy/=10;
	}
	cout<<"\n decimal no is : "<<no;
	c=-1;	int n;	float s=0.0;
/*	while(c!=-8)
	while(bin2!=0)
	{	bin2= bin2 * 10;
		n= bin2;
		bin2 = bin2-n;
		if(n==0)
			d=(n * pow(2,c--));
	   cout<<"\n d "<<d;
	   s+=d;
	   cout<<"\t s "<<s;  getche();
	}*/
	cout<<"bin2 * pow "<<bin2* pow(10,8);	getche();
	for(int i=1;i<=8;i++)
	{   bin2= bin2 * 10;
		n= bin2;
		if(n==1)
				s+=(n * pow(2,-i));		cout<<"\n s "<<s<<"\t i "<<i;
		bin2 = bin2-n;	cout<<"\t bin2 "<<bin2;	getche();
	}
	cout<<"\n sum  "<<s;
	getche();
}

