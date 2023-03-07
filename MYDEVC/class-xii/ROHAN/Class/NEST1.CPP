#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class person
{
	char name[50];
	class age
	{
		int dd,mm,yy;
		public:
			void input()
			{
				cout<<"\nENTER AGE IN DD MM YY FORMAT......";
				cin>>dd>>mm>>yy;
			}
			void show()
			{
				cout<<"\nAGE IS ....."<<yy<<"years"<<mm<<"months"<<dd<<"days\n";
			}


	};
	age obj;
	public:
		void input1()
		{
			cout<<"\nENTER NAME......";gets(name);
			obj.input();
		}
		void show1()
		{
			cout<<"\nNAME IS........"<<name;
			obj.show();
		}
};
void main()
{
	clrscr();
	person a[3];
	for(int i=0;i<3;i++)
	{
		a[i].input1();
	}
	clrscr();
	for(i=0;i<3;i++)
	{
		a[i].show1();
	}
	getch();
}