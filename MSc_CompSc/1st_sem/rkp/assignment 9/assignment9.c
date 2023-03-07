/*amortized alorithm implementation*/
#include<stdio.h>
#include<conio.h>

long int a[20],b[20];

void main()
{
	int n,i,l,d;
	long int ci=0,cip=0,ti=0,ai=0,counter=0,fav=0;
	long int max=1,j,num,k;
	printf("Enter number of digits for representation :- ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		max*=2;
	printf("\nMax value is :- %ld",max);
	printf("\nValue\tbin\tci\tti\tai\n");
	for(j=0;j<=max;j++)
	{
		num=j;
		l=19;
		while(num!=0)
		{
			k=num%2;
			num/=2;
			a[l]=k;
			l--;
		}
		for(i=20-n;i<20;i++)
		{
			if(a[i]!=b[i])
				ti++;
		}
		for(i=20-n;i<20;i++)
		{
			if(a[i]==1)
				ci++;
		}
		ai=ti+ci-cip;
		counter+=ai;
		printf("%ld\t",j);
		d=20-n;
		for(i=d;i<20;i++)
			printf("%ld",a[i]);
		printf("%ld\t%ld\t%ld\n",ci,ti,ai);
		for(i=0;i<20;i++)
			b[i]=a[i];
		cip=ci;
		ci=0;
		ti=0;
		ai=0;
	}
	fav=counter/max;
	printf("\n%ld",fav);
}

