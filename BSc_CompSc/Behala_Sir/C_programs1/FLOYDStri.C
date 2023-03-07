    /* Floyd's triangle  OK */

#include"stdio.h"
#include"conio.h"

void main()
{

	int i,j,start=1,c=1;
	clrscr();

	for(i=1;i<=5;i++)
	{

		for(j=start;j<start+i;j++)
		{
			printf("%6d",c);
			c=1-c;
		}
		if( i%2 == 0 )
			c=1-c;


		printf("\n\n");

		start=start+i;
	}


	getch();

}