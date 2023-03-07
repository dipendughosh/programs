/* cheaking the parenthesis either it is wellformed or not*/

#include<stdio.h>
#include<conio.h>
#define MAX 50
#define NULL 0
int top=-1;
void main()
{
char str[50],str1[MAX];
int i,x,error;
clrscr();
printf("enter the expression");
gets(str);
i=0;
while(str[i]!='\0'&&error!=-1)
{
if(str[i]=='('||str[i]=='{'||str[i]=='[')
{
if(top<MAX-1)
{
top=top+1;
str1[top]=str[i];
}
else
printf("stac is overflow");
}
else
{
if(top!=-1)
{
x=str1[top];
top=top-1;
}
else               /*if the stac is empty*/
x=NULL;
if(x=='(')
x=')';
else if(x=='{')
x='}';
else if(x=='[')
x=']';
if(x==NULL)
error=-1;
else if (x!=str[i])
error=-1;
else
error=0;
}
i++;
}
if(error==0)
{
if(top==-1)
printf("parenthesis are wellformed");
else
printf("parenthesis are not wellformed");
}
else
printf("parenthesis are not wellformed");
getch();
}