#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class test
{   private:
        int a,b,sum;
    public:
        void getdata();
        void showdata();
        int calcdata();
}
obj1,obj2;

void test::getdata()
{
    cout<<"\nEnter a number       : "; cin>>a;
    cout<<"Enter another number : "; cin>>b;
}

void test::showdata()
{   cout<<"\nThe sum is : "<<sum; }

int test::calcdata()
{   sum = a + b;
    return sum;
}

int main()
{   //test obj;
    int p1,p2;
    obj1.getdata();
    p1 = obj1.calcdata();
    obj1.showdata();
    obj2.getdata();
    p2 = obj2.calcdata();
    obj2.showdata();
    cout<<"\nThe sum is : "<<p1+p2;
    cout<<endl;
    system("PAUSE");
    return 0;
}


