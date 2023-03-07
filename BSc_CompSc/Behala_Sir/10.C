/*   *
    ***
   *****
    ***
     *
     .
     .
     .  (done)
   n rows */
#include<stdio.h>
#include<conio.h>

void main()
{       int n,i,j,x=0,z=0;
	clrscr();
	printf("Enter number of rows n :- ");
	scanf("%d",&n);
	i=n/2+1;
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
	z=x+z-3;
	j=1;
	while(z>0)
	{       i=1;
		printf(" ");
		while(i<=j)
		{	printf(" ");
			i++;
		}
		i=1;
		while(i<=z)
		{	printf("*");
			i++;
		}
		j++;
		z=z-2;
		printf("\n");
	}
	getch();
}


