#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct train
{
	int id,dist,noc;
	char dest[10];
};

void swap(struct train *a,struct train *b)
{	struct train t;
	t=*a;
	*a=*b;
	*b=t;
}


void main()
{   int i,n=0;
	int ch;
	struct train ob[10];
	void mrg_srt1(struct train a[],int);
	void mrg_srt2(struct train a[],int);
	FILE *fp;
	fp=fopen("train.txt","r");
	if(fp==NULL)
	{
		printf("file not found");
		exit(0);
	}
	do
	{
		fscanf(fp,"%d|%d|%d|%s\n",&ob[n].id,&ob[n].dist,&ob[n].noc,&ob[n].dest);
		n++;
	}while(!feof(fp));
	fclose(fp);
	do
	{
		printf("\n\t1.distanc sort");
		printf("\n\t2.destination sort");
		printf("\n\t3.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				mrg_srt1(ob,n);
				fp=fopen("test3.txt","w");
				if(fp == NULL)
				{
					printf("\nCannot open file");
					exit(0);
				}

				for(i=0;i<n;i++)
				{
					fprintf(fp,"%d %d %d %s\n",ob[i].id,ob[i].dist,ob[i].noc,ob[i].dest);
		
				}
				fclose(fp);
				break;

			case 2:
				mrg_srt2(ob,n);
				fp=fopen("test4.txt","w");
				if(fp == NULL)
				{
					printf("\nCannot open file");
					exit(0);
				}

				for(i=0;i<n;i++)
				{
					fprintf(fp,"%d %d %d %s\n",ob[i].id,ob[i].dist,ob[i].noc,ob[i].dest);
		
				}
				fclose(fp);
				break;
			case 3:
				exit(0);
			default:
				printf("\nWrong Input");
				break;
		}
	}while(1);
}

void mrg_srt1(struct train a[],int n)
{   
	//Declaring Variables
	int la,ua,lb,ub,i,j,size,k;
	struct train aux[50];
	//Merge sort logic
	size=1;
	while(size<n)
	{	k=0;
		la=0;
		while(la+size<=n)
		{	lb=la+size;
			ua=lb-1;
			ub=(lb+size-1)<10?lb+size-1:n-1;
			for(i=la,j=lb;i<=ua && j<=ub;k++)
			{	if(a[i].dist<a[j].dist)
				{	aux[k]=a[i];
					i++;
				}
				else
				{	aux[k]=a[j];
					j++;
				}
			}
			while(i<=ua)
			{	aux[k]=a[i];
				k++;
				i++;
			}
			while(j<=ub)
			{	aux[k]=a[j];
				k++;
				j++;
			}
			la=ub+1;
		}
		for(i=0;i<n;i++)
			a[i]=aux[i];
		size=size*2;
	}
}

void mrg_srt2(struct train a[],int n)
{   //Declaring Variables
	int la,ua,lb,ub,i,j,size,k;
	struct train aux[50];
	//Merge sort logic
	size=1;
	while(size<n)
	{	k=0;
		la=0;
		while(la+size<=n)
		{	lb=la+size;
			ua=lb-1;
			ub=(lb+size-1)<n?lb+size-1:n-1;
			for(i=la,j=lb;i<=ua && j<=ub;k++)
			{	if(a[i].dest[0]<a[j].dest[0])
				{	aux[k]=a[i];
					i++;
				}
				else
				{	aux[k]=a[j];
					j++;
				}
			}
			while(i<=ua)
			{	aux[k]=a[i];
				k++;
				i++;
			}
			while(j<=ub)
			{	aux[k]=a[j];
				k++;
				j++;
			}
			la=ub+1;
		}
		for(i=0;i<n;i++)
			a[i]=aux[i];
		size=size*2;
	}
}