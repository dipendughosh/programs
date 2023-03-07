#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
struct node
{
       int data;
       node * address;
};
int main()
{
    node * temp ,* newnode;
    temp=NULL;
    char ch;
    do
    {
              newnode=new node;
              cout<<"\nEnter data...";cin>>newnode->data;
              newnode->address=temp;
              temp=newnode;
              cout<<"\nWant to continue...(Y/N)..";cin>>ch;
     }
     while(ch=='Y' || ch=='y');
     cout<<"\n OUTPUT..";
     do
     {
               cout<<"\nNumber is ..."<<newnode->data;
               newnode=newnode->address;
     }
     while(newnode->address !=NULL);
     cout<<"\nNumber is ..."<<newnode->data;
     cout<<endl;
     getche();
     return 0;
}     