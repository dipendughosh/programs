			/*FIND OUT THE VALUE OF SIN(X) */

#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int m,c,z,flag=1;
	float f,x,s=0.0,n;
	clrscr();
	printf("Enter the value of x in degree => ");
	scanf("%f",&x);
	n=x;
	printf("\nEnter the range  =>");
	scanf("%d",&m);
	x=(x * 3.14)/180.0;
	for(c=1;c<=m;c+=2)
		{
		f=1.0;
		for(z=c;z>0;z--)
		      f=f*z;
		s= s + (pow(x,c)/f) * flag;
		flag *=-1;
		 }
	 printf("\n\n Sin( %.2f degree )=%.2f",n,s);
     getch();
  }



