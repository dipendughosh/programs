//To perform polynomial addition of the form
//an(x^ny^nz^n)+an-1(x^n-1y^n-1z^n-1)+an(x^n-2y^n-2z^n-2)+...........

#include<iostream>
#include<new>
#include<exception>
//#define NULL 0

using namespace std;

//Template polynomial class
template<class ab>
class polynomial
{
//Begining of private scope
private:
	//Node structure of an individual term in the expression:-
	//Coefficient part-a;Exponent parts-x,y,z;Address part-next
	struct node
	{
		ab a,x,y,z;
		node *next;
	};
	//Head node of the polynomial
	struct node *head;
//Begining of public scope
public:
	//Defult constructor
	polynomial()
	{
		polynomial::head=NULL;
	}
	//Prototypes of normal functions and overloaded operator function 
	void create();
	polynomial operator+(polynomial);
	void display();
	//Destructor
	~polynomial()
	{
	}
};

//Create function to create the polynomials
template<class ab>
void polynomial<ab>::create()
{
	//Declaring local variables
	struct node *temp,*ptr;
	char c;
	ab n,m;
	//Infinite loop to enter data depending on user's choice
	while(1)
	{
		try
		{
			temp=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Unable to allocate space";
			return;
		}
		cout<<"Enter coeficient:- ";
		cin>>n;
		cout<<"Enter exponent of (x,y,z):- ";
		cin>>m;
		temp->a=n;
		temp->x=m;
		temp->y=m;
		temp->z=m;
		temp->next=NULL;
		if(polynomial<ab>::head == NULL)
		{
			polynomial<ab>::head=temp;
		}
		else
		{
			ptr=polynomial<ab>::head;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next=temp;
		}
		cout<<"Do you want to enter any more nodes?(y/Y) :- ";
		cin>>c;
		if(c != 'y' && c != 'Y')
			break;
	}
}

//Operator '+' overloaded function to add two polynomials entered by the user
template<class ab>
polynomial<ab> polynomial<ab>::operator+(polynomial ob)
{
	//Declaribg local variables
	polynomial temp;
	struct node *ptr1,*ptr2,*ptr3,*ptr4;
	int f;
	ptr1=polynomial<ab>::head;
	ptr2=ob.head;
	//Loop to add coefficients when the exponents are equal
	//and when terms of the in the first polynomial are left
	while(ptr1 != NULL)
	{	
		ptr2=ob.head;
		f=0;
		try
		{
			ptr4=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation not possible";
			throw 1;
		}
		while(ptr2 != NULL)
		{
			if(ptr1->x == ptr2->x)
			{
				f=1;
				ptr4->a=ptr1->a+ptr2->a;
				ptr4->x=ptr1->x;
				ptr4->y=ptr1->y;
				ptr4->z=ptr1->z;
				ptr1=ptr1->next;
				ptr2=ptr2->next;
				if(temp.head == NULL)
					temp.head=ptr4;
				else
				{	ptr3=temp.head;
					while(ptr3->next != NULL)
						ptr3=ptr3->next;
					ptr3->next=ptr4;
				}
				break;
			}
			ptr2=ptr2->next;
		}
		if(f==1)
			continue;
		ptr4->a=ptr1->a;
		ptr4->x=ptr1->x;
		ptr4->y=ptr1->y;
		ptr4->z=ptr1->z;
		ptr1=ptr1->next;
		if(temp.head == NULL)
			temp.head=ptr4;
		else
		{	ptr3=temp.head;
			while(ptr3->next != NULL)
				ptr3=ptr3->next;
			ptr3->next=ptr4;
		}
	}
	//Concatinating the terms present in the second polynomial but not in the first
	ptr2=ob.head;
	while(ptr2 != NULL)
	{
		f=0;
		ptr1=temp.head;
		while(ptr1 != NULL)
		{
			if(ptr1->x == ptr2->x)
			{
				f=1;
				break;
			}
			ptr1=ptr1->next;
		}
		if(f != 1)
		{
			try
			{
				ptr4=new node;
			}
			catch(bad_alloc e)
			{
				cout<<"Allocation not possible";
				throw 1;
			}
			ptr4->a=ptr2->a;
			ptr4->x=ptr2->x;
			ptr4->y=ptr2->y;
			ptr4->z=ptr2->z;
			if(temp.head == NULL)
				temp.head=ptr4;
			else
			{	ptr3=temp.head;
				while(ptr3->next != NULL)
					ptr3=ptr3->next;
				ptr3->next=ptr4;
			}
		}
		ptr2=ptr2->next;
	}
	return temp;
}

//Function to display the polynomial of the template class
template<class ab>
void polynomial<ab>::display()
{
	struct node *ptr;
	ptr=polynomial<ab>::head;
	//Displaying in desired format
	while(ptr->next != NULL)
	{
		cout<<ptr->a<<" x^"<<ptr->x<<" y^"<<ptr->y<<" z^"<<ptr->z<<" + ";
		ptr=ptr->next;
	}
	cout<<ptr->a<<" x^"<<ptr->x<<" y^"<<ptr->y<<" z^"<<ptr->z<<"\n";
}

//Main function
int main()
{
	char ch;
	cout<<"\nMAIN MENU";
	cout<<"\n'i' for integer!";
	cout<<"\n'f' for float!";
	cout<<"\n'c' for character!";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	if(ch=='i')
	{
		polynomial<int> ob1,ob2,ob3;
		try
		{
			ob1.create();
			ob2.create();
			cout<<"\n1st Polynomial:-\n";
			ob1.display();
			cout<<"\n2nd Polynomial:-\n";
			ob2.display();
			cout<<"\nAfter addition result is :-\n";
			ob3=ob1+ob2;
			ob3.display();
		}
		catch(int i)
		{
			cout<<"\nAllocation failed\n";
		}	
	}
	else if(ch=='f')
	{
		polynomial<float> ob1,ob2,ob3;
		try
		{
			ob1.create();
			ob2.create();
			cout<<"\n1st Polynomial:-\n";
			ob1.display();
			cout<<"\n2nd Polynomial:-\n";
			ob2.display();
			cout<<"\nAfter addition result is :-\n";
			ob3=ob1+ob2;
			ob3.display();
		}
		catch(int i)
		{
			cout<<"\nAllocation failed\n";
		}	
		
	}
	else
	return 0;
}
