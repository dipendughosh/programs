// number-combination
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int swap(int &x,int &y)
{   int z=x; x=y ; y=z;
    return(x,y);
}

void display(int n[],int s)
{   for (int t=0; t<s; t++) cout<<n[t];
    cout<<endl;
    getche();
}

int fact(int no)
{   int f=1;
    for (int g=no; g>1; g--) f*=g;
    return f;
}

int main()
{   int num[30],n,p=0,q=1,i=0,v=0;
    cout<<"Enter a number : "; cin>>n;
    while(n>0)
    {   num[i++]=n%10 ; n/=10;
    }
    display(num,i); cout<<endl;
    getche();
    while(v<fact(i))
    {   swap(num[p],num[q]);
        display(num,i);
        q = q<i-1 ? q+=1 : 1; // if (q=i-1) q=1 ;//q+=1; else q=1;
        p = p<i-2 ? p+=1 : 0; // if (p=i-2) p=0 ;//p+=1; else p=0;
        v++;
    }

    getche();
    return 0;

}
