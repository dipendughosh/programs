#include<iostream.h>
#include<conio.h>
struct node
{	int info;
	node* next;
};
void main()
{
	clrscr();
	node* a, *s;
	a->next = NULL;
	int num = 0;
	do
	{
		cout<<"Enter number : "; cin>>num;
		a->info = num;
		if(num <= 0) break;
		node* b = new node;
		b->next = a; // b->next is holding address of a(structure)
		a = b;       // address a takes up address b
	}
	while(num > 0);
	while(a != NULL)
	{
		cout<<a->info<<"\t";
		a = a->next;
	}
	getche();
}
