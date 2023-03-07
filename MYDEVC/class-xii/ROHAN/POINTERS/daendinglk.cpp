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
       node * leftaddress;
       node * rightaddress;
};
int main()
{
    node * temp ;
    node * newnode;
    node *start=new node;
    node *newn=new node;
    temp=NULL;
    int count=0;
    char ch;
    do
    {
              newnode=new node;
              cout<<"\nEnter data...";cin>>newnode->data;
              newnode->rightaddress=NULL;
              newnode->leftaddress=temp;
              temp=newnode;
              if(count==0)
              {            start=temp;start->rightaddress=temp; }
              //if(count==1)
              //           start->rightaddress=temp;            
              count++;
              //cout<<"\nnewnode right address.."<<cout<<newnode->rightaddress;
              //cout<<"\nnewnode left  address.."<<cout<<newnode->leftaddress;
              cout<<"\nWant to continue...(Y/N)..";cin>>ch;
     }
     while(ch=='Y' || ch=='y');
     cout<<"\n OUTPUT..";
     //cout<<"\nstart right address.."<<cout<<start->rightaddress;
     //cout<<"\nstart left  address.."<<cout<<start->leftaddress;
     newnode=start;
     do
     {
               cout<<"\nNumber is ..."<<newnode->data;
               cout<<"\nNewn right address.."<<newnode->rightaddress;
               newnode=newnode->rightaddress;
     }
     while(newnode->address !=NULL);
     //cout<<"\nNumber is ..."<<newnode->data;
     cout<<endl;
     getche();
     return 0;
}     