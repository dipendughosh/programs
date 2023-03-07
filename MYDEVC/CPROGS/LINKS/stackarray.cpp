#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
int top = -1;
char exp[10],stack[10];
void push(char);
void pop();
void shostack();
void main()
{   cout<<"Enter Expression : "; gets(exp);
    for(int i=0;i<strlen(exp);i++)
        push(exp[i]);
    push('\0');
    shostack();
    for(int j=0;j<strlen(exp);j++)
    {   pop();
        shostack();
        getche();
    }
    cout<<endl;
    system("PAUSE");
}
void push(char c)
{   stack[++top]=c;}
void shostack()
{   for(int x=top;x>=0;x--) cout<<"\t"<<stack[x];
    cout<<endl;
}
void pop() {top--;}
