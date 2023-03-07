#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class time
{
	int day,month1,hr1,m1,hr2,m2,day2,month2,id,t;
	public:
		void input()
		{
			cout<<"\nEnter I.D.....................";cin>>id;
			cout<<"\nEnter Login month date........";cin>>month1>>day;
			cout<<"\nEnter Login time..............";cin>>hr1>>m1;
			cout<<"\nEnter Logout month date.......";cin>>month2>>day2;
			cout<<"\nEnter Logout time..............";cin>>hr2>>m2;
		}
		int compute()
		{
			int dd=0,dd2=0;
			long x=0;
			//for first timting
			dd=(((month1-1)*31+day)*24)+hr1;
			dd=dd*60;
			dd+=m1;
			//for second time
			dd2=(((month2-1)*31+day2)*24)+hr2;
			dd2=dd2*60;
			dd2+=m2;
			x=dd2-dd;
			t=x;
			return x;
		}
		void show(int x)
		{
			cout<<"\nEnter I.D....................."<<id;
			cout<<"\nEnter Login month date........"<<month1<<"-"<<day;
			cout<<"\nEnter Login time.............."<<hr1<<"-"<<m1;
			cout<<"\nEnter Logout month date......."<<month2<<"-"<<day2;
			cout<<"\nEnter Logout time............."<<hr2<<"-"<<m2;
			cout<<"\nDuration (hr/minutes)........."<<x/60<<"-"<<x%60;
			cout<<endl;
		}
		int give()
		{
			return t;
		}
};
void main()
{
	clrscr();
	time obj[100];
	int no;
	cout<<"\nEnter number of user's.........";cin>>no;
	for(int i=0;i<no;i++)
	{
		obj[i].input();
	}
	clrscr();
	for(i=0;i<no;i++)
	{
		obj[i].show(obj[i].compute());
	}
	getch();
}
