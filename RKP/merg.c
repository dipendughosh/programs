//To merge two sorted list
#include <stdio.h>
#include <conio.h>

int main()
{  // clrscr();
	//Declaring variables
    int a[10],b[10],c[20],i,j,n,m,temp,x=0,y=0;
	//Entering data
    printf("\nEnter size of array A :  ");
    scanf("%d",&n);
    printf("\nEnter sorted array A :\n");
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    printf("\nEnter size of array B :");
    scanf("%d",&m);
    printf("\nEnter sorted array B :\n");
    for(i=0;i<m;i++)
	scanf("%d",&b[i]);
	//Displaying first array 
    printf("\nARRAY A :\n");
    for(i=0;i<n;i++)
	printf("\t%d",a[i]);
	//Displaying second array 
    printf("\nARRAY B :\n");
    for(i=0;i<m;i++)
	printf("\t%d",b[i]);
	//Initializing resultant array
    for(i=0;i<n+m;i++)
		c[i]=0;
	//Loop to merge the arrays
    for(i=0;i<n+m;i++)
	{
	    if(a[x]>=b[y])
	    {   c[i]=b[y];
			y++;
	    }
	    else
	    {   c[i]=a[x];
			x++;
	    }
	}
	//If array A has not been completed
	if(x!=n)
	{	for(i;x<n;x++)
			c[i]=a[x];
	}
	//If array B has not been completed
	if(y!=m)
	{	for(i;y<m;y++)
			c[i]=b[y];
	}
	//Displaying merged array 
    printf("\nARRAY C :\n");
    for(i=0;i<n+m;i++)
		printf("%d\t",c[i]);
    getch();
    return(0);
}
