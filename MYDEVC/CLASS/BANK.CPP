#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

class account
{       int acc1,acc2;
        float p,r,t,si,ci;
    public:
        void getdata(float,float,float);
        void calc(float,float);
        void calc(float,float,float);
        void showdata();
};

void account::getdata(float x,float y,float z)
{   p=x;
    r=y;
    t=z;
}
void account::calc(float y,float z)
{   float x=100;
    si=x*y*z*.01;
}

void account::calc(float x,float y,float z)
{   ci=(x*(pow((1+(y*.01)),z))-x);
}
void account::showdata()
{   cout<<"\nSIMPLE INTEREST : Rs. "<<si;
    cout<<"\nCOMPOUND INTEREST : Rs. "<<ci;
}

int main()
{   account c;
    float pr,ti,ra;
    cout<<"Enter the principal : "; cin>>pr;
    cout<<"Enter the rate : ";  cin>>ra;
    cout<<"Enter the time : "; cin>>ti;
    c.getdata(pr,ra,ti);
    c.calc(ra,ti);
    c.calc(pr,ra,ti);
    c.showdata();
    cout<<endl;
    system("PAUSE");
    return 0;
}
