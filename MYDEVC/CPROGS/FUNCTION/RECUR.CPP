#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{   void rec(int);
    int a = 0;
    rec(a);
    cout<<endl;
    system("PAUSE");
    //return 0;
}

void rec(int i)
{   cout<<i++<<"\t";
    if(i < 20) rec(i);
}
