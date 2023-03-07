//Deapth-First Search
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0

//Main vertex node structure
struct main_node
{	int c;
	int stat;
	struct main_node *next;
	struct cnct_node *link;
};

//Adjacent vertex node structure
struct cnct_node
{	struct main_node *linked;
	struct cnct_node *nexted;
};

//Function to create a main vertex node with the value passed from main
struct main_node *getnode(int a)
{	struct main_node *new1;
	new1=(struct main_node *)malloc(sizeof(struct main_node));
	new1->c=a;
	new1->stat=1;
	new1->next=NULL;
	new1->link=NULL;
	return(new1);
}

//Function to create an adjacency vertex node
struct cnct_node *getnode1()
{	struct cnct_node *new1;
	new1=(struct cnct_node *)malloc(sizeof(struct cnct_node));
	new1->nexted=NULL;
	new1->linked=NULL;
	return(new1);
}

//Main program
void main()
{       //Declaring variables
	struct main_node *new1,*ptr,*head,*ptr1,*stack[10];
	struct cnct_node *new2,*ptr2,*ptr3;
	int y,x,top;
	head=NULL;
	clrscr();
	//Entering a graph in an adjacency list
	//Entering the main vertices
	printf("Enter the vertices of the graph(integers):- \n");
	do
	{	printf("Enter :-");
		scanf("%d",&y);
		new1=getnode(y);
		if(head==NULL)
			head=new1;
		else
		{	ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Do you want to continue(1-Yes,0-No):- ");
		scanf("%d",&x);
	}while(x==1);
	//Entering the adjacent vertices
	printf("Enter the vertices adjacent to the vertices :- \n");
	ptr=head;
	while(ptr!=NULL)
	{       printf("Does %d have any adjacent vertex?(1-Yes,0-No):- ",ptr->c);
		scanf("%d",&x);
		while(x==1)
		{       printf("Enter adjacent vertex of - %d (if no adjacent vertex,enter 0)- ",ptr->c);
			scanf("%d",&y);
			if(y==0)
				break;
			ptr1=head;
			while(ptr1!=NULL && ptr1->c!=y)
				ptr1=ptr1->next;
			if(ptr1==NULL)
			{	printf("\n%d is not a vertex of the graph\n",y);
				printf("Do you want to re-enter(1-Yes,0-No):- ");
				scanf("%d",&x);
				getch();
				continue;
			}
			new2=getnode1();
			new2->linked=ptr1;
			if(ptr->link==NULL)
				ptr->link=new2;
			else
			{	ptr2=ptr->link;
				while(ptr2->nexted!=NULL)
					ptr2=ptr2->nexted;
				ptr2->nexted=new2;
			}
			printf("Does %d have any more adjacent vertices?(1-Yes,0-No):- ",ptr->c);
			scanf("%d",&x);
		}
		ptr=ptr->next;
	}
	//Displaying the adjacency list
	printf("The Adjacency List is-\n");
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d : ",ptr->c);
		ptr2=ptr->link;
		while(ptr2!=NULL)
		{	printf("%d,",ptr2->linked->c);
			ptr2=ptr2->nexted;
		}
		printf("\n");
		ptr=ptr->next;
	}
	//Performing DFS traversal
	printf("\nPress Enter for Deapth-First Search-\n");
	getch();
	printf("\nEnter starting point-");
	scanf("%d",&y);
	printf("\nThe DFS output is-\n");
	ptr=head;
	while(ptr->c!=y)
		ptr=ptr->next;
	top=0;
	stack[top]=ptr;
	stack[top]->stat=2;
	top++;
	while(top!=0)
	{       stack[top-1]->stat=3;
		printf("%d\t",stack[top-1]->c);
		top--;
		ptr2=stack[top]->link;
		while(ptr2!=NULL)
		{	if(ptr2->linked->stat==3 || ptr2->linked->stat==2)
			{	ptr2=ptr2->nexted;
				continue;
			}
			stack[top]=ptr2->linked;
			top++;
			ptr2->linked->stat=2;
			ptr2=ptr2->nexted;
		}
	}
	getch();
}

