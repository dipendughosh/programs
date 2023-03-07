#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

struct stu
{	char name[80];
	int phy;
	int chem;
	int math;
	int comp;
	int total;
	int average;
};
void main()
{	clrscr();
	int i,j;
	stu student[3];
	stu temp;
	for(i=0;i<3;i++)
	{	cout<<"Enter name of student : ";
		gets(student[i].name);
		cout<<"\nEnter physics marks : ";
		cin>>student[i].phy;
		cout<<"\nEnter chemistry marks : ";
		cin>>student[i].chem;
		cout<<"\nEnter mathematics marks : ";
		cin>>student[i].math;
		cout<<"\nEnter computer marks : ";
		cin>>student[i].comp;
		student[i].total= student[i].phy+student[i].chem+student[i].math+student[i].comp;
		student[i].average=student[i].total;
		cout<<"\n";
	}
	for(i=0;i<2;i++)
	{	for(j=i+1;j<3;j++)
		{	if(student[i].total<=student[j].total)
			{	temp=student[i];
				student[i]=student[j];
				student[j]=temp;
			}
		}
	}
	clrscr();
	cout<<"                Phy    Chem    Math    Comp    Total  Average";
	for(i=0;i<3;i++)
	{	cout<<"\nName of student : ";
		puts(student[i].name);
		cout<<"                "<<student[i].phy;
		cout<<"\t"<<student[i].chem;
		cout<<"\t"<<student[i].math;
		cout<<"\t"<<student[i].comp;
		cout<<"\t"<<student[i].total;
		cout<<"\t"<<student[i].average;
	}
	getche();
}