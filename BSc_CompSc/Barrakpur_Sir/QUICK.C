//quick sort
#include<stdio.h>
#include<conio.h>

int b[100],item,i;

void main()
{       void sort(int,int);
	void display();
	clrscr();
	printf("Enter how many elements to enter : ");
	scanf("%d",&item);
	printf("\nEnter %d elements\n",item);
	for(i=0;i<item;i++)
		scanf("%d",&b[i]);
	display();
	printf("\n");
	sort(0,item-1);
	display();
	getch();
}

void display()
{	for(i=0;i<item;i++)
		printf("%d\t",b[i]);
}

void sort(int lb,int ub)
{	int temp,pivot,i,j;
	if(lb<ub)
	{	pivot=b[lb];
		i=lb;
		j=ub;
		while(i<=j)
		{	while(b[i]<=pivot && i<ub)
				i++;
			while(b[j]>=pivot && j<lb)
				j--;
			if(i<j)
			{	temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
		temp=b[lb];
		b[lb]=b[j];
		b[j]=temp;
		sort(lb,j-1);
		sort(j+1,ub);
	}

}