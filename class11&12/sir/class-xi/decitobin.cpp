#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int binno[8],decno,i;
    cout<<"Enter a decimal number : ";
    cin>>decno;
    for(i=7;i>=0;i--)
    {   binno[i] = decno%2;
        decno/=2;
    }
    cout<<"\nThe Binary format is :\n";
    for(i=0;i<8;i++) cout<<binno[i]<<" ";
    cout<<endl;
    system("PAUSE");
    return 0;
}
