#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n;
    double p=0.0;
    cin>>n;
    for(float i=0.0;i<=n;i+=0.01)
    {
        p=(i*i);
        if(p>=n)
        {
            cout<<i-.01;
            cout<<"\nsq is...."<<(i-.01)*(i-.01);
            break;
        }
    }

    cout<<endl;
    system("PAUSE");
    return 0;
}
