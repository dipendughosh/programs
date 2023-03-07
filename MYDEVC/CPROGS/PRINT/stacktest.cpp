#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class stack
{     int st[5],top;
      public:
      stack() {    top = 0;    }
      void getdata(int var)
      {   st[++top] = var;     }
      int showdata()
      {   return st[top--];    }
};

int main()
{   int pile[5],t = 0, val = 11;
    while (t<5) pile[t++] = val++;
    cout<<"\nResult of Pile in array :\n";
    for (int i = 0; i < 5; i++) cout<<pile[i]<<endl;
    getche();

    stack s1;
    t = 0, val = 11;
    while (t++<5)
    {   s1.getdata(val++);
        t++;
    }
    cout<<"\n\nResult of Stack :\n";
    for (int i = 0; i < 3; i++)
        cout<<s1.showdata()<<endl;
    cout<<endl;
     system("PAUSE");
     return 0;
}
