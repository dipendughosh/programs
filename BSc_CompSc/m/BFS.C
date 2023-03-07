#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0
struct node1
{       char data;
	struct node1 *links;
	struct node2 *cors;
};
struct node2
{       struct node1 *link;
	struct node2 *corrs;
};
void main()
{       struct node1 *s=NULL;
	void insertion(struct node1 **);
	void display(struct node1 *);
	insertion(&s);
	printf("The nodes are:-");
	display(s);
	getch();
}
void insertion(struct node1 **s)
{	int n;
	char dt;
	struct node1 *p,*q,*new1;
	printf("\nEnter the no of nodes");
	scanf("%d",&n);
	while(n!=NULL)
	{       printf("\nEnter the nodes");
		//flush(dt);
		scanf("%c",&dt);
		new1=(struct node1 *)malloc(sizeof(struct node1));
		new1->data=dt;
		new1->links=NULL;
		new1->cors=NULL;
		if((*s)==NULL)
			(*s)=new1;
		else
		{	p=(*s);
			while(p->links!=NULL)
				p=p->links;
			p->links=new1;
		}
		n--;
	}
	p=*s;
	while(p!=NULL)
	{
}
void display(struct node1*s)
{
	struct node1 *p;
	struct node2*q;
	p=s;
	while(p!=NULL)
	{       q=p->cors;
		while(q!=NULL)
		{
			printf("%c",*(q->corrs));
			q=q->corrs;
		}
		p=p->links;
	}
}
