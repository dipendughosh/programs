#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
void main()
{   int a,b;
    void calc(int,int);         // declaration of function
    cout<<"Enter value for a : "; cin>>a;
    cout<<"Enter value for b : "; cin>>b;
    calc(a,b);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void calc(int p, int q)
{   int c;
    if( p > q ) c = p - q;
    else c = q - p;
    cout<<"\nSubs of a and b is : "<<c;
    cout<<"\nAddn of a and b is : "<<p+q;
}
