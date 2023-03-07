//Stack using array
#include<stdio.h>
#include<conio.h>

//Structure of a single cell of the stack array
struct stack
{	int a[100];
	int top;
};

//Declaring functions
struct stack push(struct stack);
struct stack pop(struct stack);
void displaystack(struct stack);

void main()
{       //Declaring variables
	struct stack s;
	int c,i;
	clrscr();
	s.top=-1;
	do
	{	printf("\n\t\tM E N U");
		printf("\n\t1.PUSH");
		printf("\n\t2.POP");
		printf("\n\t3.Display Stack");
		printf("\n\t4.Exit");
		printf("\n\tEnter choice:-");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(s.top==99)
					printf("\nStack Full\n");
				else
					s=push(s);
				break;
			case 2:
				if(s.top==-1)
					printf("\nStack Empty");
				else
					s=pop(s);
				break;
			case 3:
				if(s.top==-1)
					printf("\nStack does not exist");
				else
					displaystack(s);
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

//Push function to push a data into the stack
struct stack push(struct stack x)
{	printf("\nEnter value - ");
	x.top=x.top+1;
	scanf("%d",&x.a[x.top]);
	return(x);
}

//Pop function to pop a data from the stack
struct stack pop(struct stack x)
{	printf("\nPoped data - %d",x.a[x.top]);
	getch();
	x.top=x.top-1;
	return(x);
}

//Function to display the elements present in the stack
void displaystack(struct stack x)
{       int y=x.top;
	printf("\nThe elements of the stack are :-");
	while(y!=-1)
	{	printf("\n%d",x.a[y]);
		y--;
	}
	getch();
}