#include<stdio.h>

int main()
{
	int c,d;
	d=0;
	c=!(d);
	printf("%d",c);
	d=1;
	c=!(d);
	printf("%d",c);
	return 0;
}