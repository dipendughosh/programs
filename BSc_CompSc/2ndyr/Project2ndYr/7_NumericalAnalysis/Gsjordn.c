//Gauss Jordan Method to solve a set of given equations
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       //Declaring variables
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
	//Gauss Jordan Method logic
	for(k=0;k<n;k++)
	{	for(j=0;j<n;j++)
		{	if(k==j)
				continue;
			r=a[j][k]/a[k][k];
			for(i=0;i<=n;i++)
			{	a[j][i]=a[j][i]-r*a[k][i];
			}
		}
	}
	for(i=0;i<n;i++)
	{	x[i]=a[i][n]/a[i][i];
	}
	printf("\nSolution is-\n");
	for(i=0;i<n;i++)
	{	printf("\nx%d=%f",i,x[i]);
	}
	getch();
}















Output:-

Enter number of equations-3                                     
Enter co-efficient Matrix with R.H.S-                       
a[0][0]=1                                                                    
a[0][1]=3                                                                    
a[0][2]=2                                                                    
a[0][3]=17                                                                  
a[1][0]=1                                                                    
a[1][1]=2                                                                    
a[1][2]=3                                                                    
a[1][3]=16                                                                  
a[2][0]=2                                                                    
a[2][1]=-1                                                                   
a[2][2]=4                                                                    
a[2][3]=13                                                        
                                                                         
Solution is-
x0=4.000000                                                                   
x1=3.000000                                                                   
x2=2.000000                                                                   
