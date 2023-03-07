#include <iostream.h>
#include <conio.h>

void main()
{   int a;
    cout<<"Enter a number (5-digit)"; cin>>a;
    void call(int);
    call(a);

}

void call(int p)
{   int z[5],s,q,w,d;
    do
    {   for(s=0;s<5;s++)
        {
        q=p%10;
        w=p-q;
        p=w/10;
        z[s]=q;
        }
    }while(p>9);
    z[s]=q;
    for(d=4;d>=0;d--)
    cout<<"\nThe digits are : "<<z[d];
    getche();
}



