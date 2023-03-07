#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class test
{
    int a,b,d;
    public:
    test()                     // Constructor
    {
        cout<<"This is a sample programme\n";
    }
    void getdata()
    {
        cin>>a;
        cin>>b;
    }
    void sumdata()
    {
       d = a + b;
    }
    void showres()
    {
        cout<<"\nd = "<<d;
    }
};

int main()
{   test t;
    t.getdata();
    t.sumdata();
    t.showres();
    cout<<endl;
    system("PAUSE");
    return 0;
}
