#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main()
{   long a,b;
    int c,i = 0,j,n = 0;
    cout<<"Enter a Binary number ";
    cin>>b;
    a=b;
    do
    {   a=a/10;
        i++;
    }while(a!=0);
    a = b;
    for(j=0;j<i;j++)
    {   c=a % 10;
        a=a / 10;
        n=n + (pow(2,j)*c);
    }
    cout<<" Binary = "<<b;
    cout<<"\n Decimal = "<<n;
        cout<<endl;
    system("PAUSE");
    return 0;
}
