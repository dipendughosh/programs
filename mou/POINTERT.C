#include<stdio.h>
#include<conio.h>

void main()
{
	char *p,*q;
	int *a,*b;
	int n,m,i;
	clrscr();
	printf("\nEnter the no of element: ");
	scanf("%d",&m);
	a=(int *)malloc(sizeof(int)*m);
	b=a;
	printf("\nEnter the numbers: ");
	for(i=0;i<m;i++)
	{
		scanf("%d",*b);
		b++;
	}
	for(i=0;i<m;i++)
	{
		printf("%d",*a);
		a++;
	}

	printf("\nEnter no of charactor of the string: ");
	scanf("%d",&n);
	p=(char *)malloc(sizeof(char)*n);
	q=p;
	printf("\nEnter the string: ");
	for(i=0;i<n;i++)
	{
		scanf("%c",*q);
		q++;
	}
	for(i=0;i<n;i++)
	{
		printf("%c",*p);
		p++;
	}
	getch();
}

