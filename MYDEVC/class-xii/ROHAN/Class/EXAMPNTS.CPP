#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
#include<dos.h>
class iscscore
{
	int a[6][2];
	public:
		iscscore();
		void point();

};
iscscore :: iscscore()
{
		cout<<"\nPlease enter subject codes....(\nEnglish     =01\nBengali     =02\nMathematics =03\nPhysics     =04\nChemistry   =05\nComputer    =06)\n\n";
		for(int i=0;i<6;i++)
		{
			cin>>a[i][0];
		}
		cout<<"\nEnter Marks  .....";
		for(i=0;i<6;i++)
		{
			cin>>a[i][1];
		}

}
void iscscore::point()
{
	int point =0;
	for(int i=0;i<6;i++)
	{
		if(a[i][1]>90)
			point=1;
		else
		{
			if(a[i][1]>=80)
				point=2;
			else
			{
				if(a[i][1]>70)
					point=3;
				else
				{
					if(a[i][1]>60)
						point=4;
					else
					{
						if(a[i][1]>50)
							point=5;
					else
					{
						if(a[i][1]>40)
							point=6;
						else
							point=7;
						}
					}
				}
			}
		}
	cout<<a[i][0]<<"   "<<a[i][1]<<"       "<<"Point-->"<<point<<endl;;
	}
}
void main()
{
	clrscr();
	iscscore temp;
	temp.point();
	getch();
}





