#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	clrscr();
	char name[50];
	cout<<"\nenter name with surname   ";
	gets(name);
	int s = strlen(name);
	int i=0;
	cout<<"\nthe name is ===>";
	while(name[i]!=' ')
	{
		cout<<name[i];
		i++;
	}
	cout<<"\nthe surname is ===>";
	while(i<=s)
	{
		cout<<name[i];
		i++;
	}
	getche();
}