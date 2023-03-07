// 1 + x^2/2! + x^4/4! + x^6/6! .....x^(<=n)/(<=n)!
#include <iostream.h>
#include <conio.h>
#include <math.h>
void main()
{   float fact(int),s=0.0,m; int x,n;
    cout<<"\nA number : "; cin>>n;
    cout<<"\nAnother  : "; cin>>x;
    for (int i = 0; i<n; i+=2)
    {
        cout<<x<<"^"<<i<<"/"<<i<<"!\t";
        s += (pow(x,i))/fact(i);
        cout<<s<<endl;
    }
    cout<<"The sum is : "<<s;
    getche();
}

float fact(int p)
{   float f = 1;
    while(p) f *= p--;
    return f;
}






