#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		int a,c=0,b,n,i;
		cout<<"enter serie limit ";
		cin>>n;
		cout<<"first value ";
		cin>>a;
		cout<<"second value ";
		cin>>b;
		cout<<a<<" "<<b<<" ";
		for(i=2;i<=n;i++)
				{	c=a+b;
					cout<<c<<" \t";
					a=b;
					b=c;
				}
		getche();
}