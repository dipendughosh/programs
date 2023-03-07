#include <iostream.h>
#include <conio.h>
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
class date
{   int dd,mm;
    public:
        date(int nd, int nm)
            {   dd = nd; mm = nm;   }
        //date(){}
        int datetodatenumber();
        date datenumbertodate(int);
        date futuredate(int);
};
int date::datetodatenumber()
{   int daynum = 0;
    for(int i = 1; i < mm; i++) daynum += days[i];
    daynum += dd;
    return daynum;
}
date date::datenumbertodate(int dn)
{   date temp(0,0); int i = 1;
    while(dn > days[i]) dn -= days[i++];
    temp.mm = i; temp.dd = dn;
    //cout<<"\n"<<temp.dd<<" -> "<<temp.mm;
    return temp;
}
date date::futuredate(int n)
{   int totday = datetodatenumber() + n;
    cout<<"\nTotal days : "<<totday;
    date future = datenumbertodate(totday);
    cout<<"\nFuture date is : "
    <<future.dd<<" th of month  "<<future.mm;
    return future;
}
int main()
{   date today(15,7); int futday;
    cout<<"\nToday is : "<<today.dd<<" th of month "<<today.mm;
    int din = today.datetodatenumber();
    cout<<"\nNo. of days as on this day : "<<din;
    today.datenumbertodate(din);
    cout<<"\nAdd days with current day : "; cin>>futday;
    today.futuredate(futday);
    getche();
    return 0;
}

