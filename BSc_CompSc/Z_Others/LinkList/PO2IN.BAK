//INPUT:-POSTFIX:-132*+4-
//OUTPUT:-11
#include<stdio.h>
#include<conio.h>

struct stack
{	int data[20];
	int top;
};

void main()
{       struct stack s;
	char post[20];
	int i;
	clrscr();
	s.top=-1;
	i=0;
	printf("Enter Postfix expression(digit & operators)");
	gets(post);
	while(post[i]!='\0')
	{	if(post[i]>='0' && post[i]<='9')
			s.data[++s.top]=post[i]-'0';
		else
		{	switch(post[i])
			{	case '+':
					s.data[s.top-1]=s.data[s.top]+s.data[s.top-1];
					s.top--;
				break;
				case '-':
					s.data[s.top-1]=s.data[s.top]-s.data[s.top-1];
					s.top--;
				break;
				case '*':
					s.data[s.top-1]=s.data[s.top]*s.data[s.top-1];
					s.top--;
				break;
				case '/':
					s.data[s.top-1]=s.data[s.top]/s.data[s.top-1];
					s.top--;
				break;
			}
		 }
		 i++;
	}
	clrscr();
	printf("%s = %d",post,s.data[s.top]);
	getch();
}

