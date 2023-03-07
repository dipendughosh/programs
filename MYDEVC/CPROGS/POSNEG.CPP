//1. Even/Odd  2. Neg/Pos ------> Sum
//2.              Neg./Pos -----> how many
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int n, even = 0, odd = 0, pos = 0, neg = 0;
    int negsum = 0, possum = 0;
    do
    {   cout<<"Enter an Integer : "; cin>>n;
        if(n%2) even+=n;
        else odd+=n;
        if(n<0)
        {   negsum += n;
            neg++;
        }
        else
        {   possum += n;
            pos++;
        }
    }
    while(n!=0);
    cout<<"\nEven sum  : " <<even;
    cout<<"\nOdd sum  : " <<odd;
    cout<<"\nNegnsum  : " <<negsum<<"\t"<<neg;
    cout<<"\npossum  : " <<possum<<"\t"<<pos;

    cout<<endl;
    system("PAUSE");
    return 0;
}
