//open address hashing
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node
{	int data;
};

struct node ob[100];
int n;

void main()
{	
	void insert();
	void search();
	void traverse();
	void delete1();
	int i,ch;
	printf("\nEnter number bucket :- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		ob[i].data=0;
	do
	{   
		printf("\t\tMenu");
		printf("\n\t1.Insert");
		printf("\n\t2.Search");
		printf("\n\t3.Traverse");
		printf("\n\t4.Delete");
		printf("\n\t5.Exit");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
				insert();
				break;
			case 2:
				search();
				break;
			case 3:
				traverse();
				break;
			case 4:
				delete1();
				break;
			case 5:
				printf("\nExiting prgram......");
				getch();
				exit(0);
			default:
				printf("\nWrong choice");
				getch();
				break;
		}
	}while(1);
}

void insert()
{   
    int i,k,item;
	printf("\nEnter key of data-");
	scanf("%d",&item);
	k=item%n;
	i=k;
	if(ob[i].data!=0)
	{	
		i++;
		while(i!=k)
		{	
			if(ob[i].data==0)
				break;
			i++;
			if(i==n)
				i=0;
		}
	}
	if(ob[i].data==0)
	{	
		ob[i].data=item;
		return;
	}
	printf("\nNo empty space");
}

void search()
{	
	int item,k,i;
	printf("\nEnter data number to search-");
	scanf("%d",&item);
	k=item%n;
	i=k;
	if(ob[i].data!=item)
	{	
		i++;
		while(i!=k)
		{
			if(ob[i].data==item)
				break;
			i++;
			if(i==n)
				i=0;
		}
	}
	if(ob[i].data==item)
	{	
		printf("\n%d present at bucket %d",ob[i].data,i);
		return;
	}
	printf("\n%d not present",item);
}

void traverse()
{       
	int i;
	i=0;
	while(i<n)
	{	
		printf("\n%d-",i);
		if(ob[i].data!=0)
			printf("\t%d",ob[i].data);
		i++;
	}
}

void delete1()
{	
	int item,k,i;
	printf("\nEnter data number whose details to delete-");
	scanf("%d",&item);
	k=item%n;
	i=k;
	if(ob[i].data!=item)
	{
		i++;
		while(i!=k)
		{
			if(ob[i].data==item)
				break;
			i++;
			if(i==n)
				i=0;
		}
	}
	if(ob[i].data==item)
	{	
		printf("\ndeleting\n%d-",ob[i].data);
		ob[i].data=0;
		return;
	}
	printf("\n%d not present",item);
}
