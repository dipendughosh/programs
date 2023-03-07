#include<stdio.h>
#include<conio.h>

void main()
{       void display(int [],int);
	int a[10],i,n;
	clrscr();
	printf("Enter no. of elements ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	display(a,n);
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	getch();
}
void display(int b[],int n)
{	int i;
	for(i=0;i<n;i++)
		b[i]=1;
}

