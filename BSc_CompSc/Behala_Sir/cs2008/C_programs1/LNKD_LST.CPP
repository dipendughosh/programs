#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"process.h"
#include"alloc.h"



#define NULL 0


		/* functions required for all linked list	*/

int choice()
{
	int x;
	gotoxy(30,30);
	printf("enter your choice.........");
	scanf("%d",&x);
	return(x);
}

int take_element()
{

	clrscr();
	int element;
	printf("enter value........");
	scanf("%d",&element);
	return (element);

}



int take_position()
{
	clrscr();
	int position;
	printf("enter position........");
	scanf("%d",&position);
	return (position);
}

void menu_lists();

		/* 	single linked lists declarations	*/

struct single_node
{
	int info;
	struct single_node *next;
};

typedef struct single_node NPTR;






void single_create(NPTR **h,int x);
void single();
void single_delete_beginning(NPTR **h);
void single_delete_middle(NPTR **h,int pos);
void single_delete_end(NPTR **h);
void single_delete();


	NPTR *head=NULL;
	int input;

	NPTR *getnode(int x)
	{
		NPTR *new1;
		new1=(NPTR *)malloc(sizeof(NPTR));
		new1->info=x;
		new1->next=NULL;
		return (new1);
	}


	/* 	doubly linked lists declarations	*/

	struct doubly_node
	{
		struct doubly_node *left,*right;
		int info;
	};

	typedef struct doubly_node NPTR2;

	NPTR2 *head1=NULL;
	NPTR2 *head2=NULL;

	NPTR2 *doubly_getnode(int x)
	{
		NPTR2 *new1;
		new1=(NPTR2 *)malloc(sizeof(NPTR2));
		new1->left=NULL;
		new1->info=x;
		new1->right=NULL;
		return(new1);
	}

	void doubly_create(NPTR2 **h1,NPTR2 **h2,int x);
	void doubly_display(NPTR2 **h1);
	void doubly_insert();
	void doubly_insert_beginning(NPTR2 **h1,int x);
	void doubly_insert_middle(NPTR2 **h1,NPTR2 **h2,int x,int pos);
	void doubly_insert_end(NPTR2 **h2,int x);

	void doubly_delete();
	void doubly();

	void doubly_delete_beginning(NPTR2 **h1);
	void doubly_delete_middle(NPTR2 **h1,NPTR2 **h2,int delele);
	void doubly_delete_end(NPTR2 **h2);

	/* 	functions for doubly linked list	*/


	void doubly_delete_beginning(NPTR2 **h1)
	{
		NPTR2 *ptr;
		ptr=*h1;
		(*h1)=(*h1)->right;
		(*h1)->left=NULL;
		free(ptr);
		doubly_delete();
	}

	void doubly_delete_middle(NPTR2 **h1,NPTR2 **h2,int delele)
	{
		NPTR2 *ptr;
		ptr=*h1;
		while(ptr->info!=delele && ptr->right!=NULL)
		{
			ptr=ptr->right;
		}

		if(ptr->info==(*h1)->info)
		{
			doubly_delete_beginning(h1);
		}
		else if(ptr->info==(*h2)->info)
		{
			doubly_delete_end(h2);
		}
		else if(ptr->info==delele)
		{
			ptr->right->left=ptr->left;
			ptr->left->right=ptr->right;
			free(ptr);
		}
		else
		{
			printf("element not found");
		}

		doubly_delete();
	}

	void doubly_delete_end(NPTR2 **h2)
	{
		NPTR2 *ptr;
		ptr=*h2;
		*h2=(*h2)->left;
		(*h2)->right=NULL;
		free(ptr);
		doubly_delete();
	}

	void doubly_delete()
	{
		clrscr();
		int ch,input;
		gotoxy(35,8);printf("deletion");
		gotoxy(30,13);printf("1.delete from beginning");
		gotoxy(30,15);printf("2.delete from middle");
		gotoxy(30,17);printf("3.delete from end");
		gotoxy(30,19);printf("4.return to previos menu");
		ch=choice();

		switch(ch)
		{
			case 1:
				doubly_delete_beginning(&head1);
				break;
			case 2:
				input=take_element();
				doubly_delete_middle(&head1,&head2,input);
				break;
			case 3:
				doubly_delete_end(&head2);
				break;
			case 4:
				doubly();
				break;
			default:
				doubly_delete();

		}
	}


