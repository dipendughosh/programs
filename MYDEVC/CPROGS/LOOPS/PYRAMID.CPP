// Number Pyramid
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>     // for setw

int main()
{   int n = 7,i,j,x,y;
    for (int i = n; i > 0; i--)
    {   for (int j = i; j > 0; j--) cout<<"   ";

        x = n-i; y = x;

        while (x>=0) cout<<setw(3)<<x--;

        x=1;
        while (x <= y) cout<<setw(3)<<x++;

        cout<<endl;
    }
    getche();
    return 0;
}








