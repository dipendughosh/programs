/* Digits stored in DOUBLY LINKED LIST
**************************************/
# include <stdio.h>
//# include <malloc.h>
# include <stdlib.h>
# include <iostream.h>
# include <conio.h>

struct dblink
{	int info;
	dblink *next;
	dblink *prev;
};
class linknum
{   long num ;
    dblink start;
    public:
  //  dblink start;
    linknum()
    {   start.next = NULL;  // Empty list
    	start.prev = NULL;
    }
    void additem();
    void showitem();
    //void matchitem(dblink*,dblink*);
};
void linknum::additem()
{   cout<<"Enter number : "; cin>>num;
    dblink *node = new dblink;
   	node = &start;      // Points to the start of the list
    while(num)
  	{	//node->next = (dblink *) malloc(sizeof(dblink));
        node -> next = new dblink;
        node -> next -> prev = node;
        node = node -> next;
        node -> info = num % 10;
        num /= 10;
        //node = node -> next;
  		node -> next = NULL;
   	}
}
void linknum::showitem()
{   dblink* node = start.next;
	do
    {  cout<<node->info<<",";
       node = node->next;
  	} while (node->next);  // Show value of last node only one time
   	do
    {   cout<<node->info<<",";
  		node = node->prev;
   	} while (node->prev);
}

/*void matchitem(linknum n1,linknum n2)
{   dblink* node1 = &n1->start;
    dblink* node2 = &n2->start;
    cout<<node1->info;getche();
    if (node1->info == node2->info)
        cout<<"\nSAME!";
    else cout<<"\nNOT!";}*/
void main()
{   linknum num1,num2;
    void matchitem(linknum,linknum);
    cout<<"\nCase 1 : \n";
    num1.additem();
    cout<<"Case 2 : \n";
    num2.additem();
    cout<<"\n\nDigits as per doubly linked list...\n";
    cout<<"Case 1 : \n";
	num1.showitem();
    cout<<"\nCase 2 : \n";
    num2.showitem();
//    matchitem(num1,num2);
    cout<<endl;
    system("PAUSE");
}



