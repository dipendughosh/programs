#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void main()
{ int swap(int,int);
  int a = 4, b = 6;
  cout << "\n a = " << a << "\tb = " << b;
  swap(a,b);
  cout << "\nIn main()   a = " << a << "\tb = " << b;
  getche();
}

int swap(int x,int y)
{
    int temp = x; x = y; y = temp;
    cout<<"\nIn function x = "<<x<<"\t"<<"y = "<<y;
}
