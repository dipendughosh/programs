#include <iostream.h>
#include <stdlib.h>
#include <conio.h>


int fact(int x)
{   int s=1;
    for(int i=1;i<=x;i++)
    {   s*=i;
    }
    return s;
}
void perm(int n,int r)
{   int x=fact(n)/fact(n-r);
    cout<<"\nPermutation is->"<<x;
}


int main()
{   int x,y,n,r;
    cout<<"\nEnter n:";
    cin>>x;
    cout<<"\nEnter r:";
    cin>>y;
    if(x>y)
    {   n=x;
        r=y;
    }
    else
    {   n=y;
        r=x;
    }
    perm(n,r);

    cout<<endl;
    system("PAUSE");
    return 0;
}
