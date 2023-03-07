//stack using array,Ok
#include<stdio.h>
#include<conio.h>

int a[100],top=-1,max=100;

void push(int);
int pop();
void createstack();
void additem();
void deleteitem();
void displaystack();

void main()
{       int c,i=0;
	do
	{	clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Stack");
		printf("\n\t2.Add Item");
		printf("\n\t3.Delete Item");
		printf("\n\t4.Display Stack");
		printf("\n\t5.Exit");
		printf("\n\tEnter choice:-");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(i==0)
					printf("\nCreating List\n");
				createstack();
				break;
			case 2:
				if(top==-1)
					break;
				else
					additem();
				break;
			case 3:
				if(top==-1)
					break;
				else
					deleteitem();
				break;
			case 4:
				if(top==-1)
					break;
				else
					displaystack();
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

void push(int item)
{	if(top<max-1)
	{	top++;
		a[top]=item;
	}
	else
		printf("\nOverflow");
}

int pop()
{	int y;
	if(top!=-1)
	{	y=a[top];
		top--;
		return y;
	}
	else
		printf("\nUnderflow");
	return(0);
}

void createstack()
{	int item;
	printf("Enter Element to Push :- ");
	scanf("%d",&item);
	push(item);
}

void additem()
{	int x;
	printf("\nAdd Item to List");
	printf("\nEnter Element to Add  :- ");
	scanf("%d",&x);
	push(x);
}

void deleteitem()
{       int x;
	printf("\nDeleting Item from List");
	x=pop();
	printf("\nDeleted Item - %d",x);
	getch();
}

void displaystack()
{       int y=top;
	while(y!=-1)
	{	printf("%d\t",a[y]);
		y--;
	}
	getch();
}