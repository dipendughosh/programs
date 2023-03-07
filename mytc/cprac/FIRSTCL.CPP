#include<iostream.h>
#include<conio.h>
class first
{   private:
		int eng,math,comp,roll;
	public:
		int total;
		void getdata()
		{
			cout<<"Enter roll no. : ";	cin>>roll;
			cout<<"English marks  : "; cin>>eng;
			cout<<"Maths   marks  : "; cin>>math;
			cout<<"Computer marks  : "; cin>>comp;
			total = eng + math + comp;
		}
		void showdata()
		{
			cout<<"\nthe sum of a "<< c;
			cout<<"\nthe sum of b "<<d;
		}
};

void main()
{
	clrscr();
	first obj1, obj2;
	first temp;
	obj1.getdata();
	obj2.getdata();
	if(obj2.total>obj1.total)
	{	temp = obj1;
		obj1 = obj2;
		obj2 = temp;
	}
	obj3.showdata();
	getche();
}