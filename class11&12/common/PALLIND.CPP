#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		long a,n,d=0,m;
		cout<<"Enter number ";
		cin>>n;
		m=n;
		while(n!=0)
		{		d*=10;
				a=n%10;
				n=n/10;
				d=d+a;
		}
		cout<<d;
		if(d==m)
			cout<<"\npallindrome";
		else
			cout<<"\nnot";
		getche();
}
