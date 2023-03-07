//Queue using array
#include<stdio.h>
#include<conio.h>

//Structure of a cell of the queue array
struct queue
{	int a[100];
	int front;
	int rear;
};

//Declaring functions
struct queue qinsert(struct queue);
struct queue qdelete(struct queue);
void display(struct queue);

void main()
{       //Declaring variables
	struct queue q;
	int c,i;
	clrscr();
	q.front=-1;
	q.rear=-1;
	do
	{	printf("\n\t\tM E N U");
		printf("\n\t1.Insert");
		printf("\n\t2.Delete");
		printf("\n\t3.Display Queue");
		printf("\n\t4.Exit");
		printf("\n\tEnter choice:-");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(q.rear==99)
					printf("\nQueue is full");
				else
					q=qinsert(q);
				break;
			case 2:
				if(q.front==q.rear)
					printf("\nQueue Empty");
				else
					q=qdelete(q);
				break;
			case 3:
				if(q.front==q.rear)
					break;
				else
					display(q);
				break;
			case 4:
				printf("Exiting Program");
				for(i=0;i<10;i++)
				{
					delay(600);
					printf(".");
				}
				exit(0);
			default:
				printf("\n\n\aWrong input\a");
				break;
		       }
	}while(1);
}

//Function to enter a data into the queue
struct queue qinsert(struct queue q)
{       printf("\nEnter item to insert - ");
	q.rear=q.rear+1;
	scanf("%d",&q.a[q.rear]);
	return(q);
}

//Function to remove a data from the queue
struct queue qdelete(struct queue q)
{	q.front++;
	printf("\nDeleted element is :- %d",q.a[q.front]);
	getch();
	return(q);
}

//Function to display the elements of the queue
void display(struct queue q)
{       int y=q.front+1;
	printf("\nThe elements in the queue are : -\n");
	while(y<=q.rear)
	{	printf("%d\t",q.a[y]);
		y++;
	}
	getch();
}