#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n1,n2,x,a,b,lcm,i,p;
    cout<<"\nEnter 1st number:";
    cin>>n1;
    cout<<"\nEnter 2nd number:";
    cin>>n2;
    if(n1>=n2)
        x=n2;
    else
        x=n1;
    p=n1*n2;
    for(i=x;i<=p;i++)
    {   a=i%n1;
        b=i%n2;
        if(a==0 && b==0)
        {   lcm=i;
            break;

        }
    }
    cout<<"\nL.C.M. is ->"<<lcm;

    cout<<endl;
    system("PAUSE");
    return 0;
}
