#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int dist = 1000;
    int ain1hr = 40;
    int distleft = dist - ain1hr;
    double i,j;
    for( i = 40, j = 1000; i <= distleft; i +=.4, j -=.5)
    {   if (i >= j)
        {   cout<<j;
            break;
        }
    }
    cout<<"\ndistance travelled by B to meet : "<<j;
    cout<<"\nTotal travelled by A : "<<i + ain1hr;
    cout<<"\nTime taken by B to meet :"<<j/50;
    cout<<"\ntravelled by B :"<<(i/60) * 50;
    float timeforB = (60/50) * j;
    cout<<"\ntime taken : "<<timeforB;
    cout<<endl;
    system("PAUSE");
    return 0;
}
