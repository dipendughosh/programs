#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   void recur(int);
    int a = 6;
    recur(a);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void recur(int x)
{   cout<<x++<<"\t";
    if(x < 20) recur(x);
}
