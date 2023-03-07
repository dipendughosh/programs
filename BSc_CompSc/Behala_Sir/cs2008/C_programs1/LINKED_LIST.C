#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0
struct node{
	int info;
	struct node *next;
};
struct node *head;
struct node* getnode(int x);
void add_list(int x);
void display_list();
int menu();
void insert_at_beg(int x);
void insert_at_mid(int x);
void insert_at_end(int x);
void del_at_beg();
void del_at_mid();
void del_at_end();

void main()
{
	int x,ch;
	clrscr();
	h=NULL;
	printf("Enter value(-999 to stop):");
	scanf("%d",&x);
	while(x!=-999){
		add_list(&h,x);
		printf("Enter value(-999 to stop)");
		scanf("%d",&x);
	}
	display_list(&h);
	do{
		ch=menu();
		switch(ch){
			case 1:
						printf("Enter a value:");
						scanf("%d",&x);
						insert_at_beg(&h,x);
						break;
			case 2:
						printf("Enter a value:");
						scanf("%d",&x);
						insert_at_mid(&h,x);
						break;
			case 3:
						printf("Enter a value:");
						scanf("%d",&x);
						insert_at_end(&h,x);
						break;
			case 4:
						del_at_beg(&h);
						break;
			case 5:
						del_at_mid(&h);
						break;
			case 6:
						del_at_end(&h);
						break;
			case 7:
						display(&h);
						break;
			case 8:
						exit(0);
		}
	}while(1);
}
int menu(){
	int ch;
	printf("MENU--------------CODE\n");
	printf("INSERT_AT_BEG-------1\n");
	printf("INSERT_AT_MID-------2\n");
	printf("INSERT_AT_END-------3\n");
	printf("DEL_AT_BEG----------4\n");
	printf("DEL_AT_MID----------5\n");
	printf("DEL_AT_END----------6\n");
	printf("DISPLAY-------------7\n");
	printf("EXIT----------------8\n");
	printf("What do you want to do?\n");
	scanf("%d",&ch);
	return ch;
}
struct node *getnode(int x){
	struct node *new1;
	new1=(struct node*)malloc(sizeof(struct node));
	new1->info=x;
	new1->next=NULL;
	return new1;
}
void add_list(struct node **h,int x){
	struct node *new1,*ptr;
	new1=getnode(x);
	if(*h==NULL){
		*h=new1;
	}
	else
	{
		ptr=*h;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=new1;
	}
}

void display_list(struct node **h){
	struct node *ptr;
	ptr=*h;
	while(ptr!=NULL){
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
}

void insert_at_beg(struct node **h,int x){
	struct node *new1;
	new1=getnode(x);
	new1->next=*h;
	*h=new1;
}


void insert_at_mid(struct node **h,int x){
	struct node *new1,*ptr;
	int val;
	new1=getnode(x);
	printf("Enter the value before which you want to insert:");
	scanf("%d",&val);
	ptr=*h;
	if(ptr->next->info==val)
		insert_at_beg(h,x);
	else
	{
		while(ptr->next!=NULL && ptr->info!=val)
			ptr=ptr->next;
		if(ptr->info==val){
			new1->next=ptr->next;
			ptr->next=new1;
		}
		else
			printf("Element not found");
	}
}


void insert_at_end(struct node **h,int x){
	struct node *new1,*ptr;
	new1=getnode(x);
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


void del_at_beg(struct node **h){
	struct node *ptr;
	if(*h!=NULL){
		ptr=*h;
		(*h)=(*h)->next;
		free(ptr);
	}
	else
		printf("Linked list not exists");
}


void del_at_mid(struct node **h){
	struct node *ptr1,*ptr2;
	int val;
	printf("Which value you want to delete?");
	scanf("%d",&val);
	ptr1=*h;
	if(ptr1->next->info==val)
		del_at_beg(h);
	else
	{
		ptr1=ptr2=*h;
		while(ptr1->next!=NULL && ptr1->info!=val){
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		if(ptr1->info==val){
			ptr2->next=ptr1->next;
			free(ptr1);
		}
		else
			printf("Element not found");
	}
}


void del_at_end(struct node **h){
	struct node *ptr1,*ptr2;
	ptr1=ptr2=*h;
	while(ptr1->next!=NULL){
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	ptr2->next=NULL;
	free(ptr1);
}
    
    