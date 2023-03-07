/* 		         surya rules			*/

/*	    polynomial addition	and multiplication	*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"

/* structure representing the node of a polynomial linked list */

struct polynode
{
	float coeff;
	int exp;
	struct polynode *next;
};

void poly_append(struct polynode **,float,int);
void poly_addition(struct polynode *,struct polynode *,struct polynode **);
void poly_multiplication(struct polynode *,struct polynode *,struct polynode **);
void poly_add_after_multi(float,int,struct polynode **);
void poly_display(struct polynode *);

void main()
{
	struct polynode *head_1,*head_2,*total,*product;

	int i=0;
	clrscr();
	head_1=head_2=total=product=NULL;

	poly_append(&head_1,1.4,5);
	poly_append(&head_1,1.5,4);
	poly_append(&head_1,1.7,2);
	poly_append(&head_1,1.8,1);
	poly_append(&head_1,1.9,0);

	clrscr();
	poly_display(head_1);

	poly_append(&head_2,1.5,6);
	poly_append(&head_2,2.5,5);
	poly_append(&head_2,-3.5,4);
	poly_append(&head_2,4.5,3);
	poly_append(&head_2,6.5,1);

	printf("\n\n");
	poly_display(head_2);


	printf("\n");
	while(i++<79)
		printf("-");
	printf("\n\n");

	poly_addition(head_1,head_2,&total);
	poly_display(total);

	getch();

	clrscr();
	poly_display(head_1);
	printf("\n\n");
	poly_display(head_2);
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");
	printf("\n\n");

	poly_multiplication(head_1,head_2,&product);
	poly_display(product);

	getch();


}

/* creating the polynomials */

void poly_append(struct polynode **head,float coeff,int exp)
{
	struct polynode *temp;
	temp=*head;

	if(*head==NULL)
	{
		*head=(struct polynode *)malloc(sizeof(struct polynode));
		temp=*head;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=(struct polynode *)malloc(sizeof(struct polynode));
		temp=temp->next;
	}
		temp->coeff=coeff;
		temp->exp=exp;
		temp->next=NULL;


}
/* displaying polynomials */

void poly_display(struct polynode *head)
{
	while(head!=NULL)
	{
		printf("%.1f x^%d : ",head->coeff,head->exp);
		head=head->next;
	}
	printf("\b\b ");
}

/* addition of the two polynomials */

void poly_addition(struct polynode *head_1,struct polynode *head_2,struct polynode **total)
{

	struct polynode *temp;

	if(head_1==NULL && head_2==NULL)
		return;

	while(head_1!=NULL && head_2!=NULL)
	{
		if(*total==NULL)
		{
			*total=(struct polynode *)malloc(sizeof(struct polynode));
			temp=*total;
		}
		else
		{
			temp->next=(struct polynode *)malloc(sizeof(struct polynode));
			temp=temp->next;
		}

		/* storing a term of the larger degree polynomial */

		if(head_1->exp < head_2->exp)
		{
			temp->coeff=head_2->coeff;
			temp->exp=head_2->exp;
			head_2=head_2->next;
		}
		else
		{
			if(head_1->exp > head_2->exp)
			{
				temp->coeff=head_1->coeff;
				temp->exp=head_1->exp;
				head_1=head_1->next;
			}
			else
			{
				/* adding the coefficients when the exponents are equal */

				if(head_1->exp == head_2->exp)
				{
					temp->coeff=head_1->coeff+head_2->coeff;
					temp->exp=head_1->exp;
					head_1=head_1->next;
					head_2=head_2->next;
				}
			}
		}
	}


	/* assigning the remaining terms of the first polynomial to the result */

	while(head_1!=NULL)
	{
		if(*total == NULL)
		{
			*total=(struct polynode *)malloc(sizeof(struct polynode));
			temp=*total;
		}
		else
		{
			temp->next=(struct polynode *)malloc(sizeof(struct polynode));
			temp=temp->next;
		}
		temp->coeff=head_1->coeff;
		temp->exp=head_1->exp;
		head_1=head_1->next;
	}

	/* assigning remaining terms of the second polynomial to the result */

	while(head_2!=NULL)
	{
		if(*total==NULL)
		{
			*total=(struct polynode *)malloc(sizeof(struct polynode));
			temp=*total;
		}
		else
		{
			temp->next=(struct polynode *)malloc(sizeof(struct polynode));
			temp=temp->next;
		}

		temp->coeff=head_2->coeff;
		temp->exp=head_2->exp;
		head_2=head_2->next;
	}

	temp->next=NULL;
}


/* multiplication of the two polynomials */

void poly_multiplication(struct polynode *head_1,struct polynode *head_2,struct polynode **product)
{
	struct polynode *temp;
	float coeff,exp;

	temp=head_2;
	if(head_1==NULL && head_2==NULL)
		return;

	/* if one list is empty */

	if(head_1==NULL)
	{
		*product=head_2;
	}
	else
	{
		if(head_2==NULL)
		{
			*product=head_1;
		}
		else 	/* if both list exists */
		{
			/* for each term of the first list */
			while(head_1 != NULL)
			{
				/* multiply each term of the second linked list */
				    /*	with a term of the first list */
				while(head_2 != NULL)
				{
					coeff=head_1->coeff*head_2->coeff;
					exp=head_1->exp + head_2->exp;

					head_2=head_2->next;


					/* add the new term to the resultant polynomial */
					poly_add_after_multi(coeff,exp,product);
				}
				head_2=temp;
				head_1=head_1->next;
			}
		}
	}
}

/* adding a term to the polynomial in descending order of the exponent */

void poly_add_after_multi(float coeff,int exp,struct polynode **product)
{
	struct polynode *temp_1,*temp_2=*product;

	if(*product == NULL || exp> (*product)->exp)
	{
		*product=temp_1=(struct polynode *)malloc(sizeof(struct polynode));
		(*product)->coeff=coeff;
		(*product)->exp=exp;
		(*product)->next=temp_2;
	}
	else
	{
		/* traverse the entire list to find the position to insert the new node */

		while(temp_2!=NULL)
		{
			if(temp_2->exp==exp)
			{
				temp_2->coeff=temp_2->coeff + coeff;
				return;
			}
			if(temp_2->exp > exp && (temp_2->next->exp < exp || temp_2->next==NULL))
			{
				temp_1=(struct polynode *)malloc(sizeof(struct polynode));
				temp_1->coeff=coeff;
				temp_1->exp=exp;
				temp_1->next=temp_2->next;
				temp_2->next=temp_1;
				return;
			}
			temp_1->next=NULL;
			temp_2->next=temp_1;
		}
	}

}





