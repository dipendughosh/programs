#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int x=3,y=4;
    int *p1,*p2;
    int arr[4]={4,5,6,7};
    void swap(int *,int *);
    for(int i=0;i<4;i++)
    {   cout<<*(arr+i)<<"\t";
        //cout<<"\n arr()"<<i<<arr[i];
    }
    getche();
    /*cout<<"X--"<<x<<"\nY--"<<y<<endl;
    cout<<"\nx-->"<<x<<endl;
    cout<<"\ny-->"<<y<<endl;
    cout<<endl;
    swap(&x,&y);
    cout<<"\nx-->"<<x<<endl;
    cout<<"\ny-->"<<y<<endl;
    p1=&x;
    p2=&y;
    cout<<"\nx-->"<<&x<<endl;
    cout<<"\ny-->"<<&y<<endl;
    /*cout<<"\nPointer P1-->"<<p1;
    cout<<"\nPointer p2-->"<<p2<<endl;
    p1++;
    cout<<"\nPointer P1-->"<<*p1;
    cout<<"\nPointer p2-->"<<*p2<<endl;*/
    system("PAUSE");
    return 0;
}
void swap(int *a,int *b)
{
    cout<<"\na-->"<<a<<endl;
    cout<<"\nb-->"<<b<<endl;
    getche();
    int temp=*a;
    *a=*b;
    *b=temp;
}

