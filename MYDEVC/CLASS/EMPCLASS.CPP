#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

class employee
{   private :
        int empno;
        int basic;
        int gross;
    public :
        char name[20];
        int g;
        void getbasic()
        {   cout<<"\nEmployee No. : "; cin>>empno;
            cout<<"\nBasic Pay    : "; cin>>basic;
            gross = basic+basic * .62;
            g = gross;//cout<<"\nGross Pay     : "<<gross;
        }
};

int main()
{   employee emp[4];
    for ( int i = 0; i < 4; i++ )
    {   emp[i].getbasic();
        cout<<"\nName         : "; cin.get(emp[i].name);
        //emp[i].g =
        cout<<endl;
    }
    getche();
    return 0;
}
