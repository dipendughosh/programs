// Program to find Permutation & Combination
                              NOT checked
#include <iostream.h>
#include <conio.h>

int main()
{   int n,r,per,comb,numer,denom,fact(int,int);
    cout<<"\n\t Permutation & Combination program \n";
    cout<<"Enter no.s :\n ";
    do
    {   cin>>n>>r;
    }  while(n<1 && n>12);// && (int n=n));
    per = fact(n,0)/fact(n,r);
    comb = per/fact(r,0);
    cout<<"\n permutation="<<per ;
    cout<<"\n combination = "<<comb;
       getche();
    return 0;
}

//function
int fact(int a,int b)
{   int sum=1,p;
    p=a-b;
    while(p>1) sum*=p-- ;
    return sum;
}

