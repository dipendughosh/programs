#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
struct train
{
	int train_id;
	char dest[20];
	int dist;
	int no_of_comp;
};
void merge_sort1(struct train t[ ],int,int);
void merge_sort2(struct train t[ ],int,int);
void merge(struct train t[],int,int,int);
void mergee(struct train t[],int,int,int) ;
main()
{
	struct train t[20];
	int i,ans;
	int m=0,n=0;
	char ch;

	FILE *fp;
	FILE *fpp;
	fp=fopen("train.txt","r");
	//	clrscr();
	if(fp==NULL)
	{
		printf("file cannot be opened");

		exit(1);
	}
	       //	printf("enter no of entries");
	//scanf("%d",&n);
	 do
	 {
	
	 fscanf(fp,"%d|%s|%d|%d\n",&t[n].train_id,&t[n].dest,&t[n].dist,&t[n].no_of_comp);
	 n=n+1;
	 }
	 while(!feof(fp)) ;
	/*for(i=1;i<=n;i++)
	 {
	 fscanf(fp,"%d%s%d%d",&t[i].train_id,&t[i].dest,&t[i].dist,&t[i].no_of_comp);
	 } */
	fclose(fp);
	for(i=0;i<n;i++)
	     printf("%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);
	       //	fprintf(fp,"%d%s%d%d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);*/
	printf("1.distance:");
	printf("\n2.destination:");
	printf("\nenter ur choice: ");
	scanf("%d",&ans);
	fpp=fopen("train1.txt","w");
	switch(ans)
	{
		case 1:
		{

			merge_sort1(t,m,n);
			for(i=0;i<n;i++)
		       fprintf(fpp,"%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);
			break;
		}
		case 2:
		{

			merge_sort2(t,m,n);
			for(i=0;i<n;i++)
			fprintf(fpp,"%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);

		}
	}
	fclose(fpp);
	getch();
	return 0;
}

void merge_sort1(struct train temp1[ ],int m,int n)
{
	int p;
	//struct train temp;
	if(m<n)
	{
		p=(m+n)/2;
		merge_sort1(temp1,m,p);
		merge_sort1(temp1,p+1,n);
		merge(temp1,m,p,n);
	}
}
      void merge(struct train temp1[],int m,int p,int n)
	{
	 int i,j,k,l;
	 struct train b[20];
	 i=m;
	 j=p+1;
	 k=m;
	 while(i<=p&&j<=n)
	 {
	    if(temp1[i].dist<temp1[j].dist)
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
	   for(l=0;l<k;l++)
	   temp1[l]=b[l];

}

void merge_sort2(struct train temp1[ ],int m,int n)
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

