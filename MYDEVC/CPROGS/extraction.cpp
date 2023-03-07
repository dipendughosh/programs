#include <iostream.h>
#include <conio.h>

void main()
{   int extract(int),num;
    cout<<"A number : "; cin>>num;
    extract(num);
    getche();
}

int extract(int p)
{   int q,w;
    do
    {
    q=p%10;
    w=(p-q);
    cout<<"The digit is : "<<q<<endl;
    p=(w/10);
    }while(p>9);
    cout<<"The digit is : "<<p<<endl;
}

