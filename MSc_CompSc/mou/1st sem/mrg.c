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
void merge_sort1(int [ ],int,int);
void merge(int [],int [],int,int,int);
//void merge_sort1(struct train t[ ],int,int);
//void merge_sort2(struct train t[ ],int,int);
//void merge(struct train t[],struct train [],int,int,int);
//void mergee(struct train t[],int,int,int) ;
main()
{
	//struct train t[20];
	int i,s=0,n=0,t[10],ans;
/*	FILE *fp;
	FILE *fpp;
	fp=fopen("train.txt","r");
	if(fp==NULL)
	{
		printf("file cannot be opened");

		exit(1);
	}
	do
	 {
		 fscanf(fp,"%d|%s|%d|%d\n",&t[n].train_id,&t[n].dest,&t[n].dist,&t[n].no_of_comp);
		 printf("%d %s %d %d\n",t[n].train_id,t[n].dest,t[n].dist,t[n].no_of_comp);
		 n=n+1;
	 }
	 while(!feof(fp)) ;
	fclose(fp);
	for(i=0;i<n;i++)
	     printf("%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);*/
	printf("\nEnter number of elements :- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);
	/*printf("1.distance:");
	printf("\n2.destination:");
	printf("\nenter ur choice: ");
	scanf("%d",&ans);
	fpp=fopen("train1.txt","w");
	switch(ans)
	{
		case 1:
		
*/
			merge_sort1(t,s,n-1);
/*			for(i=0;i<n;i++)
		       fprintf(fpp,"%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);
			break;*/
		
/*		case 2:
		

			merge_sort2(t,s,n);
			for(i=0;i<n;i++)
				fprintf(fpp,"%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);
			break;

		
	}
	fclose(fpp);*/
	for(i=0;i<n;i++)
		printf("%d\t",t[i]);
	getch();
	return 0;
}

void merge_sort1(int temp1[ ],int s,int t)
{
	int m,i;
	int a[100];
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
void merge(int temp1[],int a[],int s,int t,int m)
{
	 int i,j,k;
	 i=s;
	 j=m+1;
	 k=s;
	 while(i <= m && j <= t)
	 {
	    if(temp1[i]<temp1[j])
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
	 else if(j<=t)
	   {
	     while(j<=t)
	      {
		a[k]=temp1[j];
		k++;
		j++;
	      }
	   }
}


/*void merge_sort1(struct train temp1[ ],int s,int t)
{
	int m,i;
	struct train a[100];
	if(s<t)
	{
		m=(s+t)/2;
		merge_sort1(temp1,s,m);
		merge_sort1(temp1,m+1,t);
		merge(temp1,a,s,t,m);
		for(i=s;i<t;i++)
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

/*void merge_sort2(struct train temp1[ ],int m,int n)
{

	int p;
	struct train temp;
	if(m<n)
	{
		p=(m+n)/2;
		merge_sort2(temp1,m,p);
		merge_sort2(temp1,p+1,n);
		mergee(temp1,m,p,n);
	}
}
  void mergee(struct train temp1[],int m,int p,int n)
	{
	 int i,j,k,l;
	 struct train b[20];
	 i=m;
	 j=p+1;
	 k=m;
	 while(i<=p&&j<=n)
	 {
	    if(temp1[i].dest[0]<temp1[j].dest[0])
	       {
		 b[k]=temp1[i];
		 i++;
	       }
	    else
	       {
		b[k]=temp1[j];
		j++;
	       }
	       k++;
	 }
	 if(i<=p)
	  {
	    for(l=i;l<=p;l++)
	     {
	       b[k]=temp1[l];
	       k++;
	     }
	  }
	 if(j<=n)
	   {
	     for(l=j;l<=n;l++)
	      {
		b[k]=temp1[l];
		k++;
	      }
	   }
	   for(l=m;l<=n;l++)
	   temp1[l]=b[l];
}

*/