void doubly_insert()
{
	clrscr();
	int ch,pos,input;

	gotoxy(35,8);printf("insertion");
	gotoxy(30,13);printf("1.insert at beginning");
	gotoxy(30,15);printf("2.insert at middle");
	gotoxy(30,17);printf("3.insert at end");
	gotoxy(30,19);printf("4.return to previos menu");
	ch=choice();

	switch(ch)
	{
		case 1:
			input=take_element();
			doubly_insert_beginning(&head1,input);
			doubly_insert();
			break;

		case 2:
			pos=take_position();
			input=take_element();
			doubly_insert_middle(&head1,&head2,input,pos);
			doubly_insert();
			break;

		case 3:
			input=take_element();
			doubly_insert_end(&head2,input);
			doubly_insert();
			break;

		case 4:
			doubly();
			break;

		default:
			doubly_insert();


	}


}


	void doubly_create(NPTR2 **h1,NPTR2 **h2,int x)
	{
		NPTR2 *new1;
		new1=doubly_getnode(x);
		if(*h1==NULL && *h2==NULL)
		{
			*h1=new1;
			*h2=new1;
		}
		else
		{
			(*h2)->right=new1;
			new1->left=(*h2);
			(*h2)=new1;

		}
	}


	void doubly_display(NPTR2 **h1)
	{
		clrscr();
		NPTR2 *ptr;
		ptr=*h1;
		printf("the list is as follows........ ptr=%d\n",ptr);
		while(ptr!= NULL)
		{
			printf("%d ",ptr->info);
			ptr=ptr->right;
		}
		getch();
		doubly();
	}


	void doubly_insert_end(NPTR2 **h2,int x)
	{
		NPTR2 *new1;
		if(*h2!=NULL)
		{
			new1=doubly_getnode(x);
			new1->left=*h2;
			(*h2)->right=new1;
			*h2=new1;
		}
		else
		{
			printf("list does not exist");
		}

		doubly_insert();
	}

	void doubly_insert_middle(NPTR2 **h1,NPTR2 **h2,int x,int pos)
	{
		NPTR2 *new1,*ptr;
		ptr=*h1;


		doubly_insert();

	}


	void doubly_insert_beginning(NPTR2 **h1,int x)
	{
		NPTR2 *new1;
		if(*h1!=NULL)
		{
			new1=doubly_getnode(x);
			new1->right=*h1;
			(*h1)->left=new1;
			*h1=new1;
		}
		else
		{
			printf("list does not exist");
		}


		doubly_insert();
	}


	/* 	functions for single linked list 	*/


	void single_insert_beginning(NPTR **h,int x)
	{

		NPTR *new1;
		new1=getnode(x);
		new1->next=*h;
		*h=new1;
		single();
	}
	void single_insert_middle(NPTR **h,int x,int pos)
	{
		NPTR *new1,*ptr;
		int count=1;
		if(pos==1)
		{
			single_insert_beginning(h,x);
		}
		else
		{
			ptr=*h;
			while(count<pos-1 && ptr->next!=NULL)
			{
				count++;
				ptr=ptr->next;
			}
			new1=getnode(x);
			new1->next=ptr->next;
			ptr->next=new1;
		}

		single();
	}


	void single_insert_end(NPTR **h,int x)
	{
		single_create(h,x);

		single();
	}


	void single_create(NPTR **h,int x)
	{
		NPTR *new1,*ptr;
		new1=(NPTR *)malloc(sizeof(NPTR));
		new1->info=x;
		new1->next=NULL;

		if(*h==NULL)
		{
			*h=new1;
		}
		else
		{
			ptr=*h;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new1;
		}

	}


void single_display(NPTR **h)
{
	NPTR *ptr;
	ptr=*h;
	clrscr();
	printf("the list is as follows........\n");
	printf("ptr= %d \n",ptr);
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->next;

	}
	getch();

	single();

}


