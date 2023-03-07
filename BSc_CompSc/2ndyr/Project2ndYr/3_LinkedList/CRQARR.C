//Circular Queue using array
#include<stdio.h>
#include<conio.h>

//Declaration of variables and functions
int a[100],front=-1,rear=-1,max=100,c=0;
void qinsert();
void qdelete();
void display();

void main()
{       int b,i;
	do
	{	clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Insert");
		printf("\n\t3.Delete");
		printf("\n\t4.Display");
		printf("\n\t5.Exit");
		printf("\n\tEnter choice:-");
		scanf("%d",&b);
		switch(b)
		{	case 1:
				qinsert();
				break;
			case 2:
				if(front==-1 || rear==-1)
				{	printf("\nQueue Exists");
					getch();
				}
				else
					qdelete();
				break;
			case 3:
				if(front==-1 || rear==-1)
				{	printf("\nQueue Exists");
					getch();
				}
				else
					display();
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

//Function to insert a data into the circular queue
void qinsert()
{       int item;
	printf("Enter Element to Push :- ");
	scanf("%d",&item);
	if(front==-1)
		front=rear=0;
	else if((front == 0 && rear==max-1) || (rear+1==front))
	{	printf("\nFULL");
		return;
	}
	else if(rear==max-1)
		rear=0;
	else
		rear++;
	a[rear]=item;
	c++;
}

//Function to delete a data of the circular queue
void qdelete()
{	if(front==-1)
	{	printf("\nEMPTY");
		return;
	}
	else if(front==rear)
	{	printf("\nDeleted element is :- %d",a[rear]);
		rear=front=-1;
	}
	else if(front==max-1)
	{	printf("\nDeleted element is :- %d",a[front]);
		front=0;
	}
	else
	{	printf("\nDeleted element is :- %d",a[front]);
		front++;
	}
	getch();
}

//Function to display the circular queue
void display()
{       int y=front;
	printf("\nElements in the queue are:-\n");
	while(y!=c)
	{	printf("%d\t",a[y]);
		y++;
	}
	if(rear<=front)
	{	y=rear;
		while(y!=front)
		{	printf("%d\t",a[y]);
			y++;
		}
	}
	getch();
}