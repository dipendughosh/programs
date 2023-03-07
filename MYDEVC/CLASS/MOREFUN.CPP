#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class a;
class b
{       int x,y,z;
    public:
        void getdata()
        {   cout<<"Enter X .."; cin>>x;
            cout<<"Enter Y ..";  cin>>y;
        }
        void calc()
        {   z=x+y;
        }
    friend void showdata(a,b);
};

class a
{       int j,k,l;
    public:
        void getdata()
        {   cout<<"Enter A .."; cin>>j;
            cout<<"Enter B .."; cin>>k;
        }
        void calc()
        {   l=j+k;
        }
};

void showdata(a d,b e)
{   cout<<"\nRESULT OF CLASS 'A' IS C = A + B = "<<d.l;
    cout<<"\nRESULT OF CLASS 'B' IS L = J + K = "<<e.z;
    cout<<"\nON ADDING THE RESULTS OF THE TWO CLASSES WE GET "<<d.l+e.z;
}


int main()
{   a c1;
    b c2;
    c1.getdata();
    c1.calc();
    c2.getdata();
    c2.calc();
    showdata(c1,c2);
    cout<<endl;
    system("PAUSE");
    return 0;
}
