/************************* CHECK MAGIC NUMBER  ****************************
********* If sum of digits of a number is 1, it is a Magic Number *********/

#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int num;
	int ismagic(int);
	cout<<"Enter a number ";
	cin>>num;
	if(ismagic(num))
	{
		cout<<num<<" is a magic number ";
	}
	else
		cout<<num<<" is not  a magic number ";
	getche();
}

int ismagic(int n)          // Function to check Magic No.
{
	int t,sum =0,p = n;
	while(n>=10)
	{
		while(p)
		{
			t = p%10;
			p/=10;
			sum+=t;
		}
		n = sum;
		p = n;
		sum =0;
	}
	if(n == 1)
	{
		return 1;   			// Magic
	}
	return 0;                  // NOT Magic
}
