#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int n,x=2,r,c,i,j=0;
    cout<<"Enter the value of n : ";  cin>>n;
    /*r=n;  c=40-n;
    for (int i=1;i<=n;i++)
    {   gotoxy(c,r);
        cout<<i;*/
    int a[100];
    for (i=1;i<=n;i++)
        a[j++]=i;
    for (i=n-1;i>=1;i--)
        a[j++]=i;
    cout<<endl;
    for (i=0;i<(2*n-1);i++)
        cout<<a[i]<<' ';
    cout<<endl;
//  cout<<"'''";



    cout<<endl;
    system("PAUSE");
    return 0;
}
