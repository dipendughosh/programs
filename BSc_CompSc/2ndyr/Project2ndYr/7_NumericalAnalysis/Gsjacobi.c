//Gauss Jacobi Method to solve a set of equations
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       //Declaring Variables
	float a[20][20],x[20],y[20],r;
	int i,j,k,n,flag;
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
	//Gauss Jacobi Method logic
	for(i=0;i<n;i++)
	{	x[i]=0.0;
		y[i]=0.0;
	}
	do
	{	flag=0;
		for(j=0;j<n;j++)
		{	x[j]=a[j][n];
			for(i=0;i<n;i++)
			{	if(i==j)
					continue;
				x[j]=x[j]-y[i]*a[j][i];
			}
			x[j]=x[j]/a[j][i];
		}
		for(i=0;i<n;i++)
		{       if(fabs(y[i]-x[i])>0.0005)
			{	flag=1;
				for(j=0;j<n;j++)
					y[j]=x[j];
				break;
			}
		 }
	}while(flag);
	printf("\nSolution is-\n");
	for(i=0;i<n;i++)
		printf("x%d = %.3f\n",i,x[i]);
	getch();
}








Output:-

Enter number of equations-3                                      
Enter co-efficient Matrix with R.H.S-                        
a[0][0]=8                                                                     
a[0][1]=-3                                                                    
a[0][2]=2                                                                     
a[0][3]=20                                                                   
a[1][0]=4                                                                     
a[1][1]=11                                                                   
a[1][2]=-1                                                                    
a[1][3]=33                                                                   
a[2][0]=1                                                                     
a[2][1]=1                                                                     
a[2][2]=4                                                                            
a[2][3]=9                                                               
                                                                              
Solution is-                                                                  
x0 = 3.000                                                                    
x1 = 2.000                                                                   
x2 = 1.000                                                                    
