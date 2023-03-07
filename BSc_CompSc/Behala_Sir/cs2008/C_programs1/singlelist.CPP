/* insert into linked list */

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
# define NULL 0

typedef struct node
  {
    int data;
    struct node *next;
  }node;
  node *head;
  node *getnode(int x)
    {
    node *new1;
    new1=(node *)malloc(sizeof(node));
    new1->data=x;
    new1->next=NULL;
    return(new1);
    }

    void create1();
    void insertbeg();
    void insertend();
    void insertmid();
    void display();

    void main()
    {
    int ch;
    do
    {
    clrscr();
    printf("\n1.Create Linked List   \n2.Insert at begining \n3.Insert at end");
    printf("\n4.Insert at middle \n5.Display List  \n6.Exit");
    printf("\n\n\nEnter your choice::\n\n");
    scanf("%d",&ch);
	 switch(ch)
	 {

	 case 1:
	 create1();
	 break;

	 case 2:
	 insertbeg();
	 break;

	 case 3:
	 insertmid();
	 break;

	 case 4:
	 insertend();
	 break;

	 case 5:
	 display();
	 break;

	 case 6:
	 exit(0);
	 }
     }
     while(1);
  } //end of main


    void create1()
    {
    node *new1,*ptr;
    int x;
    printf("Enter an element(-999 to stop)");
    scanf("%d",&x);

    while(x!=-999)
      {
      new1=getnode(x);
      if(head==NULL)
	{
	   head=new1;
	   ptr=new1;
	}
	else
	{
	  ptr->next=new1;
	  ptr=new1;
	}
     printf("Enter an element(-999 to stop)  ");
     scanf("%d",&x);
     }
   }

    void insertbeg()
     {
     node *new1;
     int x;
     printf("Enter the element to be inserted at the begining   ::");
     scanf("%d",&x);
     new1=getnode(x);

       if(head==NULL)
	  head=new1;
       else
	{
	 new1->next=head;
	 head=new1;
	}
     }


    void insertend()
      {
      node *new1,*ptr;
      int x;
      printf("Enter an element to be inserted at the end");
      scanf("%d",&x);
      new1=getnode(x);
      if(head==NULL)
	 head=new1;
      else
       {
	   ptr=head;
	   while(ptr->next!=NULL)
	   {
	   ptr=ptr->next;
	   }
	  ptr->next=new1;
       }
      }

    void insertmid()
      {
      node *new1,*ptr;
      int x,pos,c=1;
      printf("Enter an element to be inserted at the middle  ");
      scanf("%d",&x);
      printf("Enter the position want to insert::");
      scanf("%d",&pos);
      new1=getnode(x);
      if(head==NULL)
	 head=new1;
      else if(pos==1)
	 {
	 new1->next=head;
	 head=new1;
	 }
      else
	{
	ptr=head;
	while(c<pos-1 && ptr->next != NULL)
	  ptr=ptr->next;
	new1->next=ptr->next;
	ptr->next=new1;
	}
     }

    void display()
     {
     node *ptr;
     printf("\n ELEMENTS ARE   ::\n ");
     ptr=head;
     while(ptr!=NULL)
     {
     printf("%d  ",ptr->data);
     ptr=ptr->next;
     }
    getch();
     }


