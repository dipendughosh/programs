//not working
#include <iostream.h>
#include <conio.h>

void main()
{
    int a,b,i,j,c,count (int ,int );
    cout<<" enter range "; cin>>a>>b;
    for(int i=a;i<b;i ++)
    {   for(int j=a+1;j<=b;j++)
        {   if (i==j ||j<i)   continue;
            c=count(i,j);
            if (c==2)
                {   cout<<"\n twin prime : "<<i<<"    "<<j;
                    break;
                 }
        }
     }
    getche();
}
int count (int a,int b)
{   int add, checkprime(int);
    add=checkprime(a)+checkprime(b);
    return add;
}
int checkprime(int a)
{   int flag=1;
    for(int i=2;i<=a/2;i++)
    {   if (a%i==0)
        {   flag=0; break;
        }
    }
    return flag;
}
