/* MERGING OF TWO List */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
typedef struct node
	{
	  int data;
	  struct node *link;
	}node;
node* merge(node*,node*);

void main(void)
{
 node*p,*x,*q,*t,*h;
 char c='y';
 clrscr();
 fflush(stdin);
 printf("\n*$*Enter the first list data*$*\n");
 p=(node*)malloc(sizeof(node));
 printf("\n enter the node data  : ");
 scanf("%d",& p->data);
 p->link=NULL;
 t=p;
 printf("\n do you want to creat MORE node?(y/n)   ");
 fflush(stdin);
 c=getche();
 while(c=='y'||c=='Y')
  {
   x=(node*)malloc(sizeof(node));
   printf("\n\n enter the node data  : ");
   scanf("%d",&x->data);
   t->link=x;
   t=x;
   x-> link=NULL;
   printf("\n\n are you want to creat more node?(y/n)   ");
   fflush(stdin);
   c=getche();
  }
 clrscr();
 printf("\n\n\n*$*Enter the second list data*$*\n");
 q=(node*)malloc(sizeof(node));
 printf("\n enter the node data  : ");
 scanf("%d",& q->data);
 q->link=NULL;
 t=q;
 printf("\n do you want to creat MORE node?(y/n)   ");
 fflush(stdin);
 c=getche();
 while(c=='y'||c=='Y')
 {
  x=(node*)malloc(sizeof(node));
  printf("\n\n enter the node data  : ");
  scanf("%d",&x->data);
  t->link=x;
  t=x;
  x->link=NULL;
  printf("\n do you want to creat more node?(y/n)   ");
  fflush(stdin);
  c=getche();
 }
 clrscr();
 printf("\n\n\n\n\tAFTER THE MERGING:->\n\n\t\t\t\t");
 h=merge(p,q);
 t=h;
 while(t!=NULL)
  {
   printf(" %d->", t->data);
   t=t->link;
  }
 printf("NULL");
 getch();
}


node* merge(node*a,node*b)
{
 node*t,*x,*p,*q,*head;
 head=(node*)malloc(sizeof(node));
 head->link=NULL;
 t=head;
 p=a;
 q=b;
 while(p!=NULL && q!=NULL)
  {
   if(p->data>q->data)
    {
     x=(node*)malloc(sizeof(node));
     x->data=q->data;
     t->link=x;
     t=x;
     q=q->link;
    }
   else
    {
     x=(node*)malloc(sizeof(node));
     x->data=p->data;
     t->link=x;
     t=x;
     p=p->link;
    }
  }
 if(p==NULL)
  t->link=q;
 else
  t->link=p;
 t=head;
 head=head->link;
 free(t);
 return(head);
}

