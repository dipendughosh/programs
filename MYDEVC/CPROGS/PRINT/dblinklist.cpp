/* Digits stored in DOUBLY LINKED LIST
**************************************/
# include <stdio.h>
//# include <malloc.h>
# include <stdlib.h>
# include <iostream.h>
//# include <conio.h>

struct dblink
{	int info;
	dblink *next;
	dblink *prev;
};

long num ;
dblink start;

void additem(dblink *node,int num)
{ 	start.next = NULL;  // Empty list
	start.prev = NULL;
	node = &start;      // Points to the start of the list
    while(num)
	{	//node->next = (dblink *) malloc(sizeof(dblink));
        node->next = new dblink;
        node->next->prev = node;
		node = node->next;
        node->info = num % 10;
        num /= 10;
		node->next = NULL;
  	}
}

void showitem (dblink *node)
{	node = start.next;
 	do
    {  cout<<node->info<<",";
	   node = node->next;
	} while (node->next);  // Show value of last node only one time

	do
    {   cout<<node->info<<",";
		node = node->prev;
	} while (node->prev);
}

void main()
{   int n1,n2;
    cout<<"Enter 1st number : "; cin>>n1;
    dblink *num1 = new dblink;
    additem(num1,n1);
    cout<<"Digits as per doubly linked list for 1st. number...\n";
	showitem(num1);
    cout<<"\n\nEnter 2nd number : "; cin>>n2;
    dblink *num2 = new dblink;
    //dblink *node = (dblink *) malloc(sizeof(dblink));
    additem(num2,n2);
    cout<<"Digits as per doubly linked list for 2nd. number...\n";
    showitem(num2);
    cout<<endl;
    system("PAUSE");
}



