# include<conio.h>
# include<iostream.h>
# include<string.h>
# include<stdio.h>
# define n 70
void main()
{
	clrscr();
	int isvalid(int);
	void invert(char []);
	void print(int);
	char a[n];
	cout<<"\nEnter the coded message...";gets(a);
	invert(a);
	int count=0,s=0,p;
	cout<<"\n Decoded Message  :- ";
	for(int i=0;i<strlen(a);i++)
	{
		if(count!=2)
		{
			p=(int)(a[i])-48;
			s=p+(s*10);
			count++;
		}
		else
		{
			if(isvalid(s))
			{
				print(s);s=0;count=0;
				p=(int)(a[i])-48;
				s=p+(s*10);count++;
			}
			else
			{
				p=(int)(a[i])-48;
				s=p+(s*10);
				print(s);
				s=0;count=0;
			}
		}
	}
	print(s);
	getch();
}
int isvalid(int s)
{
	if(s==32)
		return 1;
	if(s>=65 && s<=90)
		return 1;
	if(s>=97 && s<=122)
		return 1;
	return 0;
}
void print(int s)
{
	cout<<(char)(s);
}
void invert(char x[])
{
     char temp[50];
     int count=0;
     for(int i=(strlen(x)-1);i>=0;i--)
     {	temp[count++]=x[i];	}
     temp[count]='\0';
     stpcpy(x,temp);
}
