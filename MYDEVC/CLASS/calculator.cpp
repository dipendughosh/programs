// ISC 2003 Q-10 *** Calculator Program ***
#include <iostream.h>
#include <conio.h>

class calculator
{   float result;
    public:
        calculator() { result = 0.0; }
        void enterfirst(int x)
            {   result = x; }
        void showresult()
            {   cout<<"\nAt present the result is : "<<result; }
        void add(int x) {   result += x; }
        void sub(int x) {   result -= x; }
        void multiply(int x) {   result *= x; }
        void divide(int x)
        {   while(x==0)
            {   cout<<"\nWrong choice... Enter new no. : ";
                cin>>x;
            }
           result /= x;
        }
        void clear();
};
void calculator::clear()
{   result = 0.0; }

int main()
{   calculator number;
    char choice ;
    int n,num;
    cout<<"\nnumber ? "; cin>>num;
    number.enterfirst(num);
    cout<<"\nSecond No. ? "; cin>>n;
    cout<<"\n\n\t'a' for Addition"
        <<"\n\t's' for Subtraction"
        <<"\n\t'm' for Multiplication"
        <<"\n\t'd' for Division"
        <<"\n\t'c' to clear the value"
        <<"\nEnter your choice ";
    switch(getche(choice))
    {   case 'a': number.add(n); break;
        case 's': number.sub(n); break;
        case 'm': number.multiply(n); break;
        case 'd': number.divide(n); break;
        case 'c': number.clear(); break;
        default: cout<<"\nWrong choice\n";
    }
    number.showresult();
    getche();
    return 0;
}

int newnum()
{   int num;
    cout<<"\nnumber ? "; cin>>num;
    return num;
}
