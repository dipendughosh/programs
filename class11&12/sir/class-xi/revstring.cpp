#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
/*FORMULA
  a[i]=a[i]-a[j]
  a[j]=a[i]+a[j]
  a[i]=a[j]-a[i]
*/

int main()
{   char a[2][10];
    int l,j,k;
    char ch;
    cout<<"Enter Two strings :\n";
    for (int i=0;i<2;i++)
        gets(a[i]);
    cout<<endl;
    for (int i=0;i<2;i++)
    {   l=strlen(a[i]);
        for (j=0,k=l-1;j<l/2;j++,k--)
        {   ch=a[i][j];
            a[i][j]=a[i][k];
            a[i][k]=ch;
        }
    }
    for (int i=0;i<2;i++)
        puts(a[i]);
    cout<<endl;
    system("PAUSE");
    return 0;
}
