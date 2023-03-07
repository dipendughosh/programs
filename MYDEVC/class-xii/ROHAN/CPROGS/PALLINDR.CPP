#include<process.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
void main()
{
	clrscr();
	int n,k=10000,h,h1,p,s=0;
	cout<<"\nEnter a 5-digit number..";cin>>n;
	p=n;
	if(n<10000)
	{
		cout<<"\nIllegal entry \nExiting programme...bye bye.."; getch();
		exit(0);
	}
	while(n!=0)
	{
		h=n%10;
		n=n/10;
		h1=h*k;
		s+=h1;;
		k/=10;
	}

	if(s==p)
		cout<<"\nYes the number entered is pallindrome..";
	else
		cout<<"\nThe number entered is not a pallindrome..";
	getch();
}