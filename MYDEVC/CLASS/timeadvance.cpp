#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class abc
{       int d,m;
    public:
        abc()
        {   d=31;  m=12;
        }
};

class xyz:public abc
{       int hh,mm;
    public:
        xyz()
        {   hh=23;  mm=0;
        }
        void get()
        {   int m,n;
            cout<<"Enter hours : ";  cin>>m;
            cout<<"Enter minutes : ";  cin>>n;
            advance(m,n);
        }
        void advance(int,int);
        void show()
        {   cout<<"Day : "<<d<<"\t  Month : "<<m<<"\n";
            cout<<"Hours : "<<hh<<"\t  Minutes : "<<mm;
        }
};

void xyz::advance(int h,int n)
{   if ((mm+n)>=60)
    {   mm=(mm+n)%60;
        hh+=(mm+n)/60;
    }
    else if ((mm+n<60)) mm+=n;

    if ((hh+h)>=24)
    {   hh=(hh+h)%24;
        d+=(hh+h)/24;
    }
    else if ((hh+h)<24) hh+=h;
    //cout<<" d : "<d;
    if (d>31)
    {   d=d%31;
        m+=d/31;
    }
    cout<<" m : "<<m;
    if (m>12)  m=1;

}


int main()
{   xyz o1;
    o1.get();
//    o1.advance();
    o1.show();
    cout<<endl;
    system("PAUSE");
    return 0;
}
