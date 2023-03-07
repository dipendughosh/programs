/* ADJACENCY LIST FOR GRAPH OK*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0
struct node1;
struct node
{
 int vertex;
 struct node *next;
 struct node1 *adjacent;
};

struct node1
{
  struct node *connect;
  struct node1 *path;
};

void addlist(struct node **h,int x);
void addlist1(struct node **h,struct node **ptr,int y);
void displaylist(struct node **h);

void main()
{
 struct node *head,*ptr;
 int x,y;
 clrscr();
 head=NULL;

 /* ADD NEW VERTEX */
 printf("\n\n\t\tEnter vertex(-999 to stop):");
 scanf("%d",&x);
 while(x!=-999)
 {
  addlist(&head,x);
  printf("\n\n\t\tEnter vertex(-999 to stop):");
  scanf("%d",&x);
 }

 /* ADD ADJACENT VERTICES */
 ptr=head;
 while(ptr!=NULL)
 {
  printf("\nEnter adjacent vertices of %d (-999 to stop):",ptr->vertex);
  scanf("%d",&y);
  while(y!=- 999)
    {
   addlist1(&head,&ptr,y);
   printf("\nEnter adjacent vertices of %d (-999 to stop):",ptr->vertex);
   scanf("%d",&y);
    }
  ptr=ptr->next;
  }

 displaylist(&head);
getch();
}/* END OF MAIN */

void addlist(struct node **h,int x)
{
 struct node *new1,*ptr;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->vertex=x;
 new1->next=NULL;
 new1->adjacent=NULL;
 if(*h==NULL)
   *h=new1;
 else
   {
    ptr=*h;
  while(ptr->next!=NULL)
       ptr=ptr->next;
  ptr->next=new1;
   }
}

void addlist1(struct node **h,struct node **ptr,int y)
{
 struct node1 *new1,*check1;
 struct node *ptr1,*check;
 ptr1=*h;
 check=*ptr;
 while(y!=ptr1->vertex)
    ptr1=ptr1->next;
 new1=(struct node1*)malloc(sizeof(struct node1));
 new1->connect=ptr1;
 new1->path=NULL;
 if(check->adjacent==NULL)
     check->adjacent=new1;
 else
   {
  check1=check->adjacent;
  while(check1->path!=NULL)
       check1=check1->path;
  check1->path=new1;
   }
}

void displaylist(struct node **h)
{
 struct node *ptr;
 struct node1 *ptr1;
 ptr=*h;
 clrscr();
 printf("\n\n");
 printf("\tTHE ADJACENCY LIST ARE\n\n");
 while(ptr!=NULL)
 {
  printf("\t%d : ",ptr->vertex);
  ptr1=ptr->adjacent;
  while(ptr1!=NULL)
    {
   printf(" %d ",*(ptr1->connect));
   ptr1=ptr1->path;
    }
  ptr=ptr->next;
  printf("\n\n");
 }
}