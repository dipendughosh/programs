#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
    int i,j,k,l,m =39,h;
    for(i=1;i<=5;i++)
    {
        k =1;
        for(h=1;h<=m;h++)
        {
            cout<<" ";
        }
        for(j=0;j<i;j++)
        {
            cout<<k;
            k++;
        }
        k-=2;
        for(l=1;l< i;l++)
        {
            cout<<k;
            k--;
        }
        cout<<"\n";
        m--;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
