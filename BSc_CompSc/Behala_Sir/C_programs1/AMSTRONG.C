			/* ARMSTRONG  NUMBER */

#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
int x,s,r,n;
clrscr();
printf("enter any number");
scanf("%d",&n);
s=0;
x=n;
while(n>0)
{
r=n%10;
s=s+pow(r,3);
n=n/10;
}
if(s==x)
  printf("%d is an amstrong",x);
else
  printf("%d is not amstrong",x);
getch();
}