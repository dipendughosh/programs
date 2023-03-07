#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
//#include<math.h>

char exp[10];
int a[10];
int cal(int a,int b,char e)
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
		/*case '^':
			s=pow(a,b);
			break;*/
	}
	return s;
}

void main()
{	clrscr();
	int i=0,top=-1;
	cout<<"\nEnter expression->";
	gets(exp);
	while(exp[i]!='\0')
	{	if(isdigit(exp[i]))
			a[++top]=exp[i]-48;
		else
		{	a[top-1]=cal(a[top-1],a[top],exp[i]);
			top--;
		}
		i++;
	}
	cout<<a[0];
	getche();
}



