#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a[] = {5,3,4}, test(int[],int),i;
    int b[3];
    for(i = 0; i < 3; i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    b[3] = test(a,3);
    cout<<"After function : "<<endl;
    for(i = 0; i < 3; i++)
        cout<<b[i]<<"\t";
    cout<<endl;
    system("PAUSE");
    return 0;
}

int test(int x[],int y)
{   int p[3],j,m = y;
    for( j = 0 ; j < y; j++)
        p[j] = x[--m];
    cout<<"In function : "<<endl;
    for(j = 0; j < 3; j++)
        cout<<p[j]<<"\t";
    cout<<endl;
    return p[y];
}
