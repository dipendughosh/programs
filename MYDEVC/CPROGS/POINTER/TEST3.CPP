#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a[5]={1,2,3,5,6};
    for(int i=0;i<5;i++)
        cout<<*(a+i)<<"  ";
    cout<<endl;
    system("PAUSE");
    return 0;
}
