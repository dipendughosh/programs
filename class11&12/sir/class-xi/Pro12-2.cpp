#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<math.h>
void main()
{	clrscr();
	int decimal(char[20]);
	void binary(int);
	int add(int,int);
	int sub(int,int);
	int mul(int,int);
	int division(int,int);
	char num1[20],num2[20],y;
	int n1,n2,c,x,ans;
	do
	{	cout<<"\nEnter 1st Binary Number :";
		gets(num1);
		n1=decimal(num1);
		cout<<"\nOperations are ->";
		cout<<"\n1.ADDITION";
		cout<<"\n2.SUBTRACTION";
		cout<<"\n3.MULTIPLICATION";
		cout<<"\n4.DIVISION";
		cout<<"\nEnter Operation to Perform :";
		cin>>c;
		cout<<"\nEnter 2nd Binary Number :";
		gets(num2);
		n2=decimal(num2);
		switch(c)
		{	case 1:
				x=add(n1,n2);
			break;
			case 2:
				x=sub(n1,n2);
			break;
			case 3:
				x=mul(n1,n2);
			break;
			case 4:
				x=division(n1,n2);
			break;
			default:
				cout<<"\nWRONG CHOICE ";
			break;
		}
		binary(x);
		cout<<"\nDo you want to continue ::";
		cin>>y;
	}while(y=='y' || y=='Y');
	cout<<"\nPlease press a key.........\a";
	getche();
}

int decimal(char number[20])
{	int len,s=0,x=0,a,i;
	len=strlen(number);
	for(i=len-1;i>=0;i--)
	{       a=number[i]-48;
		if(a>2)
		{	cout<<"\nWrong input of binary number ::";
			getch();
			exit(0);
		}
		else
		{	a=(pow(2,x)*a);
			s=s+a;
			x++;
		}
	}
	return s;
}

int add(int num1,int num2)
{	int sum=num1+num2;
	return sum;
}

int sub(int num1,int num2)
{	int sub;
	if(num1>num2)
		sub=num1-num2;
	else
		sub=num2-num1;
	return sub;
}

int mul(int num1,int num2)
{	int mult=num1*num2;
	return mult;
}

int division(int num1,int num2)
{	int div;
	if(num1>num2)
		div=num2/num1;
	else
		div=num1/num2;
	return div;
}

void binary(int x)
{	int r,y=0;
	long sum[80];
	cout<<"\nThe binary num is ";
	while (x!=0)
	{	r=x%2;
		x=x/2;
		sum[y]=r;
		y++;
	}
	for(int i=y-1;i>=0;i--)
		cout<<sum[i];
}
