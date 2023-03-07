//CODDING CIRCULAR WAY WITH SPACE IN ORIGINAL STRING REPLACED BY QQ
//PRACTICAL EXAM SJC 11S FINALS
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	char a[500],s[500],c[500];
	int sum=0,l,p=0,m=0,sum1=0,count,shift;
	cout<<"\nEnter data....";gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
			s[m++]=a[i];
	}
	s[m]='\0';
	do
	{
		cout<<"\nEnter shift...";cin>>shift;
	}
	while(shift>26 ||shift<1);
	for(i=0;i<strlen(s);i++)
	{
		sum=0;
		count=0;
		count=(int)(s[i]);
		sum=count+shift-1;
		if(sum>90)
		{
			sum1=sum-90;
			l=sum1+65-1;
		}
		else
			l=sum;
		c[p++]=l;
	}
	c[p]='\0';
	cout<<"\nDecoded message...\n\n"<<endl;
	for(i=0;i<p-1;i++)
	{
		if(c[i]=='Q' )
		{
			if(c[i+1]=='Q')
				cout<<" ";
		}
		else
			cout<<c[i];
	}

	getch();
}