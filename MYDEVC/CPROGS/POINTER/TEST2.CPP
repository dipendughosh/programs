#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int x,y,*xp,temp=3;
    x=5*(temp+5);
    xp=&temp;

    y=5*(*xp+5);
    cout<<"x : "<<x<<"  y : "<<y;
    cout<<endl;
    system("PAUSE");
    return 0;
}
