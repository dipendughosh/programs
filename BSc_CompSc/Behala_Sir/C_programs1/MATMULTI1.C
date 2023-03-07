/MATRIX MULTIPLICATION*/

#include<stdio.h>
#include<conio.h>
void main()
{
int a[10][10],b[10][10],c[10][10],i,j,k,r1,c1,c2;
clrscr();
printf("enter no. of rows and column of 1st matrix: ");
scanf("%d%d",&r1,&c1);
printf("enter no. column of 2nd matrix: ");
scanf("%d",&c2);
clrscr();
printf("\n Enter first matrix......\n");
for(i=0;i<r1;i++)
  {
    for(j=0;j<c1;j++)
     {
	printf("a[%d][%d]=",i,j);
	scanf("%d",&a[i][j]);
     }
  }
printf("\nEnter second matrix.......\n");
  for(i=0;i<c1;i++)
  {
    for(j=0;j<c2;j++)
     {
	printf("b[%d][%d]=",i,j);
	scanf("%d",&b[i][j]);
     }
  }
clrscr();
printf("\n\nFirst matrix is......\n\n");
for(i=0;i<r1;i++)
  {
    for(j=0;j<c1;j++)
	printf("%d  ",a[i][j]);
    printf("\n");
  }

printf("\n\nSecond matrix is.......\n\n");
  for(i=0;i<c1;i++)
  {
    for(j=0;j<c2;j++)
	printf("%d  ",b[i][j]);
    printf("\n");
  }


for(i=0;i<r1;i++)
   {
     for(j=0;j<c2;j++)
	{
	 c[i][j]=0;
	 for(k=0;k<c1;k++)
	   c[i][j] = c[i][j] + a[i][k] * b[k][j];
	}
    }
printf("\n\n After matrix multiplication.....\n\n");
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c2;j++)
	printf("%d  ",c[i][j]);
    printf("\n");
  }

getch();
}



