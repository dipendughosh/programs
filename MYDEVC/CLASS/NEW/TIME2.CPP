#include<conio.h>
#include<stdlib.h>
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
		{	cout<<"Enter the time in 24-hour format : ";
			cin>>hh>>mm;
		}
		void disptime()
		{
		}
		void minutestotime(int p)
		{   int h,m;
            if (p>60)
            {   m=p%60;
                h=p/60;
            }
            else if (p<60)
                 {  h=0;
                    m=p;
                 }
        }
       int timetominutes(time);
       void diff(time endtime,time starttime);
};


int time::timetominutes(time df)
{   int min_calc=0;
	if (df.mm==0)  min_calc+=df.mm;
	else min_calc+=(df.hh*60+df.mm);
	return min_calc;
}

void time::diff(time endtime,time starttime)
{   int d=timetominutes(endtime)-timetominutes(starttime);
    minutestotime(d);
    /*if (endtime.hh<starttime.hh && endtime.mm<starttime.mm)
		{	endtime.hh+=23;
			endtime.mm+=60;
		}

	else if (endtime.hh<starttime.hh && endtime.mm>starttime.mm)
			endtime.hh+=24;

	if (endtime.hh==starttime.hh && endtime.mm==starttime.mm)
		cout<<"\nWrong entry.";

	if (endtime.hh==starttime.hh && endtime.mm<starttime.mm)
		{	endtime.hh+=23;
			endtime.mm+=60;
		}

	if (endtime.hh>starttime.hh && endtime.mm<starttime.mm)
		{   endtime.hh--;
			endtime.mm+=60;
		}
	d.mm=endtime.mm-starttime.mm;
	d.hh=endtime.hh-starttime.hh;*/
}



void main()
{   int totmins;
	time starttime,endtime;
	cout<<"\nEnter the starting time : ";
	starttime.readtime();
	cout<<"\nEnter the ending time : ";
	endtime.readtime();
	starttime.diff(endtime,starttime);
//	totmins=timetominutes();
//	starttime.minutestotime(totmins);
    system("PAUSE");
}
