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
	int p=0,shift,count,sum,sum1,l,m=0;
	cout<<"\nEnter string....";gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			s[p++]=a[i];
		}
		else
		{
			s[p++]='Q';
			s[p++]='Q';

		}
	}
	s[p++]='Q';
	s[p++]='Q';
	s[p]='\0';
	cout<<"\nEntered string after innitial modification....\n\n"<<s<<"\n\n"<<endl;
	cout<<"\nEnter shift...";cin>>shift;
	if(shift>27)
	{
		cout<<"\nIllegal entry...\nExiting programme...\n\n";
		getch();
		exit(0);
	}
	cout<<"\n\n\nCoded message is....\n\n"<<endl;
	for(i=0;i<p;i++)
	{
		sum=0,count=0;
		count=(int)(s[i]);
		sum=count-shift+1;
		if(sum<65)
		{
			sum1=0;l=0;
			sum1=65-sum;
			l=90-sum1+1;
		}
		else
			l=sum;
		c[m++]=(char)(l);
	}
	c[m]='\0';
	cout<<c;
	cout<<"\n\t\t\t**********\n";
	getch();
}

