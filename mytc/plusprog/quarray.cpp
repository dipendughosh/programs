// Queue-Array Program
# include <iostream.h>
# include <conio.h>
# include <process.h>
# define SIZE 5
class q
{
	char x;
	int m,front,rear,a[SIZE];
	public:
	q()
	{	front = -1;
		rear = -1;
		m = SIZE - 1;
	}
	void insert();
	void del();
	void disp();
};

void q::insert()
{	int n;
	do
	{
		cout<<"Insert Element : "; cin>>n;
		if(rear == -1)
		{	front = 0; rear = 0;	}
		else if(front == 0 && rear==(m-1) || (rear+1)==front)
		{
			cout<<"\n\tHOUSE FULL!!...";
			disp();
			getch();
			exit(0);
		}
		else
			rear = (rear+1) % m;

		a[rear] = n;
		cout << endl;
		//disp();
		cout<<"Insert more ? (y/n)";
		cin>>x;
	} while(x=='y');
}
void q::del()
{	int p;
	do
	{
		if(front==-1)
			cout<<"\nNothing left to delete!...";
		else
		{	p=a[front];
			cout<<"\nDelete number "<<p;
			if(front==rear)   //queue is empty reinitialize the value
				front=rear=-1;
			else
				front=(front+1)%m;
			cout<<endl;
			//disp();
		}
		cout<<"\nDelete more ? (y/n) ";
		cin>>x;
	} while(x=='y');
}

void q::disp()
{
	int i;
	if(front == -1)
		cout<<"The Queue is empty...";
	else  if(rear<front)
	{
		cout<<"\nThe Queue now is ======>\n";
		for(i=0;i<=rear;i++)
			cout<<a[i]<<"\t";
		for(i=rear+1;i<front;i++)
		   cout<<"-"<<"\t";
		for(i=front;i<m;i++)
			cout<<a[i]<<"\t";
	}
	else
	{
		cout<<"\nThe Queue now is ======>\n";
		for(i=0;i<front;i++)
			cout<<"-"<<"\t";
		for(i=front;i<=rear;i++)
			cout<<a[i]<<"\t";
	}
	cout<<endl;
}

void main()
{
	clrscr();
	q a1;
	int ch;
	do
	{
		clrscr();
		cout<<"	1. INSERT DATA IN QUEUE\n ";
		cout<<"	2. DELETE DATA FROM QUEUE\n ";
		cout<<"	3. DISPLAY QUEUE\n ";
		cout<<"	4. Exit\n";
		cout<<"\n Enter your choice : "; cin>>ch;
		if(ch==1)
			a1.insert();
		if(ch==2)
			a1.del();
		if(ch==3)
		{	a1.disp(); getch();	}
	} while(ch<4);
}