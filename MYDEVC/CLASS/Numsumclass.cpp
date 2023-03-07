#include <iostream.h>
#include <conio.h>

class number
{   int num,n[10];
    public:
        int count(int num);
};
number digits;

int number::count(int num)
{   int ns = 0; int i = 1;
    do
    {   n[i] = num%10;
        ns = ns + n[i];
        num = (num - n[i++])/10;
    }while(num);
    cout<<"Intermediate sum : "<<ns<<endl;
    return(ns);
}

int main()
{   int no;
    int i = 1,numsum;
    cout<<"Enter a number : "; cin>>no;
    while (no>10)
    {   no = digits.count(no); }
        cout<<"\n Numsum : "<<no;
    getche();
    return 0;
}
