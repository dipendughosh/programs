/* odd or even testing using bitwise operator.OK */

#include<stdio.h>
#include<conio.h>
void main(void)
{
 int x;
 clrscr();
 printf("\n\Enter a number: ");
 scanf("%d",&x);
 if((x&1)==0)
  printf("\n\nThe no. is even..");
 else
  printf("\n\nThe no. is odd..");
 getch();
}