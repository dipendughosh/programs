#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a = 45;
    cout<<"Address of a (&a) = "<< &a;
    int *addr = &a;
    cout<<"\n*addr = "<< *addr;
    cout<<"\n&addr = "<< addr;
    *addr += 2;
    cout<<"\n*addr = "<< *addr;
    cout<<"\n&addr = "<< addr;
    cout<<"\na = "<<a;
    cout<<endl;
    system("PAUSE");
    return 0;
}
