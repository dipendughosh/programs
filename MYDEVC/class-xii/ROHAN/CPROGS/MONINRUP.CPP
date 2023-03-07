//RUPEE DENOMINATIONS;
#include<conio.h>
#include<iostream.h>
void main()
{
	clrscr();
	int a[9]={1000,500,100,50,20,10,5,2,1};
	int no,n;
	cout<<"\nEnter a number..";cin>>no;
	for(int i=0;i<9;i++)
	{
		n=0;
		while(no>=a[i])
		{
			no=no-a[i];
			n++;
		}
		cout<<"\nRs "<<a[i]<<"notes are-->"<<n;
	}
	getch();
}