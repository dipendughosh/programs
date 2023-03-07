#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

class iscscores
{       protected:
	int number[6][2];
	public:
	iscscores();
	int point();
};

iscscores::iscscores()
{	int i,j;
	for(i=0;i<6;i++)
	{	for(j=0;j<2;j++)
		{	if(j==0)
			{	cout<<"Enter subject code ";
				cin>>number[i][0];
			}
			if(j==1)
			{	cout<<"Enter subject marks ";
				cin>>number[i][1];
			}
		}
	}
}

int iscscores::point()
{	int p,i=0;
	if(number[i][0]>=90)
		p=1;
	if(number[i][0]>=80 && number[i][0]<=89)
		p=2;
	if(number[i][0]>=70 && number[i][0]<=79)
		p=3;
	if(number[i][0]>=60 && number[i][0]<=69)
		p=4;
	if(number[i][0]>=50 && number[i][0]<=59)
		p=5;
	if(number[i][0]>=40 && number[i][0]<=49)
		p=6;
	if(number[i][0]>=30 && number[i][0]<=39)
		p=7;
	if(number[i][0]>=20 && number[i][0]<=29)
		p=8;
	if(number[i][0]>=10 && number[i][0]<=19)
		p=9;
	if(number[i][0]>=0 && number[i][0]<=9)
		p=10;
	i++;
	return p;
}

class bestfour :public iscscores
{	public:
	bestfour();
	void bestsubjects();
};

bestfour::bestfour()
{
}

void bestfour::bestsubjects()
{       int i,j,temp,p1[6],a[6],p=0;
	for(i=0;i<6;i++)
	{	p1[i]=iscscores::point();
		p=p+p1[i];
	}
	for(i=0;i<6;i++)
		cout<<p1[i];
	for(i=0;i<6;i++)
		a[i]=p1[i];
	for(i=0;i<5;i++)
	{	for(j=i+1;j<6;j++)
		{	if(a[i]>=a[j])
			{	temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<6;i++)
		cout<<a[i];
	cout<<"\nBest four subjects are\n";
	for(i=2,j=0;i<6;i++,j++)
	{	if(a[i]==p1[j])
		{	cout<<iscscores::number[j][0];//;<<"";
		}
		if(j==5)
			j=0;
	}

}

void main()
{	clrscr();
	bestfour b;
	b.bestsubjects();
	getche();
}
