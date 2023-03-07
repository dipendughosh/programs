			/* FIBONACCI NUMBER */

#include<stdio.h>
#include<conio.h>
void main()
{
   int a=0,b=1,i,c,n;
   clrscr();
   printf("enter the number of terms:");
      scanf("%d",&n);

   printf("\n\nThe Fibonacci numbers are:\n\n%d %d ",a,b);
   for(i=0;i<n-2;i++)
	{
	c=a+b;
	printf("%d ",c);
	a=b;
	b=c;
	}
   getch();
}