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
	struct train ob[10];
	int ch;
	void qk_srt1(struct train a[],int,int);
	void qk_srt2(struct train a[],int,int);
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
					qk_srt1(ob,0,n);
					fp=fopen("test1.txt","w");
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
					qk_srt2(ob,0,n);
					fp=fopen("test2.txt","w");
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
					printf("\nWrong Input: Re Enter");
					break;	
		}
	}while(1);
	
}

void qk_srt1(struct train a[],int m,int n)
{       //Declaring Variables
	int i,j,k;
	//Quick sort logic
	if(m<n)
	{	i=m;
		j=n;
		k=a[m].dist;
		do
		{	do
			{	i++;
			}while(a[i].dist<k);
			do
			{	j--;
			}while(a[j].dist>k);
			if(i<j)
				swap(&a[i],&a[j]);
		}while(i<j);
		swap(&a[m],&a[j]);
		qk_srt1(a,m,j-1);
		qk_srt1(a,j+1,n);
	}
}

void qk_srt2(struct train a[],int m,int n)
{       //Declaring Variables
	int i,j;
	char k[80];
	//Quick sort logic
	if(m<n)
	{	i=m;
		j=n;
		strcpy(k,a[m].dest);
		do
		{	do
			{	i++;
			}while(a[i].dest[0]<k[0]);
			do
			{	j--;
			}while(a[j].dest[0]>k[0]);
			if(i<j)
				swap(&a[i],&a[j]);
		}while(i<j);
		swap(&a[m],&a[j]);
		qk_srt2(a,m,j-1);
		qk_srt2(a,j+1,n);
	}
}
