#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
void main()
{	clrscr();
	void space(int);
	void linefeed();
	void display();
	int d,x;
	int m[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	cout<<"Enter the first day of the year.(EG.1-SUNDAY,2-MONDAY) : ";
	cin>>d;
	x=d;
	for(int i=0;i<12;i++)
	{   clrscr();
		display();
		for(int j=1;j<=m[i];j++)
		{	if (j==1)
			{	space((x-1)+(x-1)*3);
			}
			else  space(3);
			x++;
			cout<<j;
			if (x==8)
			{	linefeed();
				x=1;
			}
		}
		//getch();
	}
	system("PAUSE");//getch();
}

void display()
{	cout<<"S   M   T   W   T   F   S\n";
}
void linefeed()
{	cout<<"\n";
}
void space(int p)
{	for(int a=0;a<p;a++)  cout<<' ';
}
