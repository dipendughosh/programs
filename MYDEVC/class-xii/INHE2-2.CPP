# include<iostream.h>
# include<conio.h>
class test
{
	int a;
	public:
		test()	{	a = 5;	}
		void give() { cout<<"test1.a ---> "<<a;}
	   //	virtual void give() { cout<<"test1.a ---> "<<a;}
};
class test2 :public test
{
	int a;
	public:
		test2()	{	a = 6;	}
		void give() { cout<<"test2.a ---> "<<a;}
};

void main()
{
	clrscr();
	test  obj1;
	test2 obj2;
	test *temp;
	temp = &obj1;	temp->give();
	temp = &obj2;
	cout<<endl;  	temp->give();
	getch();
}




