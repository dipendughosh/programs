#include<iostream.h>
#include<conio.h>
class abc
{
	int a,b,c;
	public:
		abc(int p, int q)
		{
			cout<<"This is a constructor\n";
			/*cout<<"Enter first value : "; cin>>a;
			cout<<"Enter second value : "; cin>>b;*/
			a = p; b = q;
		}

		void adddata()
		{  c = a + b;
		}

		void showdata()
		{	cout<<"\nAdded value : "<<c;
		}
};
void main()
{   clrscr();
	//abc obj;
	//obj.getdata();
	int x,y;
	cout<<"Enter first value : "; cin>>x;
	cout<<"Enter second value : "; cin>>y;
	abc obj(x,y);
	obj.adddata();
	obj.showdata();
	getche();
}














