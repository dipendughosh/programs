/* POLYNOMIAL ADDITION OK */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#define NULL 0
typedef struct node
{
 int data;
 int exp;
 struct node *link;
}som;

som* getnode(int,int);
char compare(int ,int);
void padd(void);
som* attach(int,int, som *);

som *head,*a,*b;

void main()
{
 som *ptr,*ptr1,*new1;
 int x,y;
 char z='y';
 printf("*$* Enter the first polinomials data first *$*");
 printf("\n\nenter the value for the 1st node: ");
 printf("\n\nDATA-> ");
 scanf("%d",&x);
 printf("\n\nEXPONENTIAL-> ");
 scanf("%d",&y);
 a=getnode(x,y);
 printf("\nwant to continue again?(y/n): ");
 fflush(stdin);
 z=getche();
 while(z=='y'||z=='Y')
 {
  printf("\n\nenter the value for new the node: ");
  printf("\n\nDATA-> ");
  scanf("%d",&x);
  printf("\n\nEXPONENTIAL-> ");
  scanf("%d",&y);
  new1=getnode(x,y);
  ptr=a;
  while(ptr->link!=NULL)
	 ptr=ptr->link;
  ptr->link=new1;
  if(new1->exp)
  {
   printf("\n\nwant to continue again?(y/n): ");
   fflush(stdin);
   z=getche();
  }
  else
   z='n';
  }
 printf("\n\n*$* Enter the second polinomials data now *$*");
 printf("\n\nenter the value for the 1st node: ");
 printf("\n\nDATA-> ");
 scanf("%d",&x);
 printf("\n\nEXPONENTIAL-> ");
 scanf("%d",&y);
 b=getnode(x,y);
 printf("\nwant to continue again?(y/n): ");
 fflush(stdin);
 z=getche();
 while(z=='y'||z=='Y')
 {
  printf("\n\nenter the value for new the node: ");
  printf("\n\nDATA-> ");
  scanf("%d",&x);
  printf("\n\nEXPONENTIAL-> ");
  scanf("%d",&y);
  new1=getnode(x,y);
  ptr=b;
  while(ptr->link!=NULL)
	 ptr=ptr->link;
  ptr->link=new1;
  if(new1->exp)
  {
   printf("\n\nwant to continue again?(y/n): ");
   fflush(stdin);
   z=getche();
  }
  else
   z='n';
 }
 padd();
 ptr1=head;
 printf("\n\nAfter the summetion,the final polinomial is:\n\n\n\t");
 while(ptr1->link!=NULL)
  {
	printf(" %dx^%d+",ptr1->data,ptr1->exp);
	ptr1=ptr1->link;
  }
  printf(" %dx^%d = 0.",ptr1->data,ptr1->exp);
  getch();
 }

 som* getnode(int x,int y)                      //to create a new node
 {
 som *new1;
 new1=(som*)malloc(sizeof(som));
 new1->data=x;
 new1->exp=y;
 new1->link=NULL;
 return(new1);
}
void padd(void)
 {
  som *p,*q,*d;
  int x;
  p=a;
  q=b;
  head=(som*)malloc(sizeof(som));     //daami program concept
  d=head;
  while(p!=NULL && q!=NULL)
	{
	 switch(compare(p->exp,q->exp))
	  {
		case '=':
		 x=p->data+q->data;
		 if(x!=0)
	{
	 d=attach(x,p->exp,d);
	 p=p->link;
	 q=q->link;
	}
		 break;
		case '>':
		 d=attach(p->data,p->exp,d);
		 p=p->link;
		 break;
		case '<':
		 d=attach(q->data,q->exp,d);
		 q=q->link;
		 break;
	  }
	}
  while(p!=NULL)
	{
	 d=attach(p->data,p->exp,d);
	 p=p->link;
	}
  while(q!=NULL)
	{
	 d=attach(q->data,q->exp,d);
	 q=q->link;
	}
  d->link=NULL;
  p=head;
  head=head->link;
  free(p);
}
som* attach(int item,int expo, som *d)
{
 som *x;
 x=(som*)malloc(sizeof(som));
 x->data=item;
 x->exp=expo;
 d->link=x;
 d=x;
 return(d);
}

char compare(int i1,int i2)
{
 if(i1==i2)
  return('=');
 if(i1>i2)
  return('>');
 if(i1<i2)
  return('<');
}



