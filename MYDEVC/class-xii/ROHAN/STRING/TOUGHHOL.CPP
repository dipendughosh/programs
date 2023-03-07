#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{
	clrscr();
	int chk(char []);
	char s[500];
	void prn(char []);
	cout<<"\nPlease enter a word..-->";gets(s);
	if(chk(s)==1)
		prn(s);
	else
		cout<<"\nIllegal entry\nProgramme needs to shut down\nPress any key..-->";
	getch();
}
int chk(char a[])
{
	int f=0,d=0;
	for(int i=0;a[i]!='\0';i++)
		if(a[i]==' ')
		{       d=1;
			break;
		}
	if(strlen(a)>=5 && strlen(a)<=13)
		{
			if(strlen(a)%2==1 && d==0)
				f=1;
		}
	return f;
}
void prn(char a[])
{
	int p=1,length=strlen(a),pos;
	pos=length;
	for(int upp=1;upp<=length+1;upp++)
	{
		for(int start =0;start<pos;start++)
			cout<<a[start];
		if(upp==1)
			cout<<"-";
		else
		{
			for(int space=1;space<=p;space++)
				cout<<" ";
			p+=2;
		}
		for(int back=pos-1;back>=0;back--)
			cout<<a[back];
		pos--;
		cout<<endl;
		if(upp==1)
			pos++;
	}
	for(int low=1;low<=length+1;low++)
	{
		pos=low;
		if(low==length+1)
			pos=length;
		for(int start =0;start<pos;start++)
			cout<<a[start];
		if(low!=length+1)
		{
			for(int space=1;space<=(2*length+1-(2*pos));space++)
				cout<<" ";
		}
		else
			cout<<"-";
		for(int back=pos-1;back>=0;back--)
			cout<<a[back];
		cout<<endl;

	}
}