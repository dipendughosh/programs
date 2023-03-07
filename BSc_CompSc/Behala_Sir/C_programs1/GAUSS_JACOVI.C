/* Gauss jacobi-iteration method Ok */
/* Please  check the datas are diagonally dominant or not */

#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
  float a[10][10],x[10],y[10];
  int i,j,n,iteration=0,flag=0;
  clrscr();
  printf("Enter order of the matrix:");
  scanf("%d",&n);
  printf("Enter co-efficients & RHS\n");

  /* Take input into array */
  for(i=0;i<n;i++)
    {
    for(j=0;j<=n;j++)
      {
      printf("a[%d][%d]=",i,j);
      scanf("%f",&a[i][j]);
      }
    }
  /* Initialize variables */
  for(i=0;i<n;i++)
    {
    x[i]=0.0;
    y[i]=0.0;
    }

  do
    {
    iteration++;
    printf("\n\n iteration: %d \n\n",iteration);

    /* Calculate new set of x values */
    for(i=0;i<n;i++)
      {
      x[i]=a[i][n];
      for(j=0;j<n;j++)
	{
	if(i==j) continue;
	   x[i]=x[i]-a[i][j] * y[j];
	}
	x[i]=x[i]/a[i][i];
      }

      for(i=0;i<n;i++)
	{
	flag=0;
	if ((fabs(x[i]-y[i])) > 0.0005)
	  {
	  flag=1;
	  for(j=0;j<n;j++)
	    y[j]=x[j];
	  break;
	  }
	 }
       for(j=0;j<n;j++)
	  printf("x[%d]=%f  ",j,x[j]);
    } while(flag==1);
  getch();
}
