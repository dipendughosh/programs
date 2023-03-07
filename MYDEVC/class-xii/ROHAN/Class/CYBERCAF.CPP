#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
//#include<dos.h>
class calender
{
	int m[13];
	public:
		calender()
		{              //jan  //feb   //mar..............
			m[0]=0;m[1]=31;m[2]=28;m[3]=31;m[4]=30;m[5]=31;m[6]=30;
			m[7]=31;m[8]=31;m[9]=30;m[10]=31;m[11]=30;m[12]=31;
		}
		long sum(int mm,int);
};
long calender::sum(int mm,int dd)
{
	long sum=dd;
	for(int i=1;i<mm;i++)
	{
		//cout<<"\nWorking"<<"i--"<<i;
		//cout<<"sum--"<<sum<<endl;getch();
		sum+=m[i];
	}
	//cout<<"sum--"<<sum<<endl;getch();
	//cout<<"sum"<<(sum*24*60)<<endl;
	return (sum*24*60);
}
class date
{
	int day,month;
	public:
		void input()
		{
			cout<<"\nEnter day.....";cin>>day;
			cout<<"\nEnter month...";cin>>month;
		}
		int ret_day()
		{	return day;	}
		int ret_mon()
		{	return month;	}
};
class time
{
	int hr,min;
	calender obj;
	public:
		void input()
		{       cout<<"\nEnter time ..(hr/min)";cin>>hr>>min;}
		long convert(int dd,int mm)
		{
			long t1;
			t1=(hr*60)+min+obj.sum(mm,dd);
			//cout<<dd<<"-t1-"<<t1<<endl;getch();
			return t1;
		}
};
class user
{
	date login,logout;
	time entry,exit;
	public:
		void input()
		{
			cout<<"\nLogin Details.........\n";
			login.input();entry.input();
			cout<<"\nLogout Details........\n";
			logout.input();	exit.input();
		}
		void cal()
		{
			long m,d1,d2;
			d1=(exit.convert(logout.ret_day(),logout.ret_mon()));
			d2=(entry.convert(login.ret_day(),login.ret_mon()));
			m=d1-d2;
			cout<<"\n Hours..."<<(m/60)<<"\t Minutes..."<<(m%60);
			getch();
		}

};
void main()
{
	clrscr();
	user obj;
	obj.input();
	obj.cal();
	getch();
}





