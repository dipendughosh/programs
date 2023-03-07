#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a,b;
    void shownum(int,int), swap(int&,int&);
    cout<<"Enter first number : "; cin>>a;
    cout<<"Enter second number : "; cin>>b;
    shownum(a,b);
    cout<<"\nAfter interchanging the values :\n";
    swap(a,b);
    shownum(a,b);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void shownum(int p, int q)
{   cout<<"\n In the shownum function :";
    cout<<"\na is : "<<p;
    cout<<"\nb is : "<<q;
}
void swap(int& p,int& q)
{   int temp = p;
    p = q;
    q = temp;
    cout<<"\n In the swap function :";
    cout<<"\na is : "<<p;
    cout<<"\nb is : "<<q;
}


