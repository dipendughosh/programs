#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

struct num
{   int n[7];
}number[7];

int main()
{   for(int p=0;p<7;p++)
    {   for (int i=0; i<7; i++)
        {   for (int j=0; j<7; j++)
            {   if (j>=p) number[p].n[j]=p;
                else number[p].n[j]=0;
            }
        }
    }
    for (int x=0;x<7;x++)
    {  for(int y=6;y>=0;y--)
            cout<<setw(3)<<number[y].n[x];
       for(int t=1;t<7;t++)
            cout<<setw(3)<<number[t].n[x];
       cout<<endl;
       //getche();
    }
    getche();
    return 0;
}
