#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int l =9;
    cout<<l<<endl;
    l = l-3;
    cout<<l+1<<endl<<l-1<<endl;
    l =l-3;
    cout<<l<< endl;
    getche();
    cout<<"\n loop begins...\n";
    for(int l = 9;l>=3;l-= 2)
         cout<<"\n"<<l;
    cout<<endl;
    system("PAUSE");
    return 0;
}
