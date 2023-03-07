#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
class rows
{   int num[7];
    public:
        void makerow(int);
        void showrow();
};
rows strip[7];

void rows::makerow(int x)
{   for (int p=0; p<7; p++)
    {   if ( p<x ) num[p] = p+1;
        else num[p] = 0;
    }
}

void rows::showrow()
{   for (int p=0; p<7; p++)
    {   if (num[p]>0) cout<<setw(3)<<num[p];
        else cout<< " ";
    }
}

int main()
{   const int r=7;
    for (int i=0; i<r; i++)
        for (int j=0; j<i+1; j++)
            strip[i].makerow(j+1);
    for (int m=0; m<7; m++)
    {   strip[m].showrow();
        cout<<endl;
    }
    getche();
    return 0;
}
