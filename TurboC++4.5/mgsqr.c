//Magic squa	re
#include<stdio.h>

main()
{	int a[10][10],i,j,n,sr=0,sc=0,f=1,s=0;
	printf("Enter order of matrix-");
	scanf("%d",&n);
	printf("Enter elements of array-\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	sr=sr+a[i][j];
			sc=sc+a[j][i];
		}
		printf("\n%d %d",sr,sc);
		if(i==0)
			s=sr;
		if(sr==sc)
		{	if(sr==s)
				f=1;
			else
			{	f=0;
				break;
			}
		}
		else
		{	f=0;
			break;
		}
		if(f==0)
			break;
		sr=0;
		sc=0;
	}
	printf("f=%d",f);
	if(f==1)
	{	sr=0;sc=0;
		for(i=0,j=n-1;i<n;i++,j--)
		{	sr=sr+a[i][i];
			sc=sc+a[i][j];
		}
		if(sr==sc)
		{	if(sr==s)
				f=1;
			else
				f=0;
		}
		else
			f=0;
	}
	if(f==0)
		printf("\nIt is not a magic square");
	else
		printf("\nIt is a magic square");
	return(0);
}
