#include<iostream.h>
#include<conio.h>
class holder
{
		char name[10];
		int accno;
	public :
		float bal;
		void getdata()
		{
			cout<<"name ?  ";   cin>>name;
			cout<<"account no ?  ";  cin>>accno;
		}
		void putdata()
		{
			cout<<"\n name  "<<name;
			cout<<" \n account no "<<accno;
		}
 };
 class savings: public holder
 {
		float balance;
	public :
		savings()
		{	cout<<" initial balance ?";  cin>>balance;  }
		int amt;
		void depositing()
		{
			cout<<"amt to be deposited  ?  ";  cin>>amt;
			balance+=amt;
			float interest=(12*balance)/100;
			balance+=interest;
		}
		void with()
		{
			cout<<" amt to be withdrawn  ? ";  cin>>amt;
			if (amt>balance)
				cout<<" withdrawal not possible!  ";
			 else
				balance-=amt;
			 float interest=(12*balance)/100;
			 balance+=interest;
		 }
		void getdata()
		{	holder::getdata();  }
		void putdata()
		{
			holder ::putdata();
			cout<<" \n present balance in savings account is : "<<balance;
		 }
 };

 class current : public holder
 {
		float balance;
	public :
		current()
		{	cout<<"initial balance   ";  cin>>balance;  }
		int amt;
		void depositing()
		{
			cout<<"amt to be deposited  ?  ";  cin>>amt;
			balance+=amt;
			int interest=(12*balance)/100;
			balance+=interest;
		}
		void with()
		{
			 cout<<" amt to be withdrawn  ? ";  cin>>amt;
			 balance-=amt;
			 int interest=(12*balance)/100;
			 balance+=interest;
		 }
		void getdata()
		{	holder::getdata();  }
		void putdata()
		{
			holder::putdata() ;
			cout<<" \n present balance in current account is : "<<balance;
		 }
 };
 void main()
 {
	clrscr();
	char ch,ans;
	cout<<" your's is current or savings account(c/s) ? ";  cin>>ch;
	switch( ch)
	{	case 's':savings obj1;
				obj1.getdata();
				cout<<"depositing or withdrawing(d/w) ?  ";  cin>>ans;
				switch(ans)
				{
					case 'd':  obj1.depositing();   break;
					case 'w':  obj1.with();    break;
					default: " wrong choice ! ";
				 }
				obj1.putdata();
				break;
		 case 'c': current obj2;
				obj2.getdata();
				cout<<"deposit or withdraw ? ";cin>>ans;
				switch(ans)
				{
					case 'd':  obj2.depositing();   break;
					case 'w':  obj2.with();    break;
					default: " wrong choice ! ";
				 }
				obj2.putdata();
				break;
		 default: cout<<"wrong input!!  ";
				  break;
	 }
   getche();
}



