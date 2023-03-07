//sorting in a single linked list
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#define NULL 0
typedef struct node
{
 int data;
 struct node *link;
}som;
som *head;
void bubble_sort(void);
void main(void)
{
 som *t,*x;
 char a='y';
 clrscr();
 fflush(stdin);
 head=(som*)malloc(sizeof(som));
 printf("\nenter the value for the node: ");
 scanf("%d",&head->data);
 head->link=NULL;
 t=head;
 printf("\nwant to continue again?(y/n): ");
 fflush(stdin);
 a=getche();
 while(a=='y'||a=='Y')
 {
  x=(som*)malloc(sizeof(som));
  printf("\n\nenter the value for the node: ");
  scanf("%d",&x->data);
  t->link=x;
  t=x;
  printf("\n\nwant to continue again?(y/n): ");
  fflush(stdin);
  a=getche();
  x->link=NULL;
 }
 bubble_sort();
 printf("\n\nThe sorted order is: \n\n");
 t=head;
 while(t!=NULL)
 {
  printf(" %d->",t->data);
  t=t->link;
 }
 printf("NULL.");
 getch();
}
void bubble_sort(void)
{
 som *p,*q,*r,*s,*temp;
 s=NULL;
 while(s!=head->link)
  {
   r=p=head;
   q=p->link;
   while(p!=s)
    {
     if(p->data>q->data)
      {
       if(p==head)
	{
	 temp=q->link;
	 q->link=p;
	 p->link=temp;
	 head=q;
	 r=q;
	}
       else
       {
	temp=q->link;
	q->link=p;
	p->link=temp;
	r->link=q;
	r=q;
       }
      }
     else
      {
       r=p;
       p=p->link;
      }
      q=p->link;
      if(q==s)
	s=p;
    }
  }
}