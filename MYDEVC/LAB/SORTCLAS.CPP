#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class num
{   int n,p;
    public:
    void getdata();
    void showdata();
    friend void arrange(num&,num&);
};
void num::getdata()
{   cout<<"\n\nNumber : "; cin>>n;
    cout<<"\nPosition : "; cin>>p;
}
void num::showdata()
{   cout<<"\n\nNumber : "<<n;
    cout<<"\tPosition : "<<p;
}
int main()
{   num number[3]; int i,j;
    //void arrange(num&,num&);
    for(i=0; i<3; i++) number[i].getdata();
    for(i=0; i<3; i++) number[i].showdata();
    cout<<"\n\nAfter Arrangement : ";
    for(i=0; i<2; i++)
        for(j=i+1; j<3; j++) arrange(number[i],number[j]);
    for(i=0; i<3; i++) number[i].showdata();
    getche();
    return 0;
}
void arrange(num& p,num& q)
{   num temp;
    if (p.n>q.n)
    {   temp=p; p=q; q=temp;
    }
}
