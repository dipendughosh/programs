/* 		         surya rules			*/

/*	      postfix evaluation through variables	*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"
#include"ctype.h"
#include"stdlib.h"


struct stack
{
	char data;
	struct stack *next;
};

void push(struct stack **top,int item)
{
	struct stack *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	temp->data=item;
	temp->next=*top;
	*top=temp;
}

char pop(struct stack **top)
{
	char item;
	struct stack *temp;

	if(*top == NULL)
	{
		printf("stack is empty");

	}
	else
	{
		temp=*top;
		item=temp->data;
		(*top)=temp->next;
		free(temp);
		return(item);
	}

	return('\0');
}


int operate(int operand_2,char _operator,int operand_1)
{
	int result;
	switch(_operator)
	{
		case '+':
			result=(operand_2)+(operand_1);
			break;
		case '-':
			result=(operand_2)-(operand_1);
			break;
		case '*':
			result=(operand_2)*(operand_1);
			break;
		case '/':
			result=(operand_2)/(operand_1);
			break;
		case '%':
			result=(operand_2)%(operand_1);
			break;
	 }

	 //result=result-96;

//	 printf("resul_1=%d\n",result);

	 return(result);
}



void main()
{
	char postfix[100],input=0;
	int operand_1,operand_2,result,postfix_value;
	int i=0,value;
	struct stack *top;
	top=NULL;
	clrscr();
	printf("enter the postfix expression:\n ");
	while(input != '\n')
	{
		printf("enter operator/operand (enter to stop): ");
		fflush(stdin);
		scanf("%c",&input);
		postfix[i++]=input;
		//printf("postfix=%c\n",postfix[i]);

	}

	postfix[i]='\0';
	printf("\n\n the postfix expression is  ");puts(postfix);

	i=0;
	while(i<strlen(postfix))
	{
		if(isalpha(postfix[i]))
		{
			printf("enter the value of %c: ",postfix[i]);
			scanf("%d",&value);
			postfix[i]=itoa(value,postfix[i],10);
		}
		i++;
	}

	printf("\n\n the postfix expression is  ");puts(postfix);

	for(i=0;i<12;i++)
		printf("postfix[%d]= %d\n",i,postfix[i]);
	i=0;

	while(i<strlen(postfix)-1)
	{
		//printf("\nindia..........................");

		if(!(isalpha(postfix[i])) /* >= 48 && postfix[i] <= 57*/)
		{
			push(&top,(int)(postfix[i]));

		}

		else/*while(isdigit(postfix[i]) <= 0)*/
		{
			operand_1=pop(&top);
			operand_2=pop(&top);
			printf("operand_2=%d   ",operand_2);
			printf("symbol= %c  ",postfix[i]);
			printf("operand_1=%d   ",operand_1);


			result=operate(operand_2,postfix[i],operand_1);
			//result=result+48;
			printf("result=%d \n",result);
			push(&top,result);
		}

		i++;
	}

	postfix_value=pop(&top);

	printf("\n\n the required postfix value is: %d",postfix_value);

	getch();

}



