//To multiply two 2D arrays
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaring variables
	int a[10][10],b[10][10],c[10][10],i,j,k,m,n,p,q;
//	clrscr();
	//Entering data
	printf("Enter number of rows of 1st matrices: ");
	scanf("%d",&m);
	printf("Enter number columns of 1st matrices: ");
	scanf("%d",&n);
	printf("Enter number of rows of 2nd matrices: ");
	scanf("%d",&p);
	printf("Enter number columns of 2nd matrices: ");
	scanf("%d",&q);
	printf("A\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("B\n");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);
	//Checking if multiplication is possible for the given dimensions of the arrays
	if(n!=p)
	{
		printf("Multiplication not possible");
		getch();
		//exit(0);
	}
	//Initializing the resultant array
	for(i=0;i<m;i++)
		for(j=0;j<q;j++)
			c[i][j]=0;
	//Loops to perform the multiplication
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				c[i][j]=c[i][j]+(a[i][k]*a[k][j]);
	//Displaying the first array
	printf("A\n");
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	//Displaying the second array
	printf("B\n");
	for(i=0;i<p;i++)
	{	for(j=0;j<q;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	//Displaying the resultant array
	printf("C\n");
	for(i=0;i<m;i++)
	{	for(j=0;j<q;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
	getch();
	return(0);
}

