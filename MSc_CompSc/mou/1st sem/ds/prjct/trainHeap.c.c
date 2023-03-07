//Heap sort
#include<stdio.h>
#include<conio.h>

struct train
{
	int id,dist,noc;
	char dest[10];
};

void main()
{   //Declaing Variables and functions
	void crheap1(struct train [],int);
	void heapsort1(struct train [],int);
	void crheap2(struct train [],int);
	void heapsort2(struct train [],int);
	int i,n=0;
	int ch;
	struct train ob[10];
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
				crheap1(ob,n);
				//Calling the Heap Sort function
				heapsort1(ob,n);
			//Displaying the sorted array
				fp=fopen("test7.txt","w");
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
				crheap2(ob,n);
				//Calling the Heap Sort function
				heapsort2(ob,n);
				//Displaying the sorted array
				fp=fopen("test8.txt","w");
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

//Heap Create function is defined
void crheap1(struct train a[],int n)
{	int i,j,k;
	struct train key;
	//Heap Create logic
	for(k=1;k<n;++k)
	{	i=k;
		key=a[k];
		j=(int)((i-1)/2);
		while((i>0) && (key.dist>a[j].dist))
		{	a[i]=a[j];
			i=j;
			j=(int)((i-1)/2);
			if(j<0)
				j=0;
		}
		a[i]=key;
	}
}

//Heap Sort function is defined
void heapsort1(struct train a[],int n)
{	int k,i,j;
	struct train temp,key;
	//Heap Sort logic
	for(k=n-1;k>=1;--k)
	{	temp=a[0];
		a[0]=a[k];
		a[k]=temp;
		i=0;
		key=a[0];
		j=1;
		if((j+1)<k)
			if(a[j+1].dist>a[j].dist)
				j=j+1;
		while((j<=(k-1)) && (a[j].dist>key.dist))
		{	a[i]=a[j];
			i=j;
			j=2*i;
			if((j+1)<k)
			{	if(a[j+1].dist>a[j].dist)
					j=j+1;
				else if(j>n)
					j=n;
			}
			a[i]=key;
		}
	}
}

//Heap Create function is defined
void crheap2(struct train a[],int n)
{	int i,j,k;
	struct train key;
	//Heap Create logic
	for(k=1;k<n;++k)
	{	i=k;
		key=a[k];
		j=(int)((i-1)/2);
		while((i>0) && (key.dest[0]>a[j].dest[0]))
		{	a[i]=a[j];
			i=j;
			j=(int)((i-1)/2);
			if(j<0)
				j=0;
		}
		a[i]=key;
	}
}

//Heap Sort function is defined
void heapsort2(struct train a[],int n)
{	int k,i,j;
	struct train temp,key;
	//Heap Sort logic
	for(k=n-1;k>=1;--k)
	{	temp=a[0];
		a[0]=a[k];
		a[k]=temp;
		i=0;
		key=a[0];
		j=1;
		if((j+1)<k)
			if(a[j+1].dest[0]>a[j].dest[0])
				j=j+1;
		while((j<=(k-1)) && (a[j].dest[0]>key.dest[0]))
		{	a[i]=a[j];
			i=j;
			j=2*i;
			if((j+1)<k)
			{	if(a[j+1].dest[0]>a[j].dest[0])
					j=j+1;
				else if(j>n)
					j=n;
			}
			a[i]=key;
		}
	}
}