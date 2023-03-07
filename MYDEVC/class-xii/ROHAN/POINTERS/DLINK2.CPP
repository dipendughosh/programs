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
       int data;
       node *right;
       node *left;
};
int main()
{
     clrscr();
     node *temp,*newnode;
     node *back=new node;
     char ch;
     temp=NULL;
     do
     {
	       newnode=new node;
	       cout<<"\nEnter Data for node....";cin>>newnode->data;
	       newnode->right=temp;
	       newnode->left=NULL;
	       temp=newnode;
	       cout<<"\nWant to continue.....";cin>>ch;
     }
     while(ch=='y');
     cout<<"\n Output in reverse order......";
     do
     {
	       cout<<"\nNumber is ..."<<newnode->data;
	       cout<<"\nNewn left address.."<<newnode->left;
	       cout<<"\nNewn right address.."<<newnode->right;
	       back=newnode;
	       newnode=newnode->right;
     }
     while(newnode->right!=NULL);
     cout<<"\n Output in serial order......";
     //cout<<back->right;
     /*do
     {
		cout<<"\nNumber is ..."<<back->data;
		cout<<"\nNewn right address.."<<back->right;
		back=back->right;
     }
     while(back->right!=NULL);*/
     getch();
     return 0;
}


