#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int prime(int);
int main()
{   int a,b;
    int nonfibo(int,int);

    cout<<"\nEnter starting number:";
    cin>>a;
    cout<<"\nEnding number:";
    cin>>b;
    nonfibo(a,b);
    cout<<endl;
    system("PAUSE");
    return 0;
}

int nonfibo(int a1,int b1)
{   int a=0,b=1,x,j,i,c,p,q;

    for(i=0;i<=b1;i++)
    {   p=b;
        q=a;
        c=a+b;
        a=b;
        b=c;
        cout<<b<<" "<<a<<"\n";
        if(c>=a1)
        {   for(j=a;j<b;j++)
            {   if(c>=a1)
                {   x=prime(j);
                    if(x==1)
                    {   cout<<j<<"\n";
                    }
                }
            }
        }
    }
}

int prime(int p)
{   int d=0;
    for(int i=1;i<=p;i++)
        if (p%i==0)
            d+=1;
    if (d==2)
         return 1;
    else
         return 0;
}
