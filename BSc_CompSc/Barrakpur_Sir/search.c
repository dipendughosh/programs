//search
#include<stdio.h>
#include<conio.h>

void main()
{       int a[100],n,trgt,i,c,loc;
	int linear1(int [],int,int);
	int linear2(int [],int,int);
	int binary(int [],int,int);
	clrscr();
	printf("Enter size of array - ");
	scanf("%d",&n);
	printf("Enter elements of array-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter target - ");
	scanf("%d",&trgt);
	printf("\tMENU\n");
	printf("\t1.Linear Search1\n");
	printf("\t2.Linear Search2\n");
	printf("\t3.Binary Search\n");
	printf("\t4.Exit");
	printf("Enter choice - ");
	scanf("%d",&c);
	switch(c)
	{	case 1:
			loc=linear1(a,n,trgt);
			break;
		case 2:
			loc=linear2(a,n,trgt);
			break;
		case 3:
			loc=binary(a,n,trgt);
			break;
		case 4:
			exit(0);
		default:
			printf("\nWrong Input");
			break;
	}
	if(loc==-1)
		printf("\n%d not found",trgt);
	else
		printf("\n%d found at %d",trgt,loc);
	getch();
}

int linear1(int b[],int m,int t)
{	int i,loc=-1;
	for(i=0;i<m;i++)
	{	if(b[i]==t)
		{	loc=i+1;
			return(loc);
		}
	}
	return(loc);
}

int linear2(int b[],int m,int t)
{	int i=0;
	b[m]=t;
	while(b[i]!=t)
		i++;
	if(i==m)
		i=-1;
	else
		i++;
	return(i);
}

int binary(int b[],int m,int t)
{	int low=0,high=m-1,mid,loc=-1;
	while(low!=high)
	{	mid=(low+high)/2;
		if(b[mid]==t)
		{	loc=mid+1;
			return(loc);
		}
		else if(b[mid]>t)
			high=mid;
		else if(b[mid]<t)
			low=mid;
	}
	return(loc);
}