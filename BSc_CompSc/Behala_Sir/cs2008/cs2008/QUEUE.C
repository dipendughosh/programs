			  /*A PROGRAM OF QUEUE*/
			   /*------------------*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
#define null 0
struct node
{
  int info;
  struct node *next;
};
void addlist(struct node **h,int x);
void displaylist(struct node**h);
struct node *getnode(int x);
void insertatend(struct node **h,int x);
void delatbeg(struct node **h);
void main()
{
  struct node *head;
  int x;
  int n;
  int pos;
  clrscr();
  head=null;
  while(1)
{
  clrscr();
  printf("\n\n\t\t  QUEUE OPERATION");
  printf("\n\n\t\t  ---------------\n\n\t\t");
  printf("\n\n\t\t1.INSERT DATA IN QUEUE\n\n\t\t2.DELETE FROM QUEUE\n\n\t\t3.DISPLAY QUEUE ELEMENTS\n\n\t\t4.EXIT");
  printf("\n\n\t\tPRESS YOUR CHOICE:");
  n=getch();
  switch(n)
  {
  case 49:
   if(head==null)
  {
  printf("\n\n\t\tENTER THE FIRST DATA(-999 TO STOP):");
  scanf("%d",&x);
  while(x!=-999)
  {
   addlist(&head,x);
   printf("\n\n\t\tENTER THE DATA(-999 TO STOP):");
   scanf("%d",&x);
   }
  }
  else
{
  printf("\n\n\t\tENTER THE DATA YOU WANT TO INSERT(-999 TO STOP):");
  scanf("%d",&x);
  while(x!=-999)
  {
  insertatend(&head,x);
  printf("\n\n\t\tENTER THE DATA(-999 TO STOP):");
  scanf("%d",&x);
  }
}
  break;
  case 50:
   if(head==null)
  {
    printf("\n\n\t\tTHE QUEUE DOESN'T EXIST");
  }
  else
  {
  delatbeg(&head);
  }
  getch();
  break;
  case 51:
      displaylist(&head);
      getch();
      break;
  case 52:
      exit(0);
  default:
      printf("\n\n\t\tYOU PRESS WRONG KEY PLEASE RE-ENTER");
      getch();
  }
}
}
void addlist(struct node **h,int x)
{
   struct node *new1,*ptr;
   new1=getnode(x);
   if(*h==null)
   *h=new1;
   else
     {
       ptr=*h;
       while(ptr->next!=null)
       {
	 ptr=ptr->next;
       }
       ptr->next=new1;
     }
}
void displaylist(struct node **h)
{
    struct node *ptr;
    ptr=*h;
    printf("\n\n\t\tTHE QUEUE ARE:");
    printf("\n\n\t\t");
    while(ptr!=null)
    {
      printf("\t%d",ptr->info);
      ptr=ptr->next;
    }
}
struct node *getnode(int x)
{
   struct node *new1;
   new1=(struct node*)malloc(sizeof(struct node));
   new1->info=x;
   new1->next=null;
   return(new1);
}
void insertatend(struct node **h,int x)
{
   struct node *new1,*ptr;
   new1=getnode(x);
   ptr=*h;
   while(ptr->next!=null)
   {
      ptr=ptr->next;
   }
   ptr->next=new1;
}
void delatbeg(struct node **h)
{
   struct node *ptr;
   ptr=*h;
   *h=(*h)->next;
   printf("\n\n\t\t%d IS SUCCESSFULLY DELETED FROM QUEUE",ptr->info);
   free(ptr);
}
