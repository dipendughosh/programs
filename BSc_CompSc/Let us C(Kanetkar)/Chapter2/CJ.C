#include<stdio.h>
#include<conio.h>

void main()
{	int x1,x2,x3,y1,y2,y3,m1,m2;//,m3;
	clrscr();
	printf("Enter co-ordinates of pt. A(x1,y1) ");
	printf("\nEnter x1 ");
	scanf("%d",&x1);
	printf("\nEnter y1 ");
	scanf("%d",&y1);
	printf("Enter co-ordinates of pt. B(x2,y2) ");
	printf("\nEnter x2 ");
	scanf("%d",&x2);
	printf("\nEnter y2 ");
	scanf("%d",&y2);
	printf("Enter co-ordinates of pt. A(x3,y3) ");
	printf("\nEnter x3 ");
	scanf("%d",&x3);
	printf("\nEnter y3 ");
	scanf("%d",&y3);
	m1=(y2-y1)/(x2-x1);
	m2=(y3-y2)/(x3-x2);
	if(m1==m2)
		printf("\n3 Pts. on a st. line");
	else
		printf("\n3 Pts. not on a st. line");
	getch();
}

