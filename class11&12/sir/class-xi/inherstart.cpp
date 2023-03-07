#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class abc
{   int a,b;
    private:
    void getdata()
    {   cout<<"Enter value for a : "; cin >> a;
        cout<<"Enter value for b : "; cin >> b;
    }
};

class xyz : private abc
{   int x,y,z;
    public:
    void getdata()
    {   abc::getdata();
        cout<<"\nEnter value for x : "; cin >> x;
        cout<<"Enter value for y : "; cin >> y;
    }
    void adddata()
    {   z = abc::a + abc::b + x + y;
    }
    void showdata()
    {   cout<<"\nAdded value : "<< z;
    }
};

int main()
{
    xyz obj;
    obj.getdata();
    obj.adddata();
    obj.showdata();
    cout<<endl;
    system("PAUSE");
    return 0;
}
