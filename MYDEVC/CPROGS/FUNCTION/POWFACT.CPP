//sum = x - x^3/3! + x^5/5! - x^7/7! ... x^n/n!
#include <iostream.h>
#include <conio.h>

float fact(float a)
{   float f = 1;
    while(a) f*=a--;
    return f;
}

float powr(float b,float c)
{   float p=1;
    for (float z=1; z<=c; z++) p*=b;
    return p;
}

int main()
{   float s=0,x,n,pp,ff;
    float ismin = -1;
    cout<<"\nEnter 2 numbers : \n";
    cin>>x>>n;
    for (float k=1; k<=n; k+=2)
    {   ismin *= (-1);
        pp = powr(x,k);
        ff = fact(k);
        s += ((pp/ff)*ismin);
        //cout<<" s = "<<s<<"\n";
        getche();
    }
    cout<<"\nThe result is "<<s;
    getche();
    return 0;
}
