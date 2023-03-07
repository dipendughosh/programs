//Hashing

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	char data[50];
	struct node *next;
};

struct index
{
	char ind;
	struct index *ptrr;     //for pointing the nodes
	struct index *ptrb;     //for pointing the next index
};


void main()
{
	char input[10];
	int i,x,ch;
	char c,w;
	struct index *a,*p;
	struct index *head1=NULL;
	struct index *head2;      //for holding the 1st index
	struct node *q,*r;
	struct node *createnode(char input[50]);
	void display(struct index *head2);
	head2=head1;
	clrscr();
	c=97;
	for(i=0;i<26;i++)
	{
		a=(struct index*)malloc(sizeof(struct index));
		a->ind=c ;
		printf("\n%c",c);
		c++;
		head1->ptrb=a;
		a->ptrr=NULL;
		a->ptrb=NULL;
		a=head1;
		printf("\na->%c",a->ind);
	}
	/*do
	{
	printf("\nPress 1 if you want to enter data: ");
	printf("\nPress 2 to display data: ");
	printf("\nPress 3 to exit: ");
	printf(Enter the choice: ")
	scanf("\n%d",&ch);*/
	head1=head2;
	p=head2;
	printf("\nEnter the word: ");
	scanf("%s",input);
	//printf("\n%c",input[0]);
	w=input[0];
	printf("\nw=%c",w);
	/*x=(int)w-65;
	printf("\nx=%d",x); */

	//mapping
	for(i=0;i<26;i++)
	{
	     if(p->ind==w)
	     {
		if(p->ptrr==NULL)
		{
			r=createnode(input);
			p->ptrr=r;
		       //p=head1;
		       display(head2);
		}
		else
		{
			q=p->ptrr;
			while(q->next!=NULL)
				q=q->next;
			r=createnode(input);
			r->next=NULL;
			display(head2);
		 }
	     }
	     else
		p=p->ptrb;
	}
	getch();
}


struct node* createnode(char input[])
{
	struct node* new1;
	int i;
	new1=(struct node*)malloc(sizeof(struct node));
	//p->ptrr=new1;
	for(i=0;i<10;i++)
	{
		new1->data[i]==input[i];
	}
	new1->next=NULL;

	return(new1);
}

void display(struct index *head2)
{
	int i,j;
	struct node *p;
	i=0;
	while(i<26)
	{
		printf("\n%c",head2->ind);
		if(head2->ptrr!=NULL)
		{
			p=head2->ptrr;
			while(p->next != NULL)
			{
				for(j=0;j<10;j++)
				{
					printf("\t%c",p->data[j]);
				}
				p=p->next;
			}
		}
		else
		head2=head2->ptrb;
	}
}

