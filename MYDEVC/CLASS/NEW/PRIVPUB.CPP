#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int x = 2, y = 3;
int abc(int);
int main()
{   int x = 20, y = 30;
    int abc(int,int);
    cout<<"Output of def :\n";
    cout<<abc(x,y);
    cout<<"\nOutput of abc :\n";
    //cout<<abc(x);
    cout<<endl;
    cout<<x<<" "<<y;
    system("PAUSE");
    return 0;
}

int abc(int p)
{   return (p);   }

int abc(int p, int q)
{   cout<<x<<" "<<y<<endl;
    cout<<"*** "<<abc(p);
     return (p+q);   }


