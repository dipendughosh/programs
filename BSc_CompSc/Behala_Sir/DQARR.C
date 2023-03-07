//dequeue  using array,ok
#include<stdio.h>
#include<conio.h>
#define MAX 50

int a[50],left=-1,right=MAX;

void qinsert();
void qdelete();
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
				if(left==-1 || right==-1)
					break;
				else
					additem();
				break;
			case 3:
				if(left==-1 || right==-1)
					break;
				else
					qdelete();
				break;
			case 4:
				if(left==-1 || right==-1)
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

void qinsert()
{       int x,ch,i;
	if(MAX-right+left+1>=MAX-1)
	{	printf("\nFULL");
		getch();
		return;
	}
	else
	{	printf("\nEnter element to insert");
		scanf("%d",&x);
		printf("From which end to enter(1-Front,2-Rear):- ");
		scanf("%d",&ch);
		if(ch==1)
		{	for(i=left;i>=0;i--)
				a[i+1]=a[i];
			left++;
			a[0]=x;
		}
		else if(ch==2)
		{	for(i=right;i<MAX;i++)
				a[i-1]=a[i];
			right--;
			a[MAX-1]=x;
		}
		else
			printf("\nWrong input");
	}
}

void qdelete()
{       int ch,i;
	if(left==-1 && right==MAX)
	{	printf("\nEMPTY");
		getch();
		return;
	}
	else
	{	printf("\nWhich to delete from(1-Front,2-Rear):- ");
		scanf("%d",&ch);
		if(ch==1)
		{	if(left!=-1)
			{	printf("\nDleted element = %d",a[0]);
				for(i=0;i<left;i++)
					a[i]=a[i+1];
				left--;
			}
			else
			{	printf("\nDleted element = %d",a[right]);
				right++;
			}

		}
		else if(ch==1)
		{	if(right!=MAX-1)
			{	printf("\nDleted element = %d",a[MAX-1]);
				for(i=MAX-1;i>right;i++)
					a[i]=a[i-1];
				right++;
			}
			else
			{	printf("\nDleted element = %d",a[left]);
				left--;
			}

		}
		else
		printf("\nWrong input");
	}
	getch();
}

void create()
{	qinsert();
}

void additem()
{	qinsert();
}

void display()
{       int y=0;
	while(y<=MAX)
	{	printf("%d\t",a[y]);
		y++;
	}
	getch();
}