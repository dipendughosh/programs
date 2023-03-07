#include <iostream.h>
#include <conio.h>

class time
{   int hh,mm;
    public:
        time() { hh = 0; mm = 0; }
        void readtime();
        void disptimeansi();
        int timetominutes(time);
        void minutestotime(int);
        void diff(time endtime, time starttime);
};

void time::readtime()
{   cout<<"\nHours   : "; cin>>hh;
    cout<<"Minutes : "; cin>>mm;
}

void time::disptimeansi()
{   cout<<hh<<" Hours "<<mm<<" Minutes"; }

int time::timetominutes(time samay)
{   int timin = samay.hh * 60 + samay.mm;
    return timin;
}

void time::minutestotime(int tm)
{   hh = tm/60; mm = tm%60; }

void time::diff(time endtime,time starttime)
{   int hour,minute;
    /*
    int elapsed = endtime.timetominutes(endtime) - starttime.timetominutes(starttime);
                                     OR
    */
    if (endtime.hh < starttime.hh) endtime.hh+=24;
    int endmin = endtime.hh * 60 + endtime.mm;
    int startmin = starttime.hh * 60 + starttime.mm;
    int elapsed = endmin - startmin;
    hour = elapsed/60;
    minute = elapsed%60;
    cout<<"\n"<<hour<<" Hours : "<<minute<<" minutes";
}

// ============== NOT NEEDED =====================
void main()
{   time starttime,endtime;
    int timeinminstart, timeinminend;
    cout<<"\nPlease enter Login time : "; starttime.readtime();
    cout<<"\n\tLogged on at ... "; starttime.disptimeansi();
    timeinminstart = starttime.timetominutes(starttime);
    cout<<"\nPlease enter Logout time : "; endtime.readtime();
    cout<<"\n\tLogged out at ... "; endtime.disptimeansi();
    timeinminend = endtime.timetominutes(endtime);
    cout<<"\nUsed the Net for  ... ";
    starttime.diff(endtime,starttime);
    getche();
}
