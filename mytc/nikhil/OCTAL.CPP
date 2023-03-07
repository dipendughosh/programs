//convert octal to binary system.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	int n,c[10],a=0;
	char s=25;
	cout<<"Enter an octal number : ";  cin>>n;
	clrscr();
	cout<<"Octal form : ("<<n<<')'<<s<<8;
	cout<<"\n\nThe binary form is : (";
	int q=n;
	while(q!=1)
	{	if(q!=1)
		{   c[a++]=(q%2);
			q/=2;
		}
	};
	c[a++]=1;
	c[a]='\0';
	for(int p=(a-1);p>=0;p--) cout<<c[p];
	cout<<')'<<s<<'2';
	getch();
}