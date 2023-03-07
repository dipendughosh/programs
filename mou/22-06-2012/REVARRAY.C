//reverse array

#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10],n,i,j,c=0,temp,s;
	clrscr();
	printf("\nEnter no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]= ",i);
		scanf("%d",&a[i]);
	}
	i--;
	printf("\ni=%d",i);
	s=n%2;
	j=0;
	if(s==0)  //even
	{
		while(c!=(n/2))
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i--;
			j++;
			c++;
		}
		printf("\nAfter reversing--");
		for(i=0;i<n;i++)
			printf("\na[%d]=%d",i, a[i]);
	}
	else
	{
		while(c<(n/2))
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i--;
			j++;
			c++;
		}
		printf("\nAfter reversing--");
		for(i=0;i<n;i++)
			printf("\na[%d]=%d",i, a[i]);
	}
	getch();
}