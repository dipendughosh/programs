//Multiplication of 2 dynamic matrix and Matrix Inversion of a matrix
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       //Declaring variables
	int c;
	void multi();
	void inverse();
	//Loop for the choice of the user
	do
	{	//clrscr();
		printf("\n\t\tM E N U");
		printf("\n\t1.Matrix Multiplication");
		printf("\n\t2.Matrix Inversion");
		printf("\n\t3.Exit");
		printf("\nEnter choice:- ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				multi();
				break;
			case 2:
				inverse();
				break;
			case 3:
				getch();
				exit(0);
			default:
				printf("\nWrong Choice");
			break;
		}
	}while(1);
}

//Matrix Multiplication function
void multi()
{       //Declaring variables
	int n=10,m=10,p=10,q=10,i,k,j;
	int a[10][10],b[10][10],c[10][10];
	//clrscr();
	//Entering the order of the matrices
	printf("Enter Row of Matrix A:");
	scanf("%d",&n);
	printf("\nEnter Column of Matrix A:");
	scanf("%d",&m);
	printf("\nEnter Row of Matrix B:");
	scanf("%d",&p);
	printf("\nEnter Column of Matrix B:");
	scanf("%d",&q);
	if(m==p)
	{       //Entering elements of 1st matrix
		printf("\nEnter Elements of Matrix A\n");
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{	printf("a[%d][%d]=",i,j);
				scanf("%d",&a[i][j]);
			}
		//Entering elements of 2nd matrix
		printf("\nEnter Elements of Matrix B\n");
		for(i=0;i<p;i++)
			for(j=0;j<q;j++)
			{	printf("b[%d][%d]=",i,j);
				scanf("%d",&b[i][j]);
			}
		for(i=0;i<n;i++)
			for(j=0;j<q;j++)
				c[i][j]=0;
		//Matrix multiplication loop
		for(i=0;i<n;i++)
			for(j=0;j<q;j++)
				for(k=0;k<m;k++)
					c[i][j]+=a[i][k]*b[k][j];
		//clrscr();
		//Displaying 1st matrix
		printf("\nMatrix A\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<m;j++)
				printf("%d\t",a[i][j]);
			printf("\n");
		}
		//Displaying 2nd matrix
		printf("\nMatrix B\n");
		for(i=0;i<p;i++)
		{	for(j=0;j<q;j++)
				printf("%d\t",b[i][j]);
			printf("\n");
		}
		//Displaying resultant matrix
		printf("\nMatrix C\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<q;j++)
				printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
	else
		printf("\nMultiplication not possible:");
	getch();
}

//Matrix inversion function
void inverse()
{       //Declaring variables
	float x[20][20],y[20][20],r;
	int i,j,k,n;
	//clrscr();
	//Entering data
	printf("Enter order of Matrix-");
	scanf("%d",&n);
	printf("\nEnter Elements of Matrix-\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	printf("x[%d][%d]=",i,j);
			scanf("%f",&x[i][j]);
		}
	}
	//clrscr();
	//Displaying the initial matrix
	printf("\nThe entered Matrix is\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
			printf("%f\t",x[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	if(i==j)
				y[i][j]=1.0;
			else
				y[i][j]=0.0;
		}
	}
	//Matrix inverse loop
	for(k=0;k<n;k++)
	{	for(j=0;j<n;j++)
		{	if(k==j)
				continue;
			r=x[j][k]/x[k][k];
			for(i=0;i<=n;i++)
			{	x[j][i]=x[j][i]-r*x[k][i];
				y[j][i]=y[j][i]-r*y[k][i];
			}
		}
	}
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	y[i][j]=y[i][j]/x[i][i];
			x[i][j]=x[i][j]/x[i][i];
		}
	}
	//Displaying the resultant matrix
	printf("\nThe inverse Matrix is -\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
			printf("%f\t",y[i][j]);
		printf("\n");
	}
	getch();
}

