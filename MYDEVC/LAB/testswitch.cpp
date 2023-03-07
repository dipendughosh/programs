
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int choice;
    float a,b,result;
    do
    {cout<<"please enter First number ";  cin>>a;
    cout<<"please enter Second number "; cin>>b;
    cout<<"\n\tM E N U";
    cout<<"\n\t1. Sum";
    cout<<"\n\t2. Difference";
    cout<<"\n\t3. Product";
    cout<<"\n\t4. Quotient";
    cout<<"\n\t0. Exit";
    cout<<"\n\nEnter your choice : ";  cin>>choice;
    switch(choice)
    {   case 1:
            result = a + b;
            cout<<"\nSum is "<<result;
            break;
        case 2:
            result = (a>b ? a-b : b-a);
            cout<<"\nDifference is "<<result;
            break;
        case 3:
            result = a * b;
            cout<<"\nProduct is "<<result;
            break;
        case 4:
            result = a / b;
            cout<<"Quotient is "<<result;
            break;
        case 0:
            break;
        default :cout<<"no such option in menu";
    }
    }while(choice!=0);
    cout<<endl;
    system("PAUSE");
    return 0;
}
