/*INFIX TO POSTFIXT CONVERSION OK */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50
int top=-1;
void main()
{
char str[MAX],str1[MAX],str2[MAX];
int i,l,n=0;
clrscr();
printf("ENTER THE  charecter INFIX EXPRESSION\n ");
gets(str);
l=strlen(str);
str[l]=')';str[l+1]='\0';
top=top+1;
str1[top]='(';
i=0;
while(str[i]!='\0')
{
if(str[i]=='(')
{                          /*IF THE ELEMENT IS '('*/
top+=1;
str1[top]=str[i];
}
else if(str[i]!='$'&&str[i]!='*'&&str[i]!='/'&&str[i]!='+'&&str[i]!='-'&&str[i]!=')')
{
str2[n]=str[i];n++;                /* IF THE ELEMENT IS A OPERAND*/
}
else
{                                  /*IF THE ELEMENT IS A OPERATOR*/
if(str[i]=='+'||str[i]=='-')
{
while(str1[top]=='+'||str1[top]=='-'||str1[top]=='*'||str1[top]=='/'||str1[top]=='$')
{
str2[n]=str1[top];
n++;
top=top-1;
}
top=top+1;
str1[top]=str[i];
}
else if(str[i]=='*'||str[i]=='/')
{
while(str1[top]=='*'||str1[top]=='/'||str1[top]=='$')
{
str2[n]=str1[top];n++;
top=top-1;
}
top=top+1;
str1[top]=str[i];
}
else if(str[i]=='$')
{
while(str1[top]=='$')
{
str2[n]=str1[top];n++;
top=top-1;
}
top+=1;
str1[top]=str[i];
}
else
{
while(str1[top]!='(')
{
str2[n]=str1[top];
top=top-1;
n+=1;
}
top-=1;
str2[n]='\0';
}
}
i++;
}
i=0;
printf("\n THE POSTFIX EXPRESSION IS\n ");
while(str2[i]!='\0')
{
printf("%c,",str2[i]);
i++;
}
getch();
}
