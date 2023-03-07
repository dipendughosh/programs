//11
//Binary calculator(done)
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<math.h>

unsigned long n1=0,n2=0,x=0;       //global varibles
void main()
{	clrscr();
	void decimal1(char[80]);   //1st decimal number conversion
	void decimal2(char[80]);   //2nd decimal number conversion
	void binary();             //binary number conversion
	void addition();           //addition of decimal number
	void subtraction();        //subtraction of decimal number
	void multiplication();     //multiplication of decimal number
	void division();           //division of decimal number
	char num1[80],num2[80],y;  //variables declaration
	int c=0;         //variables declaration
	do                         //lop for input data & user's choice
	{	cout<<"\nEnter 1st Binary Number :";
		gets(num1);
		decimal1(num1);
		cout<<"\nEnter 2nd Binary Number :";
		gets(num2);
		decimal2(num2);
		cout<<"\nOperations are ->";
		cout<<"\n1.ADDITION";
		cout<<"\n2.SUBTRACTION";
		cout<<"\n3.MULTIPLICATION";
		cout<<"\n4.DIVISION";
		cout<<"\nEnter Operation to Perform :";
		cin>>c;            //user's choice
		switch(c)
		{	case 1:    //case for addition
				addition();
			break;
			case 2:    //case for subtraction
				subtraction();
			break;
			case 3:    //case for multiplication
				multiplication();
			break;
			case 4:    //case for division
				division();
			break;
			default:
				cout<<"\nWRONG CHOICE ";
				getch();

			break;
		}
		binary();          //conversion of results into binary
		cout<<"\nDo you want to continue ::";
		cin>>y;
	}while(y=='y' || y=='Y');  //user's choice
	cout<<"\nPlease press a key.........\a";
	getche();
}

void decimal1(char number[80])    //1st decimal number conversion
{	int len=0,x=0,a=0,i=0;
	unsigned long s=0;
	len=strlen(number);
	for(i=(len-1);i>=0;i--)
	{       a=number[i]-48;
		if(a>=2)
		{	cout<<"\nWrong input of binary number ::";
			getch();
			exit(0);
		}
		else
		{	s=s+(pow(2,x)*a);
			++x;
		}
	}
	n1=s;
}

void decimal2(char number[80])    //2nd decimal number conversion
{	int len=0,x=0,a=0,i=0;
	unsigned long s=0;
	len=strlen(number);
	for(i=(len-1);i>=0;i--)
	{       a=number[i]-48;
		if(a>=2)
		{	cout<<"\nWrong input of binary number ::";
			getch();
			exit(0);
		}
		else
		{	s=s+(pow(2,x)*a);
			++x;
		}
	}
	n2=s;
}

void addition()                   //addition of decimal number
{	unsigned long sum=(n1+n2);
	x=sum;
}

void subtraction()                //subtraction of decimal number
{	unsigned long sub;
	if(n1>n2)
		sub=(n1-n2);
	else
		sub=(n2-n1);
	x=sub;
}

void multiplication()             //multiplication of decimal number
{	unsigned long mult=(n1*n2);
	x=mult;
}

void division()                   //division of decimal number
{	unsigned long div;
	if(n1>n2)
		div=(n2/n1);
	else
		div=(n1/n2);
	x=div;
}

void binary()                     //binary number conversion
{	int r,y=0;
	unsigned long sum[80];
	cout<<"\nThe binary num is ";
	if(x==0)
		cout<<x;
	while (x!=0)
	{	r=x%2;
		x=x/2;
		sum[y]=r;
		y++;
	}
	for(int i=y-1;i>=0;i--)
		cout<<sum[i];
}
