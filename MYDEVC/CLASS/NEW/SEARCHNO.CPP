#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{   int i,n,j=5,m,l,a,x=0;
    cout<<" enter a 5 digit number ";
    cin>>n;
    cout<<" enter the number to be checked with";
    cin>>l;
    a=n;
    for(i=0;i<j;i++)
    {   m=a%10;
        a=a/10;
        if(m==l)
        {   cout<<l<<" is in "<<(5-i)<<" position";
            x=1;
        }
    }
        if(x!=1)
        cout<<l<<" is not present in "<<n;

    cout<<endl;
    system("PAUSE");
}
