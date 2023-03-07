#include<iostream.h>
#include<conio.h>
void main()
{   clrscr();
	int col = 1,c = 33; //1;
	do
	{
		for(int row = 1; row < 25; row++)
		{
			gotoxy(col,row);
			cout<<c<<"->";
			if(c!=26) cout<<(char)(c);
			c++;
			if(c>254) break;
		}
		col += 8;// 7;
	}
	while(col < 78);
	getche();
}