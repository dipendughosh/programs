#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct train
{
	int train_id;
	char dest[20];
	int dist;
	int no_of_comp;
};

void merge_sort1(struct train [ ],int,int);
void merge_sort2(struct train [ ],int,int);
void merge(struct train [],struct train [],int,int,int);
void mergee(struct train [],struct train [],int,int,int) ;
main()
{
	struct train t[20];
	int i,s=0,n=0,ch;
    FILE *fp;
	//FILE *fpp;
	fp=fopen("train.txt","r");
	if(fp==NULL)
	{
		printf("file cannot be opened");

		exit(1);
	}
	do
	 {
		 fscanf(fp,"%d|%d|%d|%s\n",&t[n].train_id,&t[n].dist,&t[n].no_of_comp,&t[n].dest);
		 //printf("%d %d %d %s\n",t[n].train_id,t[n].dist,t[n].no_of_comp,t[n].dest);
		 n=n+1;
	 }
	 while(!feof(fp)) ;
	fclose(fp);
	printf("\n\n");
/*	for(i=0;i<n;i++)
	     printf("%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);*/
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
			merge_sort1(t,s,n-1);
			fp=fopen("test3.txt","w");
				if(fp == NULL)
				{
					printf("\nCannot open file");
					exit(0);
				}


			for(i=0;i<n;i++)
		       fprintf(fp,"%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);
			fclose(fp);
			break;
		
		case 2:
			merge_sort2(t,s,n-1);
			fp=fopen("test4.txt","w");
				if(fp == NULL)
				{
					printf("\nCannot open file");
					exit(0);
				}


			for(i=0;i<n;i++)
				fprintf(fp,"%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);
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



void merge_sort1(struct train temp1[ ],int s,int t)
{
	int m,i;
	struct train a[100];
	if(s<t)
	{
		m=(s+t)/2;
		merge_sort1(temp1,s,m);
		merge_sort1(temp1,m+1,t);
		merge(temp1,a,s,t,m);
		for(i=s;i<=t;i++)
			temp1[i]=a[i];
	}
}
void merge(struct train temp1[],struct train a[],int s,int t,int m)
{
	 int i,j,k;
	 i=s;
	 j=m+1;
	 k=s;
	 while(i <= m && j <= t)
	 {
	    if(temp1[i].dist<temp1[j].dist)
	       {
		 a[k]=temp1[i];
		 i++;
	       }
	    else
	       {
		a[k]=temp1[j];
		j++;
	       }
	       k++;
	 }
	 if(i<=m)
	  {
	    while(i<=m)
		{
	       a[k]=temp1[i];
	       k++;
			i++;
	     }
	  }
	 else
	   {
	     while(j<=t)
	      {
		a[k]=temp1[j];
		k++;
		j++;
	      }
	   }
}


void merge_sort2(struct train temp1[ ],int s,int t)
{
	int m,i;
	struct train a[100];
	if(s<t)
	{
		m=(s+t)/2;
		merge_sort1(temp1,s,m);
		merge_sort1(temp1,m+1,t);
		mergee(temp1,a,s,t,m);
		for(i=s;i<=t;i++)
			temp1[i]=a[i];
	}
}
void mergee(struct train temp1[],struct train a[],int s,int t,int m)
{
	 int i,j,k;
	 i=s;
	 j=m+1;
	 k=s;
	 while(i <= m && j <= t)
	 {
	    if(temp1[i].dest[0]<temp1[j].dest[0])
	       {
		 a[k]=temp1[i];
		 i++;
	       }
	    else
	       {
		a[k]=temp1[j];
		j++;
	       }
	       k++;
	 }
	 if(i<=m)
	  {
	    while(i<=m)
		{
	       a[k]=temp1[i];
	       k++;
			i++;
	     }
	  }
	 else
	   {
	     while(j<=t)
	      {
		a[k]=temp1[j];
		k++;
		j++;
	      }
	   }
}
