			 //PROGRAM OF INSERTION SORT
		       /*----------------------------*/
#include<stdio.h>
#include<conio.h>
void insertionsort(int x[],int n);
void main()
{
 int x[20],n,i;
 clrscr();
 printf("\n\n\t\tEnter the number of elements:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("\n\n\t\tEnter the no[%d]-th element:",i+1);
  scanf("%d",&x[i]);
 }
 insertionsort(x,n);
getch();
}
void insertionsort(int x[],int n)
{
    int y,k,i;
    for(k=1;k<n;k++)
    {
     y=x[k];
     for(i=k-1;i>=0&&y<x[i];i--)
     x[i+1]=x[i];
     x[i+1]=y;
    }
    printf("\n\n\t\tThe sorted array is:");
    for(i=0;i<n;i++)
    {
     printf("\t%d",x[i]);
    }
}
