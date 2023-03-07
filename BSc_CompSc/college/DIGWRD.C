/*Enter a number greater than equal to 0 and less
than 1000000000.Then print the entered number un words*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

//Character arrays to store the numbers in words
char arr1[11][20]={"Zero\0","One\0","Two\0","Three\0","Four\0","Five\0",
		    "Six\0","Seven\0","Eight\0","Nine\0","Ten\0"};
char arr2[10][20]={"\0","Eleven\0","Twelve\0","Thirteen\0","Fourteen\0",
	 "Fifteen\0","Sixteen\0","Seventeen\0","Eighteen\0","Nineteen\0"};
char arr3[10][20]={"\0","Ten\0","Twenty\0","Thirty\0","Forty\0",
		"Fifty\0","Sixty\0","Seventy\0","Eighty\0","Ninty\0"};
char arr4[5][20]={"\0","Hundred\0","Thousand\0","Lakh\0","Crore\0"};

//Character array to store the entered number in words
char arr5[10][20];

//Length of the converted number
int len=0;

//Function Declaration for conversion
void convert1(int [],int);

void main()
{       long int n,i,c=0,b,j,flag=0;
	int a[10];
	clrscr();
	for(i=0;i<=10;i++)
		a[i]=0;
//Entering the number as LONG INTEGER type
	do
	{	printf("\nEnter number (0 <= N < 1000000000):- ");
		scanf("%ld",&n);
		if(n>=0 && n<=999999999)
			flag=1;
		else
			printf("\nSORRY\tOut of Range,Re-Enter");
	}
	while(flag==0);
	b=n;
	if(n==0)
		puts(arr1[0]);
//Storing individual digits in an integer type array
	while(b!=0)
	{	a[c]=b%10;
		b=b/10;
		c++;
	}
/*Calling the function and passing 2 arguments,
the digits and number of digits*/
	convert1(a,c);
//Displaying the number and its converted form
	printf("%ld->",n);
	for(i=len-1;i>=0;i--)
	{       j=0;
		while(arr5[i][j]!='\0')
		{	printf("%c",arr5[i][j]);
			j++;
		}
		printf(" ");
	}
	getch();
}

//Function for the conversion
void convert1(int a[10],int c)
{	int i=0,b;
	for(i=0;i<c;i++)
	{
//Converting UNITS Digit,and TENS Digit
		if(i==0)
		{	b=a[i]+(a[i+1]*10);
			i++;
			if(b>=1 && b<=10)
			{	strcpy(arr5[len],arr1[b]);
				len++;
			}
			else if(b>=11 && b<=19)
			{       b=b-10;
				strcpy(arr5[len],arr2[b]);
				len++;
			}
			else if(b>=20 && b<=99)
			{       strcpy(arr5[len],arr1[b%10]);
				len++;
				b=b/10;
				strcpy(arr5[len],arr3[b]);
				len++;
			}
		}
//Converting HUNDREDS Digit
		else if(i==2)
		{	b=a[i];
			if(b>0)
			{	strcpy(arr5[len],arr4[1]);
				len++;
				strcpy(arr5[len],arr1[b]);
				len++;
			}
		}
//Converting THOUSANDS Digit and TEN THOUSANDS Digit
		else if(i==3)
		{	b=a[i]+(a[i+1]*10);
			i++;
			if(b>=1 && b<=10)
			{       strcpy(arr5[len],arr4[2]);
				len++;
				strcpy(arr5[len],arr1[b]);
				len++;
			}
			else if(b>=11 && b<=19)
			{       b=b-10;
				strcpy(arr5[len],arr4[2]);
				len++;
				strcpy(arr5[len],arr2[b]);
				len++;
			}
			else if(b>=20 && b<=99)
			{       strcpy(arr5[len],arr4[2]);
				len++;
				strcpy(arr5[len],arr1[b%10]);
				len++;
				b=b/10;
				strcpy(arr5[len],arr3[b]);
				len++;
			}
		}
//Converting LAKHS Digit and TEN LAKHS Digit
		else if(i==5)
		{	b=a[i]+(a[i+1]*10);
			i++;
			if(b>=1 && b<=10)
			{       strcpy(arr5[len],arr4[3]);
				len++;
				strcpy(arr5[len],arr1[b]);
				len++;
			}
			else if(b>=11 && b<=19)
			{       b=b-10;
				strcpy(arr5[len],arr4[3]);
				len++;
				strcpy(arr5[len],arr2[b]);
				len++;
			}
			else if(b>=20 && b<=99)
			{       strcpy(arr5[len],arr4[3]);
				len++;
				strcpy(arr5[len],arr1[b%10]);
				len++;
				b=b/10;
				strcpy(arr5[len],arr3[b]);
				len++;
			}
		}
//Converting CRORES Digit and TEN CRORES Digit
		else if(i==7)
		{	b=a[i]+(a[i+1]*10);
			i++;
			if(b>=1 && b<=10)
			{       strcpy(arr5[len],arr4[4]);
				len++;
				strcpy(arr5[len],arr1[b]);
				len++;
			}
			else if(b>=11 && b<=19)
			{       b=b-10;
				strcpy(arr5[len],arr4[4]);
				len++;
				strcpy(arr5[len],arr2[4]);
				len++;
			}
			else if(b>=20 && b<=99)
			{       strcpy(arr5[len],arr4[4]);
				len++;
				strcpy(arr5[len],arr1[b%10]);
				len++;
				b=b/10;
				strcpy(arr5[len],arr3[b]);
				len++;
			}
		}
	}
}