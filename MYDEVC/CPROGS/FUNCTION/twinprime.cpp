#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a,b;
    int prime(int);
    cout<<"\nEnter range..  ";cin>>a>>b;
    if(a%2==0)
        a=a+1;
/*    if(a<=b)
    {   max=b;
        min=a;
    }
    else
    {   max=b;
        min=a;
    }
    */
    for(int i=a;i<=b;i+=2)
    {
        if (prime(i)==1)
            if ((prime(i+2)==1)&&((i+2)<=b))
                cout<<i<<"\t"<<i+2<<"\n";
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
int prime(int p)
{   int d=0;
    for(int i=1;i<=p;i++)
        if (p%i==0)
            d+=1;
    if (d==2)
         return 1;
    else
         return 0;
}
