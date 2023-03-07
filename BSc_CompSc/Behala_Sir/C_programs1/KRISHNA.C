			/* KRISHNAMURTI NUMBER */

#include<stdio.h>
#include<conio.h>
void main()
{
int x,r,i,f,n,s=0;
clrscr();
printf("enter any number");
scanf("%d",&x);
n=x;
while(n>0)
 {
  r=n%10;
  f=1;
  for(i=1;i<=r;i++)
       f=f*i;
  s=s+f;
  n=n/10;
 }
if(s==x)
   printf("%d is a krishnamurti number",x);
else
   printf("%d is not krishnamurti number",x);
getch();
}