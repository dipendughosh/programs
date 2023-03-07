#include <iostream.h>
#include <conio.h>

void main()
{   int a[5] = { 1,2,0,0 };
    int i =0;
    for(;i<4;i++) cin>>a[i]; getche() ;
    cout<<a[5]<<endl;
    for(i=0;i<5;) cout<<a[i++];

    /*int swap(int&,int&);
    cout<<"A number : "; cin>>n;
    '\0'
    cin>>b;
    cout<<&a<<"\t"<<a;
    cout<<"\n"<<&b<<"\t"<<b;
    cout<<endl;
    swap(a,b);
    cout<<"in main a = "<<a;
    cout<<"\nin main b = "<<b; */
    getche();
}
/*
int swap(int &p,int &q)
{   cout<<"\n"<<&p<<"\t"<<&q;
    int temp=p; p=q; q=temp;
    cout<<"\nin swap p = "<<p<<"\t"<<q<<endl;
    return p,q;
} */
