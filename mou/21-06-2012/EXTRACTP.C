//extract a portion of original string by pointer

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
	i=0;
	while(i<x)
	{
		printf("%d",i);
		//printf("\ntest1");
		scanf("%c",a);
		a++;
		i++;
	}
	printf("\nTesting\n");
	/*for(i=0;i<x;i++)
	{
		printf("%c",u);
		u++;
	} */
	printf("\nEnter the no. from which letter you want to extract: ");
	scanf("%d",&n);
	printf("\nEnter how many number you want to extract: ");
	scanf("%d",&m);
	printf("\n%d",m);
	q=(char *)malloc(sizeof(char)*m);
	b=q;
	for(i=0;i<n;i++)
	{
		p++;
	}
	printf("\n%c",*p);
	printf("\n");
	total=n+m-1;
	for(i=0;i<total;i++)
	{
		*q=*p;
		p++;
		q++;
	}
	for(i=0;i<total;i++)
	{
		printf("%s",*b);
		b++;
	}
	getch();

}