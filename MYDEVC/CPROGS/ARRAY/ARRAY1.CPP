#include <iostream.h>
#include <conio.h>
#include<math.h>
#include <stdlib.h>

int main()
{
   int a[5][9],i,j;
   for(i=0;i<5;i++)
   {   for(j=0;j<9;j++)
       {    if ((i+j)==4||(j-i)==4)
                a[i][j]=i;
            else
                a[i][j]=7;
            if(i+j>4)
                a[i][j]=abs(4-j);
            if(j-i>4)
                a[i][j]=7;
       }
   }
   for(i=0;i<5;i++)
   {    cout<<endl;
        for(j=0;j<9;j++)
        {   if(a[i][j]!=7)
                cout <<a[i][j] <<"\t";
            else
                cout<<"\t";
        }
   }
    getche();
    return 0;
}

