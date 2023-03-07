/* 		         surya rules			*/

/*		    breadth first search		*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"


struct queue
{
	char data;
	struct queue *next;
};

void insert(struct queue **front,struct queue **rear,char item)
{
	struct queue *temp_8;

	temp_8=(struct queue *)malloc(sizeof(struct queue));
	temp_8->data=item;
	temp_8->next=NULL;

	if(*front == NULL)
	{
		*front=temp_8;
	}
	else
	{
		(*rear)->next=temp_8;
	}


}


char delet(struct queue **front,struct queue **rear)
{
	struct queue *temp_9;
	char item;
	if(*front == NULL)
	{
		printf("queue is empty");
	}
	else
	{
		temp_9=*front;
		item=temp_9->data;
		(*front)=temp_9->next;
		free(temp_9);

		if(*front == NULL)
			*rear=NULL;

		return(item);
	}
	return(0);
}



struct edgelist;

struct nodelist
{
	char vertex;
	int status;
	struct nodelist *next;
	struct edgelist *adj;
};

struct edgelist
{
	struct nodelist *vertex1;
	struct edgelist *next1;
};

  /* inserting the vertices of the graph */

    void insert_vertex(struct nodelist **sr,char v)
	   {
		struct nodelist *temp,*temp1;
		temp=(struct nodelist *)malloc(sizeof(struct nodelist));
		temp->vertex=v;
		temp->status=1;
		temp->next=NULL;
		temp->adj=NULL;

		if (*sr==NULL)
			*sr=temp;
		else
		    {
		      temp1=*sr;
		      while(temp1->next!=NULL)
			temp1=temp1->next;
		     temp1->next=temp;
		    }
	    }

	/* finding the location of vertex in a graph */

    struct nodelist * search_vertex(char v,struct nodelist **sr)
	   {
		struct nodelist *temp;
		temp=*sr;
		while(temp->vertex != v && temp->next != NULL)
		    temp=temp->next;
		if(temp->vertex==v)
		   return(temp);
		else
		   return(NULL);
	    }

	/* inserting the adjacent vertices of a vertex */

     void insert_edge(struct nodelist **add,struct nodelist **search)
	     {
		struct edgelist  *temp,*temp1;
		temp=(struct edgelist *)malloc(sizeof(struct edgelist));
		temp->vertex1=*add;
		temp->next1=NULL;

		if ((*search)->adj==NULL)
		    (*search)->adj=temp;
		else
		   {
		    temp1=(*search)->adj;
		    while(temp1->next1 != NULL)
		       temp1=temp1->next1;
		    temp1->next1=temp;
		    }
	       }

void main()
{
	char v,start,item;
	struct nodelist *head,*address,*address1,*search;
	struct edgelist *temp;
	struct queue *front,*rear;
	struct edgelist *travel;
	struct nodelist *travel_2;

	head=NULL;
	clrscr();
	/* taking the vertices as input */
	printf("\n Enter vertex in char(press enter to stop): ");
	fflush(stdin);
	scanf("%c",&v);
	while(v != '\n')
	     {
		insert_vertex(&head,v);
		printf("\n Enter vertex in char(press enter to stop): ");
		fflush(stdin);
		scanf("%c",&v);
	     }

	 /* taking the adjacent vertices as input */
	 search=head;
	 printf("\n\n");
	    do
	       {
		  printf("Enter adjacent vertex of(enter to nil)%c:",search->vertex);
		  fflush(stdin);
		  scanf("%c",&v);
		  if (v != '\n')
		     {
		      address=search_vertex(v,&head);
		      insert_edge(&address,&search);
		     }
		  else
		      {
		      printf("\n\n");
		      search=search->next;
		      }

		} while (search != NULL);

	 search=head;
	 while(search != NULL)
	     {
		printf("%c :",search->vertex);
		temp=search->adj;
		while(temp != NULL)
		     {
		      printf(" %c",temp->vertex1->vertex);
		      temp=temp->next1;
		     }
		printf("\n\n");
		search=search->next;
	      }

	getch();


	/* travelling in bfs */

	front=NULL;
	rear=NULL;

	printf("\n enter the vertex  u want to start travelling from: ");
	fflush(stdin);
	scanf("%c",&start);
	insert(&front,&rear,start);
	address=search_vertex(start,&head);
	address->status=2;
	printf("\n\n\n");

	printf("the required bfs traversal is: ");

	while(front != NULL)
	{
		item=delet(&front,&rear);
		printf("%c ",item);
		address->status=3;

		travel=address->adj;
		travel_2=travel->vertex1;

		address=search_vertex(travel_2->vertex,&head);

		if(address->status != 1)
		{
			travel=travel->next1;
			travel_2=travel->vertex1;
			address=search_vertex(travel_2->vertex,&head);
		}
		while(travel != NULL && address->status == 1)
		{
			insert(&front,&rear,travel_2->vertex);
			address->status=2;
			address1=address;

			travel=travel->next1;

			if(travel == NULL)
				break;

			travel_2=travel->vertex1;

			if(address->status != 1)
				address=address1;
		}
	}

	getch();
}