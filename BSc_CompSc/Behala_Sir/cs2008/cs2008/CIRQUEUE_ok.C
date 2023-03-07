
/* Program of circular queue using array*/
# include<stdio.h>
# define MAX 5

int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert();
void del();
void display();
void main()
{
	int choice;
	while(1)
	{
		clrscr();
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			insert();
			break;
		case 2 :
			del();
			break;
		case 3:
			display();
			getch();
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice\n");
			getch();
		}/*End of switch*/
	}/*End of while */
}/*End of main()*/

void insert()
{
	int added_item;
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("Queue Overflow \n");
		getch();
		return;
	}
	if (front == -1)  /*If queue is empty */
	{
		front = 0;
		rear = 0;
	}
	else
		if(rear == MAX-1)/*rear is at last position of queue */
			rear = 0;
		else
			rear = rear+1;
	printf("Input the element for insertion in queue : ");
	scanf("%d", &added_item);
	cqueue_arr[rear] = added_item ;
}/*End of insert()*/

void del()
{
	if (front == -1)
	{
		printf("Queue Underflow\n");
		getch();
		return ;
	}
	printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
	getch();
	if(front == rear) /* queue has only one element */
	{
		front = -1;
		rear=-1;
	}
	else
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
}/*End of del() */

void display()
{
	int front_pos = front,rear_pos = rear;
	if(front == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	}/*End of else */
	printf("\n");
}/*End of display() */

