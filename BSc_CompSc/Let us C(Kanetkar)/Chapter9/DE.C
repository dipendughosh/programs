#include<stdio.h>
#include<conio.h>

void main()
{       char str[10];
	int len,x,i,sum=0,t=1;
	clrscr();
	printf("Enter a number as string-> ");
	gets(str);
	len=strlen(str);
	for(i=(len-1);i>=0;i--)
	{	x=str[i]-48;
		sum=sum+(t*x);
		t*=10;
	}
	printf("%d",sum);
	getch();
}

