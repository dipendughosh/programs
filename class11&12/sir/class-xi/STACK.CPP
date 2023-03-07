#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

char exp[10];
int stack[10];
void main()
{	clrscr();
	char e;
	int len,i,j=0,a,b,x;
	int calculate(int,int,char);
	cout<<"\nEnter expression->";
	gets(exp);
	len=strlen(exp);
	for(i=0;i<len;i++)
	{	if(isdigit(exp[i]))
		{	stack[j]=exp[i]-48;
			j++;
		}
		else
		{	a=stack[j-1];
			b=stack[j];
			e=exp[i];
			x=calculate(a,b,e);
			stack[j-1]=x;
			j=j-1;
		}
		showstack();cout<<endl;getche();
	}
	cout<<"\nResult="<<stack[0];
	getche();
}

int calculate(int a,int b,char e)
{   int s;
	switch(e)
	{	case '+':
			s=a+b;
			break;
		case '-':
			s=a-b;
			break;
		case '*':
			s=a*b;
			break;
		case '/':
			s=a/b;
			break;
		/*default:
			s=0;
			break;*/
	}
	return s;
}
