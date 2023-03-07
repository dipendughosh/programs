//priority q using array,ok
#include<stdio.h>
#include<conio.h>

struct pqueue
{	int data;
	int priority;
};
struct pqueue a[50];
int front=-1,rear=-1,max=50;

void qinsert(int,int);
int qdelete();
void create();
void additem();
void display();

void main()
{       int c,i;
	do
	{	clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Queue");
		printf("\n\t2.Add Item");
		printf("\n\t3.Delete Item");
		printf("\n\t4.Display Queue");
		printf("\n\t5.Exit");
		printf("\n\tEnter choice:-");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				create();
				break;
			case 2:
				if(front==-1 || rear==-1)
					break;
				else
					additem();
				break;
			case 3:
				if(front==-1 || rear==-1)
					break;
				else
					qdelete();
				break;
			case 4:
				if(front==-1 || rear==-1)
					break;
				else
					display();
				break;
			case 5:
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

void qinsert(int item,int pro)
{	if(front==-1)
		front=rear=0;
	else if(rear==max-1)
	{	printf("\nQueue is Full");
		return;
	}
	else
		rear++;
	a[rear].data=item;
	a[rear].priority=pro;
}

int qdelete()
{       int c,pos,min;
	if(front==-1)
	{	printf("\nEMPTY");
		return;
	}
	else if(front==rear)
	{	printf("\nDeleted element is :- %d",a[rear].data);
		rear=front=-1;
	}
	else
	{	min=a[front].priority;
		pos=front;
		c=front+1;
		while(c<rear)
		{	if(min>a[c].priority)
			{	min=a[c].priority;
				pos=c;
			}
			c++;
		}
		printf("\nDeleted element is :- %d",a[pos].data);
		for(c=pos;c<rear;c++)
		{	a[c].data=a[c+1].data;
			a[c].priority=a[c+1].priority;
		}
		rear=rear-1;
	}
	getch();
	return;
}

void create()
{	int item,pos;
	printf("Enter Element :- ");
	scanf("%d",&item);
	printf("Enter Priority of Element (-999 to stop) :- ");
	scanf("%d",&pos);
	qinsert(item,pos);
}

void additem()
{	int x,pos;
	printf("\nAdd Item to List");
	printf("\nEnter Element to Add  :- ");
	scanf("%d",&x);
	printf("Enter Priority of Element (-999 to stop) :- ");
	scanf("%d",&pos);
	qinsert(x,pos);
}

void display()
{       int y=front;
	while(y<=rear)
	{	printf("%d\t",a[y].data);
		y++;
	}
	printf("\n");
	y=front;
	while(y<=rear)
	{	printf("%d\t",a[y].priority);
		y++;
	}
	getch();
}