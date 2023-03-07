#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       int a[10],i;
	float sum=0,x=0;
	clrscr();
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{      	x=pow(a[i],2);
		sum=sum+x;
	}
	for(i=0;i<10;i++)
	{      	printf("%d\t",a[i]);
		printf("\n");
	}
	x=1/2;
	x=sqrt(sum);
	printf("\n%f",x);
	getch();
}

