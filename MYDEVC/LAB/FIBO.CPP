#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int n;
    int fibon(int);
    //clrscr();
    cout<<"\nenter a number";
    cin>>n;
    cout<<"\n"<<fibon(n);
    cout<<endl;
    system("PAUSE");
    return 0;
}
int fibon(int x)
{   int f0=0,f1=1,f2;
    for(int i=1;i<=x;i++)
    {   f2=f0+f1;
        //cout<<"\n"<<f2;
        f0=f1;
        f1=f2;
    }
    return f2;
}

