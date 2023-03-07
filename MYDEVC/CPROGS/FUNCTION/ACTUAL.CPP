#include <iostream.h>
#include <conio.h>

int main()
{
    int a,b;
    int p;
    void prod(int,int);
    cout<<"two nos : ";cin >>a>>b;
    p=a*b;
    cout<<"\nproduct in main ===> "<<p ;
    prod(a,b);
    getche();
    return 0;
}

void prod(int m,int n )
{
  int pro=n*m;
  cout<<"\nproduct in function ...> "<<pro;
}
