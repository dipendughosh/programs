//integer array
#include<stdio.h>
#include<conio.h>

struct fre
{	int b;
	int cnt;
};

void main()
{       struct fre x[20];
	int a[20],i,j,y=0,flag=0,n;
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{	for(j=0;j<y;j++)
			if(x[j].b==a[i])
			{	flag=1;
				break;
			}
		x[y].cnt=0;
		if(flag==0)
		{       x[y].b=a[i];
			for(j=0;j<n;j++)
			{	if(x[y].b==a[j])
					x[y].cnt++;
			}
			y++;

		}
		flag=0;
	}
	for(i=0;i<y;i++)
		printf("%d\t%d\n",x[i].b,x[i].cnt);
	getch();
}

