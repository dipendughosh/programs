  /* G.C.D.  of two no. using only summesion & bitwise operator OK */

#include<stdio.h>
#include<conio.h>

void main(void)
{
 int x,y,z;
 fflush(stdin);
 clrscr();
 printf("\n\nEnter the first no.: ");
 scanf("%d",&x);
 printf("\n\nEnter the second no.: ");
 scanf("%d",&y);
 while(x!=y)
  {
   if(x>y)
    {
     z=~y;
     z=z+1;
     x=x+z;
    }
   else if(y>x)
    {
     z=~x;
     z=z+1;
     y=y+z;
    }
  }
 printf("\n\nThe answer is: %d",x);
 getch();
}