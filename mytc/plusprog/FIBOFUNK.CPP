//*making of fibon series*
#include<iostream.h>
#include<conio.h>
void main()
{	int n;
	void print(int);
	cout<<"\na number ";
	cin>>n;
	print(n);
	getche();
}
void print(int n)
{	int i=1,p,j,z;
	cout<<i;
	for(;i<=n;i++)
	{	p=0,j=1;
		cout<<"\n"<<j;
		while(j<i)
		{	z=p+j;
			cout<<z;
			p=j;
			j=z;
		}
		getche();

	}
}
