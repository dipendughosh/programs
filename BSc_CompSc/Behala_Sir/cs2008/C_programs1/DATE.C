/* storing a date using just 2 bytes space only OK */

#include<stdio.h>
#include<conio.h>

void showbits(int);
void main(void)
{
 int x,y,day,mnth,yr;
 fflush(stdin);
 clrscr();
 printf("\n\nEnter the day: ");
 scanf("%d",&day);
 printf("\n\nEnter the month: ");
 scanf("%d",&mnth);
 printf("\n\nEnter the year: ");
 scanf("%d",&yr);
 x=512*(yr-1980)+32*mnth+day;
 printf("\n\nThe stored no. in the memory is: %d",x);
 getch();
 clrscr();
 printf("\n\nThe bit wise form of the stored no. is:");
 showbits(x);
 //now retrieving the data..
 //for day..
 y=x;
 y=y&31;
 printf("\n\nThe day is: %d",y);
 //for month..
 y=x;
 y=y&480;
 y=y>>5;
 printf("\n\nThe month is: %d",y);
 //for year..
 y=x;
 y=y&65024;
 y=y>>9;
 y=y+1980;
 printf("\n\nThe year is: %d",y);
 getch();
}
void showbits(int n)
{
 int i,k,x;
 for(i=15;i>=0;i--)
  {
   x=1<<i;
   k=n&x;
   (k==0)? printf("0"):printf("1");
  }
}

