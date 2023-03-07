#include <iostream.h>
#include <conio.h>
#define N 10
int f=1;
void main()
{int a[N][N]={0},n,d=1,s;
   cout<<" enter size : ";
   cin>>n;
   void right(int,int,int a[N][N]),down(int,int,int a[N][N]);
   void left(int,int,int a[N][N]),top(int,int,int a[N][N]);
   void show(int,int a[N][N]);
    int i=0,j=0,k;
    for(j=0,s=n;j<n;j++,s--)
     {for( i=0,k=n;i<n;i++,k--)
      {right(j,i,a);
      cout<<j<<"\t i"<<i;getche();
      down(i,s,a);
      left(s,k,a);
      top(k,j,a);}

     }
     show(n,a);
     getche();
}
void right(int row,int col,int a[N][N])
{ if(a[row][col]==0)
   {a[row][col]=f++;
   }
}
void down(int row,int col,int a[N][N])
  { if(a[row][col]!=0)
    a[row][col]=f++;
  }
void left(int row,int col,int a[N][N])
{ if(a[row][col]!=0)
   a[row][col]=f++;
}
void top(int row,int col,int a[N][N])
{ if(a[row][col]!=0)
   a[row][col]=f++;
}
void show(int rc, int a[N][N])
{for(int i=0;i<rc;i++)
 {for(int j=0;j<rc;j++)
   cout<<a[i][j]<<"\t";
   cout<<endl;
 }
}
