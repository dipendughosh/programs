// Date of birth ==> Age ==> difference etc.

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define PERSON 3
class dates
{   int day,month,year;
    public:
        dates()
        {   day = month = year = 0; }
        void getdates();
        int datetoday()
        {   return((((year*12) + month) * 30) + day); }
        void age(int,int);
};
void dates::getdates()
{   do
    {   cout<<"\nEnter day : "; cin>>day;
    } while(day < 1 || day > 31);
    do
    {   cout<<"\nEnter month : "; cin>>month;
    } while(month < 1 || month > 12);
    do
    {   cout<<"\nEnter year : "; cin>>year;
    } while(year < 1 || day > 2004);
}

void dates::age(int curdays,int totdays)
{   int lived,dd,mm,yy;
    lived = curdays - totdays;
    dd = lived % 30;
    lived /= 30;
    mm = lived % 12;
    yy = lived /12 ;
    cout<<yy<<" years "<<mm<<" months "<<dd<<" days";
}

void main()
{   int curday,days[PERSON],a,b,diff;
    void daytodate(int);
    dates current,obj[PERSON];
    cout<<"\nEnter current date :\n";
    current.getdates();
    curday = current.datetoday();
    cout<<endl;
    for(int i = 0; i < PERSON; i++)
    {   cout<<"\nEnter DOB of person "<<i+1;
        obj[i].getdates();
        days[i] = obj[i].datetoday();
        cout<<"\nThe age is : ";
        obj[i].age(curday,days[i]);
    }
    diff = 1;
    do
    {   cout<<"\nEnter numbers for difference : ";
        cin>>a;
        if(a<1 || a>PERSON) continue;
        cout<<" and "; cin>>b;
        if(b<1 || b>PERSON || a == b) continue;
        diff = 0;
    } while (diff = 0);
    diff = obj[a-1].datetoday() - obj[b-1].datetoday();
    if (diff = 0) cout<<"\nBoth are of same age.";
    if (diff < 0)
    {   cout<<"Person "<<a<<" is ";
        obj[1].age(obj[a-1].datetoday(), obj[b-1].datetoday());
        cout<<" younger than person "<<b;
    }
    else
    {   cout<<"Person "<<a<<" is ";
        obj[1].age(obj[b-1].datetoday(), obj[a-1].datetoday());
        cout<<" older than person "<<b;
    }

    cout<<endl;
    system("PAUSE");
    return 0;
}

