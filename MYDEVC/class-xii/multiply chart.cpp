#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
void main()
{  int a[10][10];
   /*int m,count=1;
   for(int m=0;m<5;m++)
   {    a[0][m]=count;
        a[m][0]=count;
        count++;
   }
   for (int i=1;i<5;i++)
   { for (int j=1;j<5;j++)
     {  a[i][j]=a[i][0]*a[0][j];}
   }*/
   for( int i=0;i<5;i++)
   { for(int j=0;j<5;j++)
         {a[i][j]=(i+1)*(j+1);
         }
   }
   for( int i=0;i<5;i++)
   { for(int j=0;j<5;j++)
        {cout<<a[i][j]<<"\t";
        }
     cout<<endl;
   }
   cout<<endl;
    system("PAUSE");
}
