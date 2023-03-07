#include <iostream.h>
#include <conio.h>

void main()
{   int sum=0,i=0;
    while(sum<=100)
    {   cout<<i<<"\t"<<sum<<endl;
        sum += i+=2;
    }
    cout<<i<<"\t"<<sum;
    getche();
}
