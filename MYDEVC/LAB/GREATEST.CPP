#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n=1,great=0;
    while(n!=0)
    {
        cout<<"Enter a number : "; cin>>n;
        if(n>great)
        {
            great = n;
        }
    }
    cout<<"greatest number is  "<<great;
    cout<<endl;
    system("PAUSE");
    return 0;
}
