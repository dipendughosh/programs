/* CROSS BY STAR OK*/

#include<stdio.h>
#include<conio.h>
void main()
{
int x,i,j,y;
clrscr();
     printf("enter the row: ");
	scanf("%d",&x);
     printf("\n\nCROSS IS..........\n\n");
      y=x;
    for(i=0;i<x;i++)
       {
	for(j=0;j<=i;j++)
	   printf(" ");
	printf("*");
	for(j=0;j<2*y-3;j++)
	   printf(" ");
	if(i!=x-1)
	   printf("*\n");
	 else
	   printf("\n");
	y--;
	}

      for(i=0,y=1;i<x-1;i++)
       {
	y++;
	for(j=x-1;j>i;j--)
	   printf(" ");
	printf("*");
	for(j=0;j<2*y-3;j++)
	   printf(" ");
	   printf("*\n");
	}


     getch();
  }
