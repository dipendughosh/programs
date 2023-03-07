#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

class bank
{   private:
        char name[51];
        float bal;
        float interest;
        int accno;
    public:
        bank();
        void show();
        void withdrawal();
        void deposit();
};

bank::bank()
{   cout<<"\nEnter your name ==> "; gets(name);
    interest=5.0;
    accno=300;
    bal=500;
}

void bank::deposit()
{   float d;
    cout<<"\nEnter the amount to be deposited ==> ";
    cin>>d;
    bal+=d;
}

void bank::withdrawal()
{   float w;
    cout<<"\nEnter the amount to be withdrawn  ==> ";
    cin>>w;
    bal-=w;
}

void bank::show()
{   cout<<"\t\t\tACCOUNT DETAILS\n\n";
    cout<<"Name : ";  puts(name);
    cout<<"\nAccount number : "<<accno;
    cout<<"\nExisting Balance : Rs. "<<bal;
    cout<<"\nRate of Interest : "<<interest<<"%";
}


int main()
{   bank subscriber;
    char z;
    cout<<"Type 'w' for Withdrawal and 'd' for Deposits.\n";
    cin>>z;
    if (z == 'd')  subscriber.deposit();
    else subscriber.withdrawal();
    subscriber.show();
    cout<<endl;
    system("PAUSE");
    return 0;
}
