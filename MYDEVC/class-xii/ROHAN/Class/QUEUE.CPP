#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class que
{
	int a[5];
	int front,back;
	public:
		que()
		{	front=back=-1;		}
		void push();
		void pop();
		void drag();
		void menu();
		void show();
};
void que::push()
{
	if(front<0)	front++;
	char ch='y';
	while(ch=='y' && back<4)
	{
		back++;
		cout<<"\nEnter data......";cin>>a[back];
		cout<<"\nWant to continue......";cin>>ch;
	}
	if(ch=='y' && back>=4)
		cout<<"\n........OVERFLOW.........\n";

}
void que::pop()
{
	char ch='y';
	cout<<"\nWant to delete......";cin>>ch;
	while(ch=='y' && back>-1)
	{
		//cout<<"\nWant to continue......";cin>>ch;
		drag();
		back-=1;
		cout<<"\nWant to delete......";cin>>ch;

	}
	if(ch=='y' && back<=-1)
		cout<<"\n........UNDERFLOW........\n"<<endl;
}
void que::drag()
{
	for(int j=1;j<5;j++)
	{	a[j-1]=a[j];	}
}
void que::show()
{
	for(int i=0;i<=back;i++)
	{	cout<<a[i]<<"  ";	}
}
void que::menu()
{
	int ch;char m;
	do
	{
		cout<<"\n 1.Push Data...";
		cout<<"\n 2.Pop Data....";
		cout<<"\n 3.Show Data...";
		cout<<"\n Enter Choice..";cin>>ch;
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				show();
				break;
			default:
				cout<<"\nIllegal choice....";
		}
		cout<<"\nWant to back to menu......";cin>>m;
	}
	while(m=='y');
}
void main()
{
	clrscr();
	que first;
	first.menu();
	getch();
}











