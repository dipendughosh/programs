//sorting giving parse error
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
  //clrscr();
   int i,j,k,size,a[5][5],t;
   cout<<"\n size of array (<5)  ";
   do
   {cin>>size;  size =size-1;
   }while((i>0&&i<5)&&(i == 1));
   for(i=0;i<=size;i++)
   {
   cout<<"enter elements of" <<i+1<<"-th row  ";
   for(j=0;j<=size;j++)
     do
     {
     cin>>a[i][j];
     }
     while(int a[i][j]==a[i][j]);
    }
   cout<<"elements sorted row-wise  ";
          for(i=0;i<=size;i++)
     {
        for(j=0;j<size;j++)
        {
           for(k=j+1;k<=size;k++)
             {
               if (a[i][j]>a[i][k])
               {
                 t=a[i][j];   a[i][j]=a[i][k];  a[i][k]=t;
                }
              }
          }
        }
        for(i=0;i<=size;i++)
        {
        for(j=0;j<=size;j++)
        cout<<endl<<a[i][j];
        }
         getche();
    return 0;
}
