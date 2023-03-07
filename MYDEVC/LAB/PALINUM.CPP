#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int num, b = 0, number;
    cout<<"\nEnter a number : "; cin>> number;
    num = number;
    for(int i = 0; i < 5; i++)
    {
        int n = num % 10;
        //cout<<n<<endl;
        b = b * 10 + n;// cout<<"\t"<<b<<endl;
        num /= 10;
    }
    if(b == number)
        cout<<"This is a Palindrome";
    else
        cout<<"Sorry!";

    cout<<endl;
    system("PAUSE");
    return 0;
}
