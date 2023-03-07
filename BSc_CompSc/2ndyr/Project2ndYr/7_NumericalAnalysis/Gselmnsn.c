//Gauss Elemination Method to solve a set of equations
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       //Declaring Variables
	float a[20][20],x[20],r;
	int i,j,k,n;
	clrscr();
	printf("Enter number of equations-");
	scanf("%d",&n);
	printf("Enter co-efficient Matrix with R.H.S-\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<=n;j++)
		{	printf("a[%d][%d]=",i,j);
			scanf("%f",&a[i][j]);
		}
	}
	//Gauss Elemination Method logic
	for(k=0;k<n;k++)
	{	for(j=k+1;j<n;j++)
		{	r=a[j][k]/a[k][k];
			for(i=0;i<=n;i++)
			{	a[j][i]=a[j][i]-r*a[k][i];
			}
		}
	}
	x[n-1]=a[n-1][n]/a[n-1][n-1];
	for(j=n-2;j>=0;j--)
	{	x[j]=a[j][n];
		for(i=n-1;i>j;i--)
		{	x[j]=x[j]-a[j][i]*x[i];
		}
		x[j]=x[j]/a[j][j];
	}
	printf("The solution is .........\n");
	for(i=0;i<n;i++)
	{	printf("x[%d]=%f\n",i,x[i]);
	}
	getch();
}















Output:-

Enter number of equations-3                                      
Enter co-efficient Matrix with R.H.S-                        
a[0][0]=2                                                                     
a[0][1]=3                                                                     
a[0][2]=1                                                                     
a[0][3]=9                                                                     
a[1][0]=1                                                                     
a[1][1]=2                                                                     
a[1][2]=3                                                                     
a[1][3]=6                                                                     
a[2][0]=3                                                                     
a[2][1]=1                                                                     
a[2][2]=2                                                                     
a[2][3]=8                                                                     

The solution is .........                                                  
x[0]=1.944445                                                                 
x[1]=1.611111                                                                 
x[2]=0.277778                                                                 
