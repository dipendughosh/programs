#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
//class sorrow;
class fun
{       int a,b,c;
    public:
        void getdata()
        {   cout<<"Enter A .."; cin>>a;
            cout<<"Enter B ..";  cin>>b;
        }
        void calc()
        {   //int c;
            c=a+b;
            //return c;
        }
    friend void showdata(fun);
};

void showdata(fun d,int p)
{   cout<<"\nc = a + b = "<<d.c;
    cout<<"\nc + 7 = "<<d.c+7;
}


int main()
{   int x=7;
    fun f;
    f.getdata();
    f.calc();
    showdata(f,x);
    cout<<endl;
    system("PAUSE");
    return 0;
}
