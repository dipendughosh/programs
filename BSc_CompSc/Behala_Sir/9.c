/*   *
    ***
   *****
  *******
     .
     .
     .
     .
     .(done)
   n rows */
#include<stdio.h>
#include<conio.h>

void main()
{       int n,i,j,x=0,z=0;
	clrscr();
	printf("Enter number of rows n :- ");
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{       x++;
		for(j=1;j<=i;j++)
			printf(" ");
		for(j=1;j<=(x+z);j++)
			printf("*");

		z++;
		printf("\n");
	}
	i=n;
	x=0;
	z=0;
	while(i>0)
	{	x++;
		j=1;
		while(j<=i)
		{	printf(" ");
			j++;
		}
		j=1;
		while(j<=x+z)
		{	printf("*");
			j++;
		}
		z++;
		printf("\n");
		i--;
	}
	getch();
}

