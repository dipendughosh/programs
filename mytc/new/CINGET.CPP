# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<string.h>
void main()
{   clrscr();
	char ch ;
	int a=0;
	while(cin.get(ch))
	{
		if(ch=='e')
			a++;
	}
	cout<<"\n"<<a++;
	getch();
}