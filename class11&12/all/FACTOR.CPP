#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		long double i,n,a=1;
		cout<<"Enter Limit ";
		cin>>n;
		for(i=1;i<=n;i++)
				a=(a*i);
		cout<<"\nFacctorial of "<<n<<" is "<<a;
		getche();
}