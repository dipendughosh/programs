#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int change(int&,int&);
    int a = 4,b = 5;
    cout<<a<<"\t"<<&a;
    cout<<"\n"<<b<<"\t"<<&b;

    cout<<"\na = "<<a<<" b = "<<b;
    change(a,b);
    cout<<"\n\nIn main After swapping...........";
    cout<<"\na = "<<a<<" b = "<<b;
    cout<<endl;
    system("PAUSE");
    return 0;
}

int change(int& x,int& y)
{   int temp;
    temp = x;
    x = y;
    y = temp;
    /*x += y;
    y -= x;
    x -= y;*/
    cout<<"\n\nIn function x = "<<x<<" y = "<<y;
    return (x,y);
}
