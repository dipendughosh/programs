#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int a[10]={8,0,9,3,1,0,2,0,5,5};

int main()
{
    int c=0,i,j;
    void print(int);
    print(10);
    for(i=0;i<10;i++)
    {   if (a[i]==0)
        {   c++;
            for (j=i;j<9;j++)
                a[j]=a[j+1];
        }
    }
    cout<<endl;
    print(10-c);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void print(int p)
{   for (int i=0;i<p;i++)
        cout<<a[i];
}
