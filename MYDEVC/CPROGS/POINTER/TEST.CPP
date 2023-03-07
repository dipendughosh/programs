#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int *p1,*p2;
    int x=10;
    p1=&x;
    cout<<"p1 : "<<p1<<"  *p1 : "<<*p1;
    (*p1)+=3;
    int y=*p1;
    cout<<"\ny : "<<y;
    (*p1)++;
    cout<<" *p1++ : "<<*p1;
    ++*p1;
    cout<<" ++*p1  "<<*p1;
    cout<<"\ny : "<<y;
    y=*p1;  cout<<"\ny : "<<y;

    p2=p1;
    cout<<"   *p1 : "<<*p1<<"  *p2 : "<<*p2;
    cout<<endl;
    system("PAUSE");
    return 0;
}
