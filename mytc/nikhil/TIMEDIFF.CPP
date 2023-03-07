#include<conio.h>
#include<iostream.h>

class time
{   	int hh;
		int mm;
	public:
		time()
		{	hh=0;
			mm=0;
		}
		void readtime()
		{	cout<<"Enter the time in 24-hour format :\n";
			cin>>hh>>mm;
		}

		void minutestotime(int p)
		{   int h=0,m=0;
			if (p>60)
			{   m=p%60;
				h=p/60;
			}
			else if (p<60)
				 {  h=0;
					m=p;
				 }
			cout<<"\nMinutes difference : "<<p;
			cout<<"\nHours : "<<h<<"\tMinutes : "<<m;

	   }

	   int timetominutes(time);
	   void diff(time endtime,time starttime);
};


int time::timetominutes(time df)
{   int min_calc=0;
	if (df.mm==0)  min_calc+=df.hh*60;
	else min_calc+=(df.hh*60+df.mm);
	cout<<"\nTOTAL MINUTES : "<<min_calc;
	return min_calc;
}

void time::diff(time endtime,time starttime)
{   if (endtime.hh<starttime.hh)
		endtime.hh+=24;
	int d=timetominutes(endtime)-timetominutes(starttime);
	minutestotime(d);

}

void main()
{   int totmins;
	time starttime,endtime;
	cout<<"\nEnter the starting time :\n";
	starttime.readtime();
	cout<<"\nEnter the ending time :\n";
	endtime.readtime();
	starttime.diff(endtime,starttime);
	cout<<endl;
	getch();
//	system("PAUSE");
}

