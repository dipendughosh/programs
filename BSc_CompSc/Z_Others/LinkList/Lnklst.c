//ss
//single link list all(passing head),ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
};

struct node* getnode(int x)
{      	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       struct node *head=NULL,*head2=NULL;
	int c,i,c1,c2;
/*1*/	void create(struct node **);
/*2*/	void append(struct node *);
/*3*/	void display(struct node *,struct node *);
/*4*/	void insertatbeg(struct node **);
/*5*/	void insertatend(struct node *);
/*6*/	void insertbefor(struct node **);
/*7*/	void insertaftr(struct node *);
/*8*/	void deleteatbeg(struct node **);
/*9*/	void deleteatend(struct node *);
/*10*/	void deleteanywhr(struct node **);
/*11*/	void reverse(struct node **);
/*12*/	void erase(struct node **);
/*13*/	void copy(struct node *,struct node **);
/*1411*/void desndsrtv(struct node *);
/*1412*/void asendsrtv(struct node *);
/*1421*/void desndsrtn(struct node **);
/*1422*/void asendsrtn(struct node **);
/*15*/	void search(struct node *);
/*16*/	void count(struct node *);
/*17*/	void frequency(struct node *);
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Append");
		printf("\n\t3.Display");
		printf("\n\t4.Insert Begin");
		printf("\n\t5.Insert End");
		printf("\n\t6.Insert Before");
		printf("\n\t7.Insert After");
		printf("\n\t8.Delete Begin");
		printf("\n\t9.Delete End");
		printf("\n\t10.Delete Anywhere");
		printf("\n\t11.Reverse");
		printf("\n\t12.Erase");
		printf("\n\t13.Copy");
		printf("\n\t14.Sort");
		printf("\n\t15.Search");
		printf("\n\t16.Count");
		printf("\n\t17.Frequency");
		printf("\n\t18.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		clrscr();
		switch(c)
		{	case 1:
				if(head!=NULL)
				{	printf("\nList Exists");
					break;
				}
				else
					create(&head);
				break;
			case 2:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					append(head);
				break;
			case 3:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
				{	display(head,head2);
					getch();
				}
				break;
			case 4:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertatbeg(&head);
				break;
			case 5:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertatend(head);
				break;
			case 6:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertbefor(&head);
				break;
			case 7:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertaftr(head);
				break;
			case 8:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					deleteatbeg(&head);
				break;
			case 9:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					deleteatend(head);
				break;
			case 10:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					deleteanywhr(&head);
				break;
			case 11:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					reverse(&head);
				break;
			case 12:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					erase(&head);
				break;
			case 13:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					copy(head,&head2);
				break;
			case 14:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
				{	clrscr();
					printf("\n\t1.Sort Value");
					printf("\n\t2.Sort Node Positions");
					printf("\n\n\tEnter Your choice");
					scanf("%d",&c1);
					switch(c1)
					{	case 1:
							clrscr();
							printf("\n\t1.Descending");
							printf("\n\t2.Ascending");
							printf("\n\n\tEnter Choice : - ");
							scanf("%d",&c2);
							switch(c2)
							{	case 1:
									desndsrtv(head);
									break;
								case 2:
									asendsrtv(head);
									break;
								default:
									printf("\n\n\aWrong input\a");
									break;
							}
							break;
						case 2:
							clrscr();
							printf("\n\t1.Descending");
							printf("\n\t2.Ascending");
							printf("\n\n\tEnter Choice : - ");
							scanf("%d",&c2);
							switch(c2)
							{	case 1:
									desndsrtn(&head);
									break;
								case 2:
									asendsrtn(&head);
									break;
								default:
									printf("\n\n\aWrong input\a");
									break;
							}
							break;
						default:
							printf("\n\n\aWrong input\a");
							break;
					}
				}
				break;
			case 15:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					search(head);
				break;
			case 16:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					count(head);
				break;
			case 17:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					frequency(head);
				break;
			case 18:
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
		getch();
	}while(1);
}

/*1*/
void create(struct node **h)
{	struct node *new1;
	int x;
	printf("\n\tCreating List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	*h=new1;
}

/*2*/
void append(struct node *h)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tAppending List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=h;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new1;
}

/*3*/
void display(struct node *h1,struct node *h2)
{       struct node *ptr;
	printf("\n\tDisplaying List Items:-\n");
	ptr=h1;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	ptr=h2;
	if(ptr!=NULL)
	{       printf("\nCopied List is-:\n");
		while(ptr!=NULL)
		{	printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}

/*4*/
void insertatbeg(struct node **h)
{	int x;
	struct node *new1;
	printf("\n\tInserting Element at Begining:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	new1->next=*h;
	*h=new1;
}

/*5*/
void insertatend(struct node *h)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tInserting Element at End:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=h;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new1;
}

/*6*/
void insertbefor(struct node **h)
{	int x,y;
	struct node *new1,*ptr;
	printf("\n\tInserting Element Before a Node:-");
	printf("\nEnter Node before which to add - ");
	scanf("%d",&x);
	printf("\nEnter value - ");
	scanf("%d",&y);
	new1=getnode(y);
	ptr=*h;
	if((*h)->data==x)
	{	new1->next=(*h);
		*h=new1;
		return;
	}
	while(ptr->next!=NULL)
	{       if(ptr->next->data==x)
		{	new1->next=ptr->next;
			ptr->next=new1;
			return;
		}
		ptr=ptr->next;
	}
	printf("%d does not exists",x);
}

/*7*/
void insertaftr(struct node *h)
{	int x,y;
	struct node *new1,*ptr;
	printf("\n\tInserting Element After a Node:-");
	printf("\nEnter Node after which to add - ");
	scanf("%d",&x);
	printf("\nEnter value - ");
	scanf("%d",&y);
	new1=getnode(y);
	ptr=h;
	while(ptr!=NULL)
	{	if(ptr->data==x)
		{	new1->next=ptr->next;
			ptr->next=new1;
			return;
		}
		ptr=ptr->next;
	}
	printf("%d does not exists",x);
}

/*8*/
void deleteatbeg(struct node **h)
{       struct node *ptr;
	printf("\n\tDeleting Element at Begining:-");
	printf("\nDeleted Element is %d",(*h)->data);
	ptr=*h;
	(*h)=(*h)->next;
	free(ptr);
	getch();
}

/*9*/
void deleteatend(struct node *h)
{       struct node *ptr1,*ptr2;
	printf("\n\tDeleting Element at End:-");
	ptr1=h;
	ptr2=h;
	while(ptr2->next!=NULL)
	{	ptr1=ptr2;
		ptr2=ptr2->next;
	}
	ptr1->next=NULL;
	printf("\nDeleted Element is %d",ptr2->data);
	free(ptr2);
	getch();
}

/*10*/
void deleteanywhr(struct node **h)
{       struct node *ptr1,*ptr2;
	int x;
	printf("\n\tDeleting Element AnyWhere in the List:-");
	printf("\nEnter Value to delete - ");
	scanf("%d",&x);
	ptr1=ptr2=*h;
	while(ptr1->next!=NULL && ptr1->data!=x)
	{	ptr2=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1->data==x)
		ptr2->next=ptr1->next;
	if(ptr1==ptr2)
		(*h)=ptr1->next;
	free(ptr1);
	getch();
}

/*11*/
void reverse(struct node **h)
{       struct node *ptr1,*ptr2,*ptr3;
	printf("\n\tReversing List");
	/*ptr1=*h;
	ptr2=(*h)->next;
	while(ptr1->next!=NULL)
	{       ptr3=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
	}
	(*h)->next=NULL;
	(*h)=ptr3;*/
	ptr3=(*h);
	ptr1=NULL;
	while(ptr3!=NULL)
	{       ptr2=ptr1;
		ptr1=ptr3;
		ptr3=ptr3->next;
		ptr1->next=ptr2;
	}
	(*h)=ptr1;
}

/*12*/
void erase(struct node **h)
{	struct node *ptr;
	printf("\n\tErasing List");
	while((*h)!=NULL)
	{	ptr=(*h);
		(*h)=(*h)->next;
		free(ptr);
	}
}

/*13*/
void copy(struct node *h1,struct node **h2)
{       struct node *ptr,*new1;
	printf("\n\tCoping List");
	(*h2)=getnode(32767);
	ptr=(*h2);
	while(h1!=NULL)
	{	new1=getnode(h1->data);
		ptr->next=new1;
		ptr=new1;
		h1=h1->next;
	}
	new1=(*h2);
	(*h2)=(*h2)->next;
	free(new1);
}

/*14 1 1*/
void desndsrtv(struct node *h)
{       struct node *ptr1,*ptr2;
	int item;
	printf("\n\tDescending order sorting");
	ptr1=h;
	while(ptr1->next!=NULL)
	{       ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->data>=ptr2->data)
			{	item=ptr2->data;
				ptr2->data=ptr1->data;
				ptr1->data=item;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}

/*14 1 2*/
void asendsrtv(struct node *h)
{	struct node *ptr1,*ptr2;
	int item;
	printf("\n\tAscending order sorting");
	ptr1=h;
	while(ptr1->next!=NULL)
	{       ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->data<=ptr2->data)
			{	item=ptr2->data;
				ptr2->data=ptr1->data;
				ptr1->data=item;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}

/*14 2 1*/
void desndsrtn(struct node **h)
{       struct node *ptr,*ptr1,*ptr2,*new1,*head2=NULL;
	printf("\n\tDescending order sorting");
	new1=getnode(32767);
	new1->next=(*h);
	(*h)=new1;
	head2=NULL;
	ptr=(*h);
	while(ptr->next!=NULL)
	{       ptr2=ptr;
		ptr1=ptr->next;
		while(ptr1!=NULL)
		{	if(ptr2->data>=ptr1->data)
			{	ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
				ptr1=ptr1->next;
		}
		new1=getnode(ptr2->data);
		if(head2==NULL)
			head2=new1;
		else
		{	ptr1=head2;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			ptr1->next=new1;
		}
		ptr1=ptr;
		while(ptr1!=NULL)
		{	if(ptr1->next==ptr2)
			{       ptr1->next=ptr2->next;
				free(ptr2);
				break;
			}
			else
				ptr1=ptr1->next;
		}
	}
	free(*h);
	(*h)=head2;
}

/*14 2 2*/
void asendsrtn(struct node **h)
{       struct node *ptr,*ptr1,*ptr2,*new1,*head2=NULL;
	printf("\n\tAscending order sorting");
	new1=getnode(-32767);
	new1->next=(*h);
	(*h)=new1;
	head2=NULL;
	ptr=(*h);
	while(ptr->next!=NULL)
	{       ptr2=ptr;
		ptr1=ptr->next;
		while(ptr1!=NULL)
		{	if(ptr2->data<=ptr1->data)
			{	ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
				ptr1=ptr1->next;
		}
		new1=getnode(ptr2->data);
		if(head2==NULL)
			head2=new1;
		else
		{	ptr1=head2;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			ptr1->next=new1;
		}
		ptr1=ptr;
		while(ptr1!=NULL)
		{	if(ptr1->next==ptr2)
			{       ptr1->next=ptr2->next;
				free(ptr2);
				break;
			}
			else
				ptr1=ptr1->next;
		}
	}
	free(*h);
	(*h)=head2;
}

/*15*/
void search(struct node *h)
{	struct node *ptr;
	int x,pos=0;
	printf("\n\tSearching Element in the List:-\n");
	printf("\nEnter value to search for-:");
	scanf("%d",&x);
	ptr=h;
	while(ptr!=NULL && ptr->data!=x)
	{	pos++;
		ptr=ptr->next;
	}
	if(ptr->data==x)
		printf("\n%d is at node number %d",ptr->data,++pos);
	else
		printf("\n%d is not present in the list",ptr->data);
}

/*16*/
void count(struct node *h)
{       struct node *ptr;
	int cnt=0;
	printf("\n\tCounting List Items:-\n");
	ptr=h;
	while(ptr!=NULL)
	{	cnt++;
		ptr=ptr->next;
	}
	printf("\nNumber of nodes in the List is %d",cnt);
}

/*17*/
void frequency(struct node *h)
{       /*struct node *ptr,*ptr1,*ptr2,*ptr3;
	int i;
	ptr=h;
	while(ptr!=NULL)
	{	ptr2=ptr;
		ptr1=ptr->next;
		i=1;
		while(ptr1!=NULL)
		{	if(ptr->data==ptr1->data)
			{	i++;
				ptr3=ptr1;
				ptr2->next=ptr1->next;
				ptr1=ptr1->next;
				free(ptr3);
			}
			else
			{	ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
		}
		printf("\n%d occors %d times",ptr->data,i);
		ptr=ptr->next;
	} */
	struct frq
	{	int dt;
		int cnt;
	}d[20];
	struct node *ptr;
	int x=0,i,f;
	for(i=0;i<20;i++)
		d[i].cnt=0;
	ptr=h;
	d[0].dt=ptr->data;
	d[0].cnt++;
	x++;
	ptr=ptr->next;
	while(ptr!=NULL)
	{       f=0;
		for(i=0;i<x;i++)
		{	if(ptr->data==d[i].dt)
			{	d[i].cnt++;
				f=1;
			}
		}
		if(f==0)
		{	d[x].dt=ptr->data;
			d[x].cnt++;
			x++;
		}
		ptr=ptr->next;
	}
	for(i=0;i<x;i++)
		printf("\n%d occurs %d times",d[i].dt,d[i].cnt);

	getch();
}

