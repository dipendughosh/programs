# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<string.h>
void main()
{   clrscr();
	char s[100];
	cin.getline(s,10);
	puts(s);
	for(int i=0;i<=7;i++)
		cout<<s[i];
	getch();
}