 //creating array of objects from a simple class

#include<iostream.h>
#include<conio.h>
class number
{   private:
		int num1;
		int num2;
		int total;
	public:
		void getdata()
		{	cout<<"Enter number1 : "; cin>>num1;
			cout<<"Enter number2 : "; cin>>num2;
			total = num1 + num2;
		}
		void showdata()
		{	cout<<"\nTotal is : "<<total;
		}
};

void main()
{   clrscr();
	number no[3];
	int t;
	for(int i = 1; i <= 3; i++)
	{	cout<<"This is data set "<<i<<"\n";
		no[i].getdata();
		cout<<endl;
	}
	cout<<"\nWhich set-total needed ? "; cin>>t;
	cout<<"This is Total of set "<<t;
	no[t].showdata();
	getche();
}
