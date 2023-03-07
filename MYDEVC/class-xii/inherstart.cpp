#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class abc
{   int a,b;
	public:
	abc(int c,int d)
	{
		cout<<"\nClass abc's constructor....\n";
		a=c;
		b=d;
	}
	/*void getdata()
	{   cout<<"Enter value for a : "; cin >> a;
		cout<<"Enter value for b : "; cin >> b;
	}  */
};
class xyz : public abc
{   int x,y,z;
	public:
	xyz(int c,int d,int i,int j ):abc(c,d)
	{
		cout<<"\nClass xyz's constructor....\n";
		x=i;
		y=j;
	}
	/*void getdata()
	{   abc::getdata();
		cout<<"\nEnter value for x : "; cin >> x;
		cout<<"Enter value for y : "; cin >> y;
	} */
	void adddata()
	{   z = abc::a + abc::b + x + y;
	}
	void showdata()
	{   cout<<"\nAdded value : "<< z;
	}
};

int main()
{
	xyz obj(1,2,3,4);
	//obj.getdata();
	obj.adddata();
	obj.showdata();
	cout<<endl;
	system("PAUSE");
	return 0;
}
