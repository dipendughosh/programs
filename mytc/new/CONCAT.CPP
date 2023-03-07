# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<string.h>
# include<process.h>
void main()
{   clrscr();
	char a[100],b[100];
	cout<<"\nEnter first word..  ";gets(a);
	cout<<"\nEnter second word..  ";gets(b);
	int p=strlen(a);
	for(int i=0;a[i]!='\0';i++)
	{	a[p]=b[i];
		p++;
	}
	a[p+1]='\0';
	puts(a);
	getch();
}
