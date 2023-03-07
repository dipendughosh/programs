#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class test
{   int x,y,z,a,b,c;
    public:
    test(int aa,int bb,int cc)
    {   x=aa;
        y=bb;
        z=cc;
    }
    int getdata(int,int);
    int getdata(int,int,int);
    int getdata(int);
    void showdata(int p)
    {   cout<<p<<"\n";
    }
};

int test::getdata(int a,int b)
{   return (a+b);
}

int test::getdata(int a,int b,int c)
{   return (a+b+c);
}

int test::getdata(int a)
{   return (a);
}

int main()
{   test obj(2,4,6);
    obj.showdata(obj.getdata(obj.x,obj.y));
    obj.showdata(obj.getdata(obj.x,obj.y,obj.z));
    obj.showdata(obj.getdata(obj.x));
    cout<<endl;
    system("PAUSE");
    return 0;
}
