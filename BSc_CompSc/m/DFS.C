#include<stdio.h>
#include<conio.h>
#define NULL 0
struct node1
{
	char data;
	struct node1*link;
	struct node1*cors;
};
struct node2
{
	struct node2*link;
	struct node2*cors;
}
void main()
{
	struct node1 *s;
	char data;
	void insertion(struct node1**);
	void display(struct node1*);
	s=NULL;
	printf("Enter the nodes");
	insertion(&s);
	printf("The nodes are:-")
	display(s);
	getch();
}
void insertion(struct node**s)
{
	int n;
	char data;
	struct node*p,*q,*new1;
	printf("Enter the no of nodes");
	scanf("%d",&n);
	printf("Enter the nodes")
	getchar(data);
	s=p;
	while(n!=NULL)
	{
		s=q;
		s=p;
		while(p==NULL)
		{
			new1=(struct node1*)mallock(sizeof(struct node1));
			new1->data=data;
			new1->link=NULL;
			p=new1;
		}
		q=q->link;
	
		
	


void display(struct node*s)
{
	struct node *p,*q;
	char l;
	int item;
	p=s;
	while(s!=NULL)
	{
		printf("%c",p->data);
		printf("Is there any corresponding nodes?select y/n");
		scanf("%c",l);
		if(l==y)
		{
			q=s;
			while(q!=NULL)
			{
				printf("%d",q->cors->item);
				q=q->cors;
			}
		else
			printf("This node has no corresponding node");
		p=p->link;
	}
}
		