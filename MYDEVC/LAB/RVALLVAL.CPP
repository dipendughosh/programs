#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int i = 1;
    int j = i;
    cout<<"\ni = "<<i<<" and j = "<<j;
    i = 2;
    cout<<"\ni = "<<i<<" and j = "<<j;
    int& p = i;
    //cout<<"\ni = "<<i<<" and &p = "<<&p;
    j = p;
    cout<<"\ni = "<<i<<" and j = "<<j;
    cout<<endl;
    system("PAUSE");
    return 0;
}
