     /* Gauss elimination OK */

#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
  float a[10][10],x[10],r;
  int i,j,k,n;
  clrscr();

  printf("Enter the order of co-efficient matrix:");
  scanf("%d",&n);
  printf("Enter the matrix with right hand side:\n");

  for(i=0;i<n;i++)
    {
    for(j=0;j<=n;j++)
      {
      printf("a[%d][%d]=",i,j);
      scanf("%f",&a[i][j]);
      }
    }

  for(k=0;k<n;k++)
    {
    for(i=k+1;i<n;i++)
      {
      r=a[i][k]/a[k][k];
      for(j=0;j<=n;j++)
	 a[i][j]=a[i][j]-r*a[k][j];
       }
     }

    x[n-1]=a[n-1][n]/a[n-1][n-1];
    for(j=n-2;j>=0;j--)
       {
	x[j]=a[j][n];
	for(i=n-1;i>j;i--)
	       x[j]=x[j]-a[j][i]*x[i];
	x[j]=x[j]/a[j][j];
       }
    printf("\n\n\n Solution is......\n\n");
    for(i=0;i<n;i++)
	printf("x[%d]=%f  \n",i,x[i]);
  getch();
}