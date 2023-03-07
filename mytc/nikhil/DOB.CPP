#include<conio.h>
#include<iostream.h>

void agedisp(int);
struct date
{	int roll;
	int d;
	int m;
	int y;
	int calc;
}p[3];

void main()
{   clrscr();
//	int
	date c,temp;
	cout<<"Enter current date\nDate...."; cin>>c.d;
	cout<<"Month...";  cin>>c.m;
	cout<<"Year...";  cin>>c.y;
	for(int z=0;z<3;z++)
	{   clrscr();
		cout<<"Enter roll ...";  cin>>p[z].roll;
		cout<<"Enter date of the birth.\nDate...."; cin>>p[z].d;
		cout<<"Month...";  cin>>p[z].m;
		cout<<"Year...";  cin>>p[z].y;
		p[z].calc=(((p[z].y*12)+p[z].m)*30)+p[z].d;
	}
	for(int i=0;i<4;i++)
	{	for(int j=i+1;j<5;j++)
		{   if(p[j].calc>p[i].calc)
			{	temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	cout<<"\n\nROLL\t\tAGE\n~~~~\t\t~~~\n";
	for(int x=0;x<3;x++)
	{   cout<<"\n";
		cout<<p[x].roll;
		agedisp(p[x].calc);
/*		cout<<"\t\t";
		cout<<p[x].d<<" " <<p[x].m<<" "<<p[x].y;
		cout<<"\n";*/
	}
	getch();

}

void agedisp(int p)
{	cout<<"\t\t";
	int days=(p%30);
	int year=((p/30)/12);
	int month=((p/30)%12);
	cout<<days<<" days "<<month<<" months "<<year<<" year.";
}