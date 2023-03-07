//wonderous square
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>

class array
{	private:
	int n,arr[10][10];
	public:
	array();
	void getsize();
	void getdata();
	void showdata();
	void check();
	void index();
	int prime(int);
	~array();
};

array::array()
{   int i,j;
    n=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            arr[i][j]=0;
}

void array::getsize()
{   cout<<"\nEnter size of array (2<=n<=10):- ";
	cin>>n;
}

void array::getdata()
{   int i,j;
	cout<<"Enter array elements:-\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>arr[i][j];
}

void array::showdata()
{   int i,j;
	cout<<"Array Elements:-\n";
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
			cout<<arr[i][j]<<"\t";
		cout<<"\n";
	}
}

void array::check()
{	int i,j,k,l,ele,sum=0,s1=0,s2=0,flag=1,f=1;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	ele=arr[i][j];
			for(k=i;k<n;k++)
			{	for(l=j+1;l<n;l++)
				{	if(ele==arr[k][l])
				    {	f=0;
                        break;
                    }
					else
						f=1;
				}
                if(f==0)
                    break;
            }
            if(f==0)
                break;
		}
        if(f==0)
            break;
	}
	if(f==1)
	{	sum=(0.5*(n*((n*n)+1)));
		for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
            {	s1=s1+arr[i][j];
                s2=s2+arr[j][i];
            }
			if(s1==sum && s2==sum)
			{	flag=1;
				s1=0;
                s2=0;
			}
			else
			{	flag=0;
                break;
				s1=0;
                s2=0;
			}
		}
		if(flag==1)
			cout<<"\nYES IT REPRESENTS A WONDROUS SQUARE";
		else
			cout<<"\nNOT A WONDROUS SQUARE";
	}
	else
		cout<<"\nNOT A WONDROUS SQUARE";
}

void array::index()
{   int i,j,f=1;
	cout<<"\nPRIME\t\tROW INDEX\t\tCOLUMN INDEX\n";
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	f=prime(arr[i][j]);
			if(f==1)
				cout<<arr[i][j]<<"\t\t"<<i<<"\t\t"<<j<<"\n";
		}
	}
}

int array::prime(int a)
{	int b,c=0,i,f=1;
	for(i=1;i<=(a/2);i++)
	{	b=a%i;
		if(b==0)
			++c;
	}
	if(c==1)
		f=1;
	else
		f=0;
	return f;
}

array::~array()
{
}

void main()
{
	char y;
	array obj;
	do
	{
		obj.getsize();
		obj.getdata();
		obj.showdata();
		obj.check();
		obj.index();
		cout<<"\nDo you want to continue(yes-y)?";
		cin>>y;
	}while(y=='y');
	getche();
}
