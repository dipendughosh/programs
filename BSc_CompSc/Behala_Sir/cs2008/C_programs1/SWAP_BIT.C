//swap ithout using any mathematical operation & any 3rd variable..
#include<stdio.h>
#include<conio.h>
void main(void)
{
 int x,y;
 clrscr();
 printf("\n\nEnter the value of x: ");
 scanf("%d",&x);
 printf("\n\nEnter the value of y: ");
 scanf("%d",&y);
 x=x^y; //logical x-or operation.
 y=x^y;
 x=x^y;
 printf("\n\n\nAfter swaping the value of 'x' is: %d",x);
 printf("\n\n\nAfter swaping the value of 'y' is: %d",y);
 getch();
}