#include<iostream.h>
#include<conio.h>

class Set
{	private:
	int n,arr[50];
	public:
	Set();
	Set(int);
	void readElements();
	void displayElements();
	int getSize();
	int has(int);
	Set intersection(Set);
	Set unions(Set);
	~Set();
};

Set::Set()
{
}

Set::Set(int nn)
{	n=nn;
	for(int i=0;i<n;i++)
		arr[i]=0;
}

void Set::readElements()
{	cout<<"\nEnter Elements of Array\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
}

void Set::displayElements()
{	cout<<"\nElements of Array\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"\n";
}

int Set::getSize()
{	cout<<"\nEnter Number of Eleents in Array->";
	cin>>n;
	return n;
}

int Set::has(int ele)
{	for(int i=0;i<n;i++)
	{	if(ele==arr[i])
			return 1;
		else
			return 0;
	}
	return 0;
}

Set Set::intersection(Set d)
{       int x,y=0,arr2[100];
	d.getSize();
	d.readElements();
	d.displayElements();
	for(int i=0;i<d.n;i++)
	{	x=d.has(d.arr[i]);
		if(x==1)
			arr2[y]=d.arr[i];
		else
			y++;
	}
	cout<<"\Intersecting Elements->\n";
	for(i=0;i<y;i++)
		cout<<"\n"<<arr2[i];
	return 0;
}

Set Set::unions(Set d)
{       int x,y=0,arr2[100];
	d.getSize();
	d.readElements();
	d.displayElements();
	for(int i=0;i<n;i++)
	{	arr2[y]=arr[i];
		y++;
	}
	for(i=0;i<d.n;i++)
	{	arr2[y]=d.arr[i];
		y++;
	}
	cout<<"\Intersecting Elements->\n";
	for(i=0;i<y;i++)
		cout<<"\n"<<arr2[i];
	return 0;
}

Set::~Set()
{
}

void main()
{	clrscr();
	int n;
	cout<<"\nEnter number of elements of array->";
	cin>>n;
	Set obj(n),obj1;
	obj.readElements();
	obj.displayElements();
	obj1.intersection(obj);
	obj1.unions(obj);
	getche();
}































































































































