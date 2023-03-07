//Create pascal triangle till n rows
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaring variables
    int a[20],i,row,j,n,x,y;
//	clrscr();
	//Initializing variables for the loop
	a[0]=1;
	n=0;
	//Entering data
	printf("How many rows : ");
	scanf("%d",&row);
	//Loop for the generation of the pascal triangle and displaying them
	for(i=0;i<row;i++)
	{	x=0;
		//Displaying the number of blank spaces required for displaying in the format of a triangle
		for(j=0;j<40-i;j++)
			printf(" ");
		//Generating the numbers of the next row on the basis of the previous row
		for(j=0;j<n;j++)
		{	printf("%d ",x+a[j]);
			y=a[j];
			a[j]=x+a[j];
			x=y;
		}
		//Displaying the 1's
		printf("1\n");
		n++;
		a[j]=1;
	}
	getch();
	return(0);
}

