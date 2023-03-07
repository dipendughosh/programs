#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
#include<fstream.h>
struct node
{
       int a;
       node *next;
}*n,*newn,*start,*save;
node * create()
{
     newn=new node;
     cout<<"\nEnter Your Node....";
     cin>>newn->a;
     newn->next=NULL;
     return newn;
}
void push(node *start,node *newn)
{
     n=start;
     if(start==NULL)        start=newn;
     else
     {
         while(n!=NULL)    {save=n;   n=n->next;    }
         if(n->next==NULL) {n=newn;   n->next=NULL; save->next=n;   }
     }
}
void show(node *start)
{
     n=start;
     while(n!=NULL)
     {
         cout<<"\nData is..."<<n->a;
         n-n->next;
     }    
}
int main()
{
    //clrscr();
    char ch='y';
    cout<<"\n*****Enter data for first node*****";
    newn=create();push(start,newn);start=newn;
    do
    {
	 newn=create();push(start,newn);
	 cout<<"\nWant to continue...";cin>>ch;
    }
    while(ch=='y');
    cout<<"\nOutput is....\n";
    show(start);
    getch();
    return 0;
}

