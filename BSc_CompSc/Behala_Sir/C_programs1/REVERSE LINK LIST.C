//reversing of single linked list
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
som* invertion(som*);
void main(void)
{
 som *p,*t,*x;
 char a='y';
 clrscr();
 fflush(stdin);
 p=(som*)malloc(sizeof(som));
 printf("\nenter the value for the node: ");
 scanf("%d",&p->data);
 p->link=NULL;
 t=p;
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
 printf("\n\nYour entered list: ");
 t=p;
 while(t!=NULL)
 {
  printf(" %d->",t->data);
  t=t->link;
 }
 printf("NULL.");
 p=invertion(p);
 printf("\n\nAfter invertion: ");
 t=p;
 while(t!=NULL)
 {
  printf(" %d->",t->data);
  t=t->link;
 }
 printf("NULL.");
 getch();
}
som* invertion(som *h)
{
 som *t,*ptr,*h2;
 t=h;
 while(t->link!=NULL)
  t=t->link;
 h2=ptr=t;
 while(ptr!=h)
  {
   t=h;
   while(t->link!=ptr)
    t=t->link;
   ptr->link=t;
   ptr=t;
  }
 ptr->link=NULL;
 return(h2);
}


