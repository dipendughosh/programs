#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int z;
main()
{
    int x;
    int* y;
    int& change(int);
    cout<<"x : "; cin>>x;
    *y = change(x);
    cout<<"\ny = "<<*y;

/*
    cout<<"y : "; cin>>y;
    change(x,y);
    cout<<endl;
    cout<<"\nx : "<<x;
    cout<<"\ny : "<<y;*/
    cout<<endl;
    system("PAUSE");
    //return 0;
}

int& change(int a)
{
    return a;
}
/*    z = a;
    a = b; b= z;
    cout<<"\nx --> "<<a;
    cout<<"\ny --> "<<b;
    getche();
} */
