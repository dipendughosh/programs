//INPUT:-POSTFIX:--+3*245
//OUTPUT:-6
#include<stdio.h>
#include<conio.h>

struct stack
{	int data[20];
	int top;
};

void main()
{       struct stack s;
	char pre[20];
	int i;
	clrscr();
	s.top=-1;
	printf("Enter Postfix expression(digit & operators)");
	gets(pre);
	i=strlen(pre)-1;
	while(i>=0)
	{	if(pre[i]>='0' && pre[i]<='9')
			s.data[++s.top]=pre[i]-'0';
		else
		{	switch(pre[i])
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
		 i--;
	}
	clrscr();
	printf("%s = %d",pre,s.data[s.top]);
	getch();
}

