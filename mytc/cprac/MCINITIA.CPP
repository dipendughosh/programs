#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	clrscr();
	char name[50],ch,c;
	int arr[20],p=1,j,y;
	cout<<"Enter a name ";
	gets(name);
	int length,i;
	arr[0] = 0;
	length = strlen(name);
	for(j =length;j>0;j--)
	{
		c = name[j];
		if(c == ' ')
		{
			y = j+1;
			break;
		}
	}
	for(i=1;i<length;i++)
	{
		ch = name[i];
		if(ch == ' ')
		{
			arr[p] = i+1;
			p++;
		}
	}
	for(i =0;i<p-1;i++)
	{
		int x =arr[i];
		cout<<name[x]<<".";
	}
	for(i = y;i<length;i++)
	{
		cout<<name[i];
	}
	getche();
}