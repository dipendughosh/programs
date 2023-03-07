//double lenear link list all(passing head),ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{       struct node *previous;
	int data;
	struct node *next;
};

struct node* getnode(int x)
{      	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->previous=NULL;
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       struct node *head=NULL,*tail=NULL;
	int c,i,c1,c2;
/*1*/	void create(struct node **,struct node **);
/*2*/	void append(struct node *,struct node **);
/*3*/	void display(struct node *,struct node *);
/*4*/	void insertatbeg(struct node **);
/*5*/	void insertatend(struct node **);
/*6*/	void insertbefor(struct node **);
/*7*/	void insertaftr(struct node **);
/*8*/	void deleteatbeg(struct node **);
/*9*/	void deleteatend(struct node **);
/*10*/	void deleteanywhr(struct node **,struct node **);
/*11*/	void reverse(struct node **,struct node **);
/*12*/	void erase(struct node **,struct node **);
/*1311*/void desndsrtv(struct node *);
/*1312*/void asendsrtv(struct node *);
/*1321*/void desndsrtn(struct node **,struct node **);
/*1322*/void asendsrtn(struct node **,struct node **);
/*14*/	void search(struct node *);
/*15*/	void count(struct node *);
/*16*/	void frequency(struct node *);
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
		printf("\n\t13.Sort");
		printf("\n\t14.Search");
		printf("\n\t15.Count");
		printf("\n\t16.Frequency");
		printf("\n\t17.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		clrscr();
		switch(c)
		{	case 1:
				if(head!=NULL && tail!=NULL)
				{	printf("\nList Exists");
					break;
				}
				else
					create(&head,&tail);
				break;
			case 2:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					append(head,&tail);
				break;
			case 3:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
				{	display(head,tail);
					getch();
				}
				break;
			case 4:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertatbeg(&head);
				break;
			case 5:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertatend(&tail);
				break;
			case 6:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertbefor(&head);
				break;
			case 7:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertaftr(&tail);
				break;
			case 8:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					deleteatbeg(&head);
				break;
			case 9:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					deleteatend(&tail);
				break;
			case 10:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					deleteanywhr(&head,&tail);
				break;
			case 11:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					reverse(&head,&tail);
				break;
			case 12:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					erase(&head,&tail);
				break;
			case 13:
				if(head==NULL && tail==NULL)
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
									desndsrtn(&head,&tail);
									break;
								case 2:
									asendsrtn(&head,&tail);
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
			case 14:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					search(head);
				break;
			case 15:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					count(head);
				break;
			case 16:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					frequency(head);
				break;
			case 17:
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
void create(struct node **h,struct node **t)
{	struct node *new1;
	int x;
	printf("\n\tCreating List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	*h=new1;
	*t=new1;
}

/*2*/
void append(struct node *h,struct node **t)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tAppending List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=h;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	new1->previous=ptr;
	ptr->next=new1;
	*t=new1;
}

/*3*/
void display(struct node *h,struct node *t)
{       struct node *ptr;
	int c;
	printf("\n\tDisplaying List Items:-\n");
	printf("\t1.Forward Display\n\t2.Backward Display\n\tEnter Choice : - ");
	scanf("%d",&c);
	switch(c)
	{	case 1:
			ptr=h;
			while(ptr!=NULL)
			{	printf("%d\t",ptr->data);
				ptr=ptr->next;
			}
			break;
		case 2:
			ptr=t;
			while(ptr!=NULL)
			{	printf("%d\t",ptr->data);
				ptr=ptr->previous;
			}
			break;
		default:
			printf("\nWrong input");
			break;
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
	(*h)->previous=new1;
	new1->next=*h;
	*h=new1;
}

/*5*/
void insertatend(struct node **t)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tInserting Element at End:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	(*t)->next=new1;
	new1->previous=*t;
	*t=new1;
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
	{       (*h)->previous=new1;
		new1->next=(*h);
		*h=new1;
		return;
	}
	while(ptr->next!=NULL)
	{       if(ptr->next->data==x)
		{	new1->next=ptr->next;
			new1->previous=ptr;
			ptr->next->previous=new1;
			ptr->next=new1;
			return;
		}
		ptr=ptr->next;
	}
	printf("%d does not exists",x);
}

/*7*/
void insertaftr(struct node **t)
{	int x,y;
	struct node *new1,*ptr;
	printf("\n\tInserting Element After a Node:-");
	printf("\nEnter Node after which to add - ");
	scanf("%d",&x);
	printf("\nEnter value - ");
	scanf("%d",&y);
	new1=getnode(y);
	ptr=*t;
	if((*t)->data==x)
	{	new1->previous=(*t);
		(*t)->next=new1;
		*t=new1;
		return;
	}
	while(ptr->previous!=NULL)
	{       if(ptr->previous->data==x)
		{	new1->previous=ptr->previous;
			new1->next=ptr;
			ptr->previous->next=new1;
			ptr->previous=new1;
			return;
		}
		ptr=ptr->previous;
	}
	printf("%d does not exists",x);
}

/*8*/
void deleteatbeg(struct node **h)
{       struct node *ptr;
	printf("\n\tDeleting Element at Begining:-");
	printf("\nDeleted Element is %d",(*h)->data);
	ptr=*h;
	(*h)->next->previous=(*h)->previous;
	(*h)=(*h)->next;
	free(ptr);
	getch();
}

/*9*/
void deleteatend(struct node **t)
{       struct node *ptr;
	printf("\n\tDeleting Element at End:-");
	printf("\nDeleted Element is %d",(*t)->data);
	ptr=*t;
	(*t)->previous->next=(*t)->next;
	(*t)=(*t)->previous;
	free(ptr);
	getch();
}

/*10*/
void deleteanywhr(struct node **h,struct node **t)
{       struct node *ptr,*ptr1,*ptr2;
	int x;
	printf("\n\tDeleting Element AnyWhere in the List:-");
	printf("\nEnter Value to delete - ");
	scanf("%d",&x);
	if(*h==*t && (*h)->data==x)
	{	free(*h);
		*h=*t=NULL;
		return;
	}
	if((*h)->data==x)
	{	ptr=*h;
		(*h)->next->previous=(*h)->previous;
		(*h)=(*h)->next;
		free(ptr);
		return;
	}
	if((*t)->data==x)
	{	ptr=*t;
		(*t)->previous->next=(*t)->next;
		(*t)=(*t)->previous;
		free(ptr);
		return;
	}
	ptr1=ptr2=*h;
	while(ptr1->next!=NULL && ptr1->data!=x)
	{	ptr2=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1->data==x)
	{	ptr2->next=ptr1->next;
		ptr1->next->previous=ptr2;
		free(ptr1);
		return;
	}
	printf("\n%d not found in list",x);
	getch();
}

/*11*/
void reverse(struct node **h,struct node **t)
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
	(*h)->previous=NULL;
	ptr1=(*h);
	while(ptr1->next!=NULL)
	{	ptr1->next->previous=ptr1;
		ptr1=ptr1->next;
	}
	(*t)=ptr1;
}

/*12*/
void erase(struct node **h,struct node **t)
{	struct node *ptr;
	printf("\n\tErasing List");
	while((*h)!=NULL)
	{	ptr=(*h);
		(*h)=(*h)->next;
		free(ptr);
	}
	(*h)=(*t)=NULL;
}


/*13 1 1*/
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

/*13 1 2*/
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

/*13 2 1*/
void desndsrtn(struct node **h,struct node **t)
{       struct node *ptr,*ptr1,*ptr2,*new1;
	printf("\n\tDescending order sorting");
	new1=getnode(32767);
	new1->next=(*h);
	(*h)=new1;
	ptr=(*h);
	*h=NULL;
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
		if(*h==NULL)
		{	*h=new1;
			*t=new1;
		}
		else
		{	ptr1=*h;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			new1->previous=ptr1;
			ptr1->next=new1;
			*t=new1;
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
}

/*13 2 2*/
void asendsrtn(struct node **h,struct node **t)
{       struct node *ptr,*ptr1,*ptr2,*new1;
	printf("\n\tAscending order sorting");
	new1=getnode(-32767);
	new1->next=(*h);
	(*h)=new1;
	ptr=(*h);
	*h=NULL;
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
		if(*h==NULL)
		{	*h=new1;
			*t=new1;
		}
		else
		{	ptr1=*h;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			new1->previous=ptr1;
			ptr1->next=new1;
			*t=new1;
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
}

/*14*/
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
		printf("\n%d is not present in the list",x);
}

/*15*/
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

/*16*/
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

