//Buble sort using template

#include<iostream>

using namespace std;

//Template Base class
template<class x>
class Myarray
{
//Begining of private scope     	
private:
	x a[20];
	int n;
//Begining of public scope     	
public:
	int i;
	//Default constructor
	Myarray()
	{
		for(i=0;i<20;i++)
			Myarray<x>::a[i]=0;
	}
	//Constructor to initialze the array
	Myarray(int k)
	{
		Myarray<x>::n=k;
		for(i=0;i<n;i++)
			Myarray<x>::a[i]=0;
	}
	void getdata();
	void bublesort();
	void show();
	//Destructor
	~Myarray()
	{
	}
};

//Function for entering data in array position
template<class x>
void Myarray<x>::getdata()
{
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter data at position a["<<i<<"]= ";
		cin>>Myarray<x>::a[i];
	}
}

//Function of buble sort to sort the array element 
template<class x>
void Myarray<x>::bublesort()
{
	int i,j;
	x temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

//Function to display the elements of the array
template<class x>
void Myarray<x>::show()
{
	for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
	
}


//Main function
int main()
{
	int n;
	char ch;
	cout<<"\n'i' for integer";
	cout<<"\n'f' for float";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	cout<<"Enter size of the array: ";
	cin>>n;
	if(ch=='i')
	{
		Myarray<int> ob1(n);
		ob1.getdata();
		ob1.bublesort();
		ob1.show();
	}
	else if(ch=='f')
	{
		Myarray<float> ob1(n);
		ob1.getdata();
		ob1.bublesort();
		ob1.show();;
	}
	else
		cout<<"\nERROR in choice!\n";
	return 0;
}

