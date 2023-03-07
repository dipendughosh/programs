#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class cc
{
    static int n;
    public:

        cc(){ n++;}
        int getdata()
        {   return n; }

};

int main()
{   cc a,b,c;
    cout<<"a = "<<a.getdata();
    cout<<"\nb = "<<b.getdata();
    cout<<"\nc = "<<c.getdata();
    cout<<endl;
    system("PAUSE");
    return 0;
}
