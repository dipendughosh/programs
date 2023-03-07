#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class cal
{   private:
            int date;
            int month;
            int year;
            int d;
            int nd;
    public:
           void getdata();
           void calc();
           void secinp();
           void ncalc();
};

void cal::getdata()
{   cout<<"\nEnter date......"; cin>>date;
    cout<<"\nEnter month....."; cin>>month;
    cout<<"\nEnter year......"; cin>>year;
}
void cal::calc()
{   int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    d=0;
    if(month>1)
    {   for(int x=1;x<month;x++)
            d+=a[x-1];
        d+=date;
    }
    else if(month==1)  d=date;
    cout<<"\n\n\aDifference ==> "<<d;
}
void cal::secinp()
{   cout<<"\nEnter no.of days....."; cin>>nd;
}
void cal::ncalc()
{   int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int z=d+nd;
    cout<<"\nTOTAL="<<z;
    int j=0;
    int nd,nm=1;
    if(z>365) {cout<<"\nSorry.....";getche();exit(0);}
    else
    {   while(z>31)
        {   nm++;
            z-=a[j++];
        }
        nd=z;
    }
    cout<<"\n\aThe new date is ==> "<<nd<<'.'<<nm<<'.'<<year;
}

int main()
{   cal c;
    c.getdata();
    cout<<endl;
    c.calc();
    cout<<endl;
    c.secinp();
    cout<<endl;
    c.ncalc();
    cout<<endl;
    system("PAUSE");
    return 0;
}
