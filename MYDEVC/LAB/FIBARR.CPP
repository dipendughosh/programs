#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int fibo(int,int);
    void print(int[4][4]);
    int z[4][4],d,k=0,l=1,temp;
    for (int q=0;q<4;q++)
    {   for (int w=0;w<4;w++)
            {
            z[q][w]=l;
            d=fibo(k,l);
            temp=k;
            k=l;
            l=d;
            }
    }
    print(z);
    cout<<endl;
    system("PAUSE");
    return 0;
}

int fibo(int p,int q)
{   int r;
    r=p+q;
    return r;
}

void print (int p[4][4])
{    for (int x=0;x<4;x++)
         {    for (int c=0;c<4;c++)
                  cout<<"\t"<<p[x][c];
              cout<<endl;
         }

}

