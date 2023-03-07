#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class book
{
	int code,pcode,stock;
	float price;
	public:
		void inn()
		{
			int c ,pc,s;
			float p;
			cout<<"\nEnter code...........";cin>>c;
			cout<<"\nEnter publisher......";cin>>pc;
			cout<<"\nEnter stock..........";cin>>s;
			cout<<"\nEnter price..........";cin>>p;
			code=c;pcode=pc;stock=s;price=p;
		}
		void sale();
		void show()
		{
			cout<<"\nBook code---"<<code<<"\t stock "<<stock;
		}
		void output()
		{
			cout<<"\n";
			cout<<"Code...."<<code<<"\tStock..."<<stock<<"\tPrice..."<<price;
		}
		int give()
		{
			return code;
		}
};
void book::sale()
{
	int no;
	cout<<"\nPlease enter number of books......";
	cin>>no;
	if(no>stock)
	{
		cout<<"\nSorry not enough stock....\n";
	}
	else
	{
		stock-=no;
		cout<<"cost is....."<<(price*no);
		cout<<endl;
	}
}
void main()
{
	clrscr();
	int x=0,cc=0,p,n;
	char ch;
	book a[25];
	book temp;
	cout<<"\nNUMBER OF BOOKS....";cin>>n;
	for(int i=0;i<n;i++)
	{
		a[i].inn();
	}
	clrscr();
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		a[i].output();
		cout<<endl;
	}
	do
	{
		clrscr();
		for(i=0;i<n;i++)
		{	a[i].output();	cout<<endl;	}
		cout<<"\nEnter book you want to buy......";cin>>cc;
		x=0;
		for(i=0;i<n;i++)
		{
			if(a[i].give()==cc)
			{	temp=a[i];p=i;	}
			else x++;
		}
		if(x<n)
		{	temp.sale();
			a[p]=temp;
		}
		else
		{       cout<<"\nNo such book is available......\n";	}

		cout<<"\nWant to continue.....";cin>>ch;
	}
	while(ch=='Y');
	clrscr();
	cout<<"\nUpdated stocks.....\n";
	for(i=0;i<n;i++)
	{
		a[i].show();
		cout<<endl;
	}
	getch();
}