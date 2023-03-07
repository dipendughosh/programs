			/* DIAMOND */

#include<stdio.h>
#include<conio.h>
void main()
{
int i,n,j,sp,k;
clrscr();
printf("enter the row: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
  for(j=0;j<40-i;j++)
       printf(" ");
  for(j=0;j< 2*i+1;j++)
      printf("*");
  printf("\n");
}
sp=40-i+1;
i--;
for(k=0;k<n-1;k++,i--)
{
  for(j=0;j<=sp+k;j++)
       printf(" ");
  for(j=0;j< 2*i-1;j++)
      printf("*");
  printf("\n");
}

getch();
}