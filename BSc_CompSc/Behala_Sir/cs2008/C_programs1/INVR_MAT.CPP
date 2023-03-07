/* 		         surya rules			*/

/*	             inverse of a matrix		*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"



void main()
{
	float a[10][10],b[10][10],r;
	int i,j,k,n;
	clrscr();
	printf("enter the order of the square matrix:");
	scanf("%d",&n);

	/* 	taking elements into the matrix array		*/

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%f",&a[i][j]);
		}
	}

	/* 	display the matrix	*/

	printf("\n the matrix is ..............\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%10.2f  ",a[i][j]);
		}
		printf("\n");
	}

	/*		taking of an identity matrix	*/

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				b[i][j]=1.0;
			else
				b[i][j]=0.0;
		}
	}

	/*		inverse of the matrix		*/

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(k==i)
				continue;
			r=a[i][k]/a[k][k];
			for(j=0;j<n;j++)
			{
				a[i][j]=a[i][j]-r*a[k][j];
				b[i][j]=b[i][j]-r*b[k][j];
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{


			       //	if(a[i][j]==a[i][j]/a[i][i]);
					b[i][j]=b[i][j]/a[i][i];

		}
	}

	/*	 printing the inverse matrix		*/

	printf("\n inverse matrix is...........\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%10.2f  ",b[i][j]);
		}
		printf("\n");
	}

	getch();

}