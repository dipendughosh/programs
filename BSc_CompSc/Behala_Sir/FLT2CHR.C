#include<stdio.h>
#include<conio.h>


void main()
{       float x;
	char str[10];
	int stk[10],i,j,y,z;
	clrscr();
	printf("Enter float number:-");
	scanf("%f",&x);
	i=0;
	y=x;
	while(y!=0)
	{	stk[i++]=y%10;
		y=y/10;
	}
	z=0;
	for(j=i-1;j>=0;j--)
		str[z++]=stk[j]+48;
	str[z++]='.';
	y=x;
	x=x-y;
	while(x!=0.0)
	{       str[z++]=(x*10.0)+48;
		x=x*10.0;
	}
	str[z]='\0';
	puts(str);

	getch();
}

