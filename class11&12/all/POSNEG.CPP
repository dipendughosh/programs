#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	char ch='y';
	int m,a=0,b=0,p=0,n=0,s=0,c=0,d;
	do
	{	cout<<"Enter an integer ";
		cin>>m;
		if(m>0)
		{		p++;
				a=a+m;
		}
		else if(m<0)
		{		n++;
				b=b+n;
		}
		else if((m%2)==0)
		{		if(m>0)
					d=m;
				else
					d=m*(-1);
				s=s+d;
		}
		else if((m%2)!=0)
		{		if(m>0)
					d=m;
				else
					d=m*(-1);
				c=c+d;
		}
		cout<<"Do you want to continue ";
		cin>>ch;
		}while(ch=='y');
		cout<<"\nNumber of positive integers "<<p;
		cout<<"\nNumber of negative integers "<<n;
		cout<<"\nSum of positive integers "<<a;
		cout<<"\nSum of negative integers "<<b;
		cout<<"\nSum of even integers "<<s;
		cout<<"\nSum of odd integers "<<c;
		getche();
}