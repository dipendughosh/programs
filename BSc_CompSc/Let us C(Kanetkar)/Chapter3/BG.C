#include<stdio.h>
#include<conio.h>

void main()
{	int c=1,n,x=0,y=0,z=0;
	clrscr();
	while(c==1)
	{	printf("Enter number :- ");
		scanf("%d",&n);
		if(n<0)
			x++;
		else if(n>0)
			y++;
		else if(n==0)
			z++;
		printf("\nDo you want to enter any more (1-Yes,2-No) :- ");
		scanf("%d",&c);
	}
	printf("\n-ive nos. = %d\n+ive nos. = %d\n0s = %d",x,y,z);
	getch();
}

