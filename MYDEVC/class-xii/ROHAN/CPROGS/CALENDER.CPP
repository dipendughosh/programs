#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
int find[7][6]={1,7,-1,18,-1,24,2,8,13,19,-1,-1,3,-1,14,20,-1,25,4,9,15,-1,26,-1,-1,10,16,21,27,-1,5,11,-1,22,0,-1,6,12,17,23,-1,-1};
int dinmon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void isleap(int yy)
{
	if(yy%4==0)
	{
		if(yy%100 !=0)
			dinmon[2]=29;
		else
		{
			if(yy%400 == 0)
			dinmon[2]=29;
		}
	}
}
int calday(int day,int mon)
{
	int s=0;
	for(int i=1;i<mon;i++)
		s+=dinmon[i];
	s+=day;
	return s;
}
void inncal(int temp[6][7])
{
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			temp[i][j]=0;
}
void display(int temp[6][7])
{
	cout<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(temp[i][j]<32)
				cout<<temp[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void print(int x)
{
	switch(x)
	{
		case 0:
			cout<<"\Sunday";break;
		case 1:
			cout<<"\Monday";break;
		case 2:
			cout<<"\Tuesday";break;
		case 3:
			cout<<"\Wednesday";break;
		case 4:
			cout<<"\Thursday";break;
		case 5:
			cout<<"\Friday";break;
		case 6:
			cout<<"\Saturday";break;
	}
}
int search(int x)
{
	for(int i=0;i<7;i++)
		for(int j=0;j<6;j++)
			if(find[i][j]==x)
			{	return i;	}
	return -1;
}
void main()
{
	clrscr();
	int cal[6][7];
	inncal(cal);
	int yr,day,mon,r;
	int col,count=1;
	cout<<"\n Enter the Date-->";
	cout<<"\n Day   --> ";cin>>day;
	cout<<"\n Month --> ";cin>>mon;
	cout<<"\n Year  --> ";cin>>yr;
	cout<<"\n First Day of year...";print(search(yr%28));
	cout<<"\n Day of the year is  --> ";
	isleap(yr);
	r=calday(day,mon);
	cout<<"\n Search"<<search(yr%28);getch();//exit(0);
	for(int i=0;i<6;i++)
	{
		if(i==0)	col=search(yr%28);
		else	col=0;
		for(int j=col;j<7;j++)
			cal[i][j]=count++;
	}
	display(cal);
	cout<<"\n R -->calday  "<<r;getch();
	r=r%7;
	cout<<"\n R --> r mod 7 "<<r;getch();
	r=r+search(yr%28)-1;
	cout<<"\n R --> r +search "<<r;getch();
	if(r>6)	r-=7;
	print(r);
	getch();
}
