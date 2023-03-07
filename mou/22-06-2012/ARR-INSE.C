//insert in array

#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10],n,i,m,x,s;
	clrscr();
	printf("\nEnter no of elements: ");
	scanf("%d",&n);

	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]= ",i);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the no which you want to insert: ");
	scanf("%d",&m);
	printf("\nm=%d",m);
	printf("\nEnter the element after which you want to insert: ");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			printf("\n%d th position found",i);
			s=n-1;
			printf("\ns=%d",s);
			//printf("%d",m);

			while(s!=i)
			{
				a[s+1]=a[s];
				s--;
			}
			printf("\nm=%d",m);
			printf("\nFinal position of s=%d",s+1);
			a[s+1]=m;
		}
	}
	printf("\nAfter insertion--");
	for(i=0;i<n+1;i++)
		printf("\na[%d]=%d", i,a[i]);
	getch();
}
