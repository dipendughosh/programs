#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void main()
{   int n,m=10;
    cout<<"Enter a number : ";
    cin>>n;
    for (int i=0; i<m; ++i)
    {   cout<<"\n"<<n<<" X ";
        cout<<i+1<<" = "<<n*(i+1);
    }
     getche();
    return 0;
}
