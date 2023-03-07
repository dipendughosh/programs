#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class abc
{   int a,b;
    public:
    void getdata()
    {
        cout<<"Enter value for a : "; cin>>a;
        cout<<"Enter value for b : "; cin>>b;
    }
};
class xyz : public abc
{   int x,y,z;
    public:
    void getdata()
    {
        abc::getdata();
        cout<<"\nEnter value for x : "; cin>>x;
        cout<<"Enter value for y : "; cin>>y;
    }
    void addata()
    {
        z = abc::a + abc::b + x + y;
    }
    void showdata()
    {   cout<<"\nz is : "<<z;
    }
};
int main()
{
    xyz obj;
    obj.getdata();
    obj.addata();
    obj.showdata();
    cout<<endl;
    system("PAUSE");
    return 0;
}
