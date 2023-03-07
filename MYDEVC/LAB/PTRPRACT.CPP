// Swapping values through pointer & reference
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>


int main()
{   int x=10,y=5;
    void swapstar(int*,int*);
    void swapamp(int&,int&);
    cout<<"Initial values\n x = "<<x<<" : y = "<<y;
    cout<<endl;
    swapstar(&x,&y);
    cout<<"\n x = "<<x<<" : y = "<<y;
    cout<<"\nNow, the values are swapped\n";
    swapamp(x,y);
    cout<<"\n x = "<<x<<" : y = "<<y<<"\nReswapped!";
    getche();
    return 0;
}

void swapstar(int* a,int* b)
{   int temp;
    temp=*a;*a=*b;*b=temp;
    cout<<"\n a = "<<*a<<" : b = "<<*b<<" ... in star**";
}

void swapamp(int& a,int& b)
{   int temp;
    temp=a;a=b;b=temp;
    cout<<"\n a = "<<a<<" : b = "<<b<<" ... in amp&&";
}
