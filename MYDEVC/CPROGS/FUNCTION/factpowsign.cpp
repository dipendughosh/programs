#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int main()
{   int factorial(int);
    int t,x,p=1,n;
    float m,q,s;
    cout<<"\n enter x..  ";cin>>x;
    cout<<"\n enter n..  ";cin>>n;
    for(int i=1;i<=n;i++)
    {   t=factorial(i);
        s=pow(x,i);
        m=float(s/t);
        q=q+(m*p);
        p=p*(-1);
     }
     cout<<"\n simplified answer..  "<<q;
     getche();

    cout<<endl;
    system("PAUSE");
    return 0;
}

 int factorial(int y1)
 {  int pt=1;
    for(int j=1;j<=y1;j++)
        pt=pt*j;
    return (pt);
 }

