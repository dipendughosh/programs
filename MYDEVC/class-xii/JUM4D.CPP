//JUMBLING A FOUR DIGIT NUMBER
#include<conio.h>
#include<iostream.h>

void swap(int x[],int f1,int f2)
{
	int temp;
	temp=x[f1];
	x[f1]=x[f2];
	x[f2]=temp;
}
void prn(int a[])
{
	for(int i=0;i<3;i++)
	{
		cout<<a[i];
	}
	cout<<"\t";
}
void main()
{
	void three(int[]);
	int n,h,p=0;
	//clrscr();
	int a[3];
	do
	{
		cout<<"\nEnter number....";cin>>n;
	}
	while(n>999 ||n<100);
	while(n>0)
	{
		h=n%10;
		n=n/10;
		a[p++]=h;
	}
	cout<<"\nPossible combination's are........\n\n";
	three(a);
	for(int i=1;i<=2;i++)
	{
		swap(a,0,i); //cout<<"f---";prn(a);cout<<"---"<<endl;
		three(a);
		//cout<<"\n";
	}
	getche();
}
void three(int x[])
{
	for(int i=1;i<=2;i++)
	{
		swap(x,0,1);
		prn(x);
		swap(x,1,2);
		prn(x);
	}
}