void single_insert()
{
	int ch,pos,input;
	clrscr();
	gotoxy(35,8);printf("insertion");
	gotoxy(30,13);printf("1.insert at beginning");
	gotoxy(30,15);printf("2.insert at middle");
	gotoxy(30,17);printf("3.insert at end");
	gotoxy(30,19);printf("4.return to previos menu");
	ch=choice();

	switch(ch)
	{
		case 1:
			input=take_element();
			single_insert_beginning(&head,input);
			single_insert();
			break;

		case 2:
			pos=take_position();
			input=take_element();
			single_insert_middle(&head,input,pos);
			single_insert();
			break;

		case 3:
			input=take_element();
			single_create(&head,input);
			single_insert();
			break;

		case 4:
			single();
			break;

		default:
			single_insert();


	}
}

void single_delete_beginning(NPTR **h)
{
	NPTR *ptr;
	ptr=*h;
	(*h)=(*h)->next;
	free(ptr);
	single_delete();
}

void single_delete_middle(NPTR **h,int pos)
{
	NPTR *ptr1,*ptr2;
	int count=1;
	if(pos==1)
	{
		single_delete_beginning(h);
	}
	else
	{
		ptr1=ptr2=*h;

		while(count<pos && ptr1!=NULL)
		{
			ptr1=ptr2;
			ptr2=ptr2->next;
			count++;
		}

		ptr1->next=ptr2->next;
		free(ptr2);
	}
	single_delete();
}

void single_delete()
{
	clrscr();
	int ch,input,pos;
	gotoxy(35,8);printf("deletion");
	gotoxy(30,13);printf("1.delete from beginning");
	gotoxy(30,15);printf("2.delete from middle");
	gotoxy(30,17);printf("3.delete from end");
	gotoxy(30,19);printf("4.return to previos menu");
	ch=choice();

	switch(ch)
	{
		case 1:
			single_delete_beginning(&head);
			break;
		case 2:
			pos=take_position();
			single_delete_middle(&head,pos);
			break;
		case 3:
			//single_delete_end(&head);
			break;
		case 4:
			single();
			break;
		default:
			single_delete();
	}

}


void single()
{
	clrscr();
	int ch;


	gotoxy(35,8);printf("single linked list");
	gotoxy(30,13);printf("1.create list");
	gotoxy(30,15);printf("2.display list");
	gotoxy(30,17);printf("3.insert element");
	gotoxy(30,19);printf("4.delete element");
	gotoxy(30,21);printf("5.return to previous menu");
	ch=choice();

	switch(ch)
	{
		case 1:
			input=take_element();
			while(input!=-999)
			{
				single_create(&head,input);
				input=take_element();
			}

			single();

			break;


		case 2:
			single_display(&head);
			break;
		case 3:
			single_insert();
			break;
		case 4:
			single_delete();
			break;
		case 5:
		       menu_lists();
		       break;
		default:
			single();
	}


	getch();
}

void doubly()
{
	clrscr();
	int ch;
	gotoxy(35,8);printf("doubly linked list");
	gotoxy(30,13);printf("1.create list");
	gotoxy(30,15);printf("2.display list");
	gotoxy(30,17);printf("3.insert element");
	gotoxy(30,19);printf("4.delete element");
	gotoxy(30,21);printf("5.return to previos menu");
	ch=choice();

	switch(ch)
	{
		case 1:
			input=take_element();
			while(input!=-999)
			{
				doubly_create(&head1,&head2,input);
				input=take_element();
			}
			doubly();
			break;

		case 2:
			doubly_display(&head1);
			break;

		case 3:
			doubly_insert();
			break;

		case 4:
			doubly_delete();
			break;
		case 5:
			menu_lists();
			break;

		default:
			doubly();
	}
		getch();

}


void circular()
{
	getch();
}


		/* function for main menu	*/


void menu_lists()
{
	clrscr();
	int ch;
	gotoxy(35,8);
	printf("LINKED LISTS");
	gotoxy(30,13);printf("1.SINGLE LINKED LISTS");
	gotoxy(30,15);printf("2.DOUBLY LINKED LISTS");
	gotoxy(30,17);printf("3.CIRCULAR LINKED LISTS");
	gotoxy(30,19);printf("4.EXIT");
	ch=choice();
	switch(ch)
	{
		case 1:
			single();
			break;
		case 2:
			doubly();
			break;
		case 3:
			circular();
			break;
		case 4:
			exit(0);
		default:
			menu_lists();
	}


}



		/*	main function	*/

void main()
{
	clrscr();
	menu_lists();

}