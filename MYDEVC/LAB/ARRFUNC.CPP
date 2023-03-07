#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{   void setdata(int,int);
    int arr[7]; int p;
    for (p=6;p>=0;p--)
    {   for (int i=0;i<7;i++)
        {    if (i>=6) arr[i]=i;
                else arr[i]=0;
             cout<<arr[i]<<"\n";  }
    }
    for (int j=0;j<7;j++)
        cout<<arr[j]<<"\n";
    getche();
    return 0;
}

void setdata(int a[],x)
{   a[x]=x;}
