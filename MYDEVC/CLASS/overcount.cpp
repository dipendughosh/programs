#include <iostream.h>
#include <conio.h>

class counter
{   int count;
    public:
        counter() { count = 0;  }
        int showcount() {   return count;   }
        void incrount() {   count++;    }
};
void main()
{   counter c1,c2;
    for(int i=0; i<10; i++)
    {   cout<<"\nc1 "<<c1.showcount();
        cout<<"\tc2 "<<c2.showcount();
        c1.incrount();
        c2.incrount();
    }
    getche();
}
