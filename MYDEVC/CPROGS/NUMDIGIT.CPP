// 2 check
#include <iostream.h>
#include <conio.h>

void main()
{   int n1,n2,arr1[10];//,arr2[10];
    cout<<"\nFirst number  : "; cin>>n1;
    //cout<<"\nSecond number : "; cin>>n2;
    arr1[0] = NULL;
    int p = 1;
    while(n1>9)
    {   arr1[p] = n1%10;
        n1 = (n1 - arr1[p])/10;
        p++;
    }
    arr1[p] = n1;
    cout<<endl;
    for(int i = p; i>0; i--) cout<<arr1[i]<<",";

    getche();
}


