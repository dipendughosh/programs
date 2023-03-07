// 2-D Array

#include <iostream.h>
#include <conio.h>
const int m=10;
void main()
{
    int a[m][m],n;
    void accept(int a[m][m],int);
    cout<<"enter the size ";
    cin>>n;
    void show(int a[m][m],int);
    accept(a,n); show(a,n);

    getche();
}
 void accept( int a[m][m],int p)
 {  int d=1 ;
    for(int i=0;i<p;i++)
      { for(int j=0;j<p;j++)
         a[i][j]=d++;
      }
 }
 void show( int a[m][m],int n)
 {
    for(int i=0;i<n;i++)
      { for(int j=0;j<n;j++)
         cout<<a[i][j]<<"\t";
         cout<<"\n\n";
      }
 }


