//extract a portion of original string by pointer

#include<stdio.h>
#include<conio.h>

void main()
{
	char *p,*a,*q,*b,*u;
	int n,m,i,x,total;
	clrscr();
	printf("\nEnter the number of your string: ");
	scanf("%d",&x);
	p=(char *)malloc(sizeof(char)*x);
	a=p;
	//u=p;
	printf("\nEnter the original string: ");
	for(i=0;i<x;i++)
	{
		scanf("%c",*a);
		a++;
	}
	/*for(i=0;i<x;i++)
	{
		printf("%c",u);
		u++;
	} */
	printf("\nEnter the no. from which letter you want to extract: ");
	scanf("%d",&n);
	printf("\nEnter how many number you want to extract: ");
	scanf("%d",&m);
	q=(char *)malloc(sizeof(char)*m);
	b=q;
	for(i=0;i<n;i++)
	{
		p++;
	}
	total=n+m-1;
	for(i=0;i<total;i++)
	{
		*q=*p;
		p++;
		q++;
	}
	for(i=0;i<total;i++)
	{
		printf("%s",b);
		b++;
	}
	getch();

}