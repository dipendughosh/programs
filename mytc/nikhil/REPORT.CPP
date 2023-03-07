#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

struct report
{	char name[21];
	int roll;
	int s1,s2;
	float avg;
};

void main()
{   clrscr();
	report student[3],temp;
	for(int i=0;i<3;i++)
	{	cout<<"Enter name :"; gets(student[i].name);
		cout<<"\nEnter roll :"; cin>>student[i].roll;
		cout<<"\nEnter marks of two subjects : "; cin>>student[i].s1>>student[i].s2;
		student[i].avg=(student[i].s1+student[i].s2)/2;
	}

	for(int a=0;a<2;a++)
	{	for(int b=a+1;b<3;b++)
		{	if(student[a].avg<student[b].avg)
			{	temp=student[a];
				student[a]=student[b];
				student[b]=temp;
			}
		}
	}
	clrscr();
	for(int j=0;j<3;j++)
	{	puts(student[j].name);
		cout<<"\n";
		cout<<student[j].roll;
		cout<<"\n";
		cout<<student[j].avg;
		cout<<endl;
	}
	getch();
}