/* * * * * * * *
     * * * * *   n lines
       * * *
     	 *       */
#include<stdio.h>
#include<conio.h>


int main()
{   //Declaring variables
	int i,j,n;
//	clrscr();
	//Enter data
	printf("\nEnter number of lines :-");
	scanf("%d",&n);
	//Loop to generate the format
	for(i=0;i<n;i++)
	{	for(j=0;j<i;j++)
			printf("   ");
		for(j=0;j<(((n-i)*2)-1);j++)
			printf("*  ");
		printf("\n");
	}
	getch();
	return(0);
}

