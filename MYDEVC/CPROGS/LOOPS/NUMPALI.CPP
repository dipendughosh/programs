#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int n,n2,num,num2 = 0,p = 10;
    //void pal(int);
    cout<<"Enter a number : "; cin>>n;
    if(n < 10)
    {   cout<<"I do not work for a miser! Bye...";
        getche();
        return(0);
    }
    //pal(n);
    n2 = n;
    while(n)
    {   num = n%10;
        n/=10;
        num2 = num2 * p + num;
    }
    cout<<"\nThe reversed number : " << num2;
    getche();
    if(n2 == num2) cout<<"\nPalindrome";
    else cout<<"\nNot Palindrome";
    cout<<endl;
    system("PAUSE");
    return 0;
}

void pal(int n)
{   int r = n,p = 10,total=0,a;
    a = n % 10;
    n/=10;
    while(n)
    {   int t = n % 10;
        total = a * p + t;
        n/=10; a = total;
    }
    if (r == total) cout<<"Pal";
    else cout<<"NOT";
}

