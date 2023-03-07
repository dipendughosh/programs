//Program to convert a number given in a particular base to any other particular base of users choice
//#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<iostream>

//using namespace std;
int main()
{       //Declaring variables and function
	void changebase(char [],double,int,int);
	char string[80];
	int len,i,a,n2,f=0;
	double n1;
	//Loop to check if input is a valid input
	do
	{       f=0;
		//clrscr();
		printf("\nEnter a number in any Base(between 1-16) :");
		fflush(stdin);
		gets(string);
		printf("Enter the Base of the number :");
		scanf("%d",&n1);
		printf("Enter the Base to which to convert the entered number :");
		scanf("%d",&n2);
		len=strlen(string);
		for(i=0;i<len;i++)
		{	a=string[i];
			//Checking digits
			if((a-48)>=0 && (a-48)<=9)
			{	if((a-48)>=n1)
				{	printf("\nINCORRECT\n\aRe-enter\n");
					f=1;
					break;
				}
			}
			//Checking alphabetes in upper cases
			else if((a-55)>=10 && (a-55)<16)
			{	if((a-55)>=n1)
				{       printf("\nINCORRECT\n\aRe-enter\n");
					f=1;
					break;
				}
			}
			//Checking alphabetes in lower cases
			else if((a-87)>=10 && (a-87)<16)
			{	if((a-87)>=n1)
				{	printf("\nINCORRECT\n\aRe-enter\n");
					f=1;
					break;
				}
			}
		}
		if(f==1)
			continue;
		else
			break;
	}while(1);
	changebase(string,n1,n2,len);
	return 0;
}

//Function to change entered number from old base to new base
void changebase(char stringhold[80],double n1,int n2,int l)
{       //Declaring variables
	int s=0,c,i,a,b,x=0;
	printf("\nThe number in base %d is ",n1);
	puts(stringhold);
	//Loop to convert number from given base to decimal
	for(i=(l-1);i>=0;i--)
	{	a=stringhold[i];
		if(a>=48 && a<=58)
		{	b=a-48;
			c=(pow(n1,x))*b;
			s=s+c;
		}
		if(a>=65 && a<=70)
		{       b=a-55;
			c=(pow(n1,x))*b;
			s=s+c;
		}
		if(a>=97 && a<=102)
		{       b=a-87;
			c=(pow(n1,x))*b;
			s=s+c;
		}
		x++;
	}
	x=0;
	//Loop to convert the number from decimal to the new base
	while(s!=0)
	{	b=s%n2;
		s=s/n2;
		if(b>=0 && b<=9)
		{	stringhold[x]=(char)(b+48);
			x++;
		}
		if(b>9 && b<16)
		{	stringhold[x]=(char)(b+55);
			x++;
		}
	}
	stringhold[x]='\0';
	printf("\nThe number in base %d is ",n2);
//	strrev(stringhold);
	puts(stringhold);
}
