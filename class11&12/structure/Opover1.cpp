#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

struct complex
{      double real,image;
};

complex operator +(complex,complex);

void main()
{   clrscr();
    complex a,b,c;
    a.real=1.0;
    a.image=1.0;
    b.real=2.0;
    b.image=2.0;
    c=a+b;
    cout<<"\n"<<c.real<<"+"<<c.image;
    //cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
    getche();
}

complex operator +(complex e1,complex e2)
{   complex temp;
    temp.real=e1.real+e2.real;
    temp.image=e1.image+e2.image;
    return temp;
}





























































































































