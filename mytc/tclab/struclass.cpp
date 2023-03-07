#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct date
{   int day, month, year;   };

class difage
{   date now; int days;
    public:
    difage(){}
    void getdates()
    {   cout<<"\nday : "; cin>>now.day;
        cout<<"month : "; cin>>now.month;
    }
    int conv()
    {   days = now.month * 30 + now.day;
        return days;
    }
};
int main()
{   difage obj1,obj2;
    int diff;
    obj1.getdates();
    obj2.getdates();
    diff = obj1.conv() - obj2.conv();
    cout<<"\nDifference is : "<<diff;
    cout<<endl;
    system("PAUSE");
    return 0;
}
