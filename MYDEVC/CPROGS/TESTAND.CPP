#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{   int n=4;
    int& var=n;
    int p = n;
    cout<<"n = "<<n<<"\tvar = "<<var<<"\tp = "<<p;
    n+=8;
    cout<<"\nn = "<<n<<"\tvar = "<<var<<"\tp = "<<p;
  getche();
    return 0;
}
