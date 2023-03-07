#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int intvar = 44;
    float flotvar = 44.04;
    void *ptrvoid;
    ptrvoid = &intvar;
    //cout<<"\n"<<*ptrvoid;
    ptrvoid = &flotvar;
    //cout<<"\n"<<*ptrvoid = &intvar;
    cout<<endl;
    system("PAUSE");
    return 0;
}
