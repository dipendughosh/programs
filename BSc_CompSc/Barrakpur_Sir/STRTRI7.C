/*       *
       * * *    n lines
     * * * * *
   * * * * * * *
     * * * * *
       * * *
	 *        */
#include<stdio.h>
#include<conio.h>


void main()
{       int i,j,n;
	clrscr();
	printf("\nEnter number of lines :-");
	scanf("%d",&n);
	if(n%2!=0)
		n-=1;
	for(i=1;i<=(n/2);i++)
	{       printf("   ");
		for(j=0;j<((n/2)-i);j++)
			printf("   ");
		for(j=0;j<((i*2)-1);j++)
			printf("*  ");
		printf("\n");
	}
	for(i=0;i<n+1;i++)
		printf("*  ");
	printf("\n");
	for(i=0;i<=((n/2)+1);i++)
	{       for(j=0;j<=i;j++)
			printf("   ");
		for(j=0;j<((((n/2)-i)*2)-1);j++)
			printf("*  ");
		printf("\n");
	}
	getch();
}

