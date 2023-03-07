#include<stdio.h>
#include<conio.h>


void main()
{       int x,*y,**z,***a;
	clrscr();
	x=5;
	y=&x;
	z=&y;
	a=&z;
	printf("x=%d\n",x);
	printf("&x=%u\n",&x);
	printf("y=%u\n",y);
	printf("&y=%u\n",&y);
	printf("*y=%d\n",*y);
	printf("z=%u\n",z);
	printf("&z=%u\n",&z);
	printf("*z=%u\n",*z);
	printf("&*z=%u\n",&*z);
	printf("**z=%d\n",**z);
	printf("a=%u\n",a);
	printf("&a=%u\n",&a);
	printf("*a=%u\n",*a);
	printf("&*a=%u\n",&*a);
	printf("**a=%u\n",**a);
	printf("&**a=%u\n",&**a);
	printf("***a=%d\n",***a);



	getch();
}

