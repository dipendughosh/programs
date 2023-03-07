#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int x[10]={1,2,3,4,5,6,7,8,9,0};
    int i,a,b,c;
    cout<<"Enter first value : ";  cin>>a;
    cout<<"Enter second value : ";  cin>>b;
    cout<<"Enter third value : ";  cin>>c;
    for(i=0;i<7;i++)
    {   if (x[i]==a)
        {   if (x[i+1]==b)
            {   for (int j=9;j>=i+2;j--)
                    a[j]=a[j-1];
                a[i+1]=c;
                break;
            }
        }

    }
    for (i=0;i<10;i++)
       cout<<x[i]<<"  ";
    cout<<endl;
    system("PAUSE");
    return 0;
}
