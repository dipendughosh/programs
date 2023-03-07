#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a,b,c,n,m,i,d;
    cout<<"1st number ";
    cin>>a;
    cout<<"\n2st number ";
    cin>>b;
    cout<<"\n3st number ";
    cin>>c;
    for(i=0;i<3;i++)
    {   n=(a*100)+(b*10)+(c);
        m=(a*10)+(b*100)+(c);
        cout<<n<<"\n"<<m<<"\n";
        d=a;
        a=b;
        b=c;
        c=d;
     }
    cout<<endl;
    system("PAUSE");
    return 0;
}
