//To check if a given set of parenthesis string is valid or not
#include<stdio.h>
#include<conio.h>


void main()
{       char str[20],stk[20];
	int tp=-1,len,i,f;
	clrscr();
	do
	{       printf("\nEnter a parenthesis string :- ");
		gets(str);
		len=strlen(str);
		for(i=0;i<len;i++)
		{	if(str[i]=='(' || str[i]==')' || str[i]=='{' || str[i]=='}' || str[i]=='[' || str[i]==']')
				f=0;
			else
			{	printf("\nRe Enter");
				f=1;
				break;
			}
		}
	}while(f);
	f=1;
	for(i=0;i<len;i++)
	{	if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{	stk[++tp]=str[i];
			f=1;
		}
		else if(str[i]==')' && stk[tp]=='(')
		{	f=1;
			--tp;
		}
		else if(str[i]=='}' && stk[tp]=='{')
		{	f=1;
			--tp;
		}
		else if(str[i]==']' && stk[tp]=='[')
		{	f=1;
			--tp;
		}
		else
		{	f=0;
			break;
		}
	}
	if(f==0)
		printf("\nEntered parentheses string is not valid in logical sense");
	else
		printf("\nEnter stirng is valid");
	getch();
}

