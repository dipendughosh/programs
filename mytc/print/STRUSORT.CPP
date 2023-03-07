#include<iostream.h>
#include<conio.h>
#include<string.h>
#define MAX 100
struct stud
{	int roll,marks;
	char name[20],passed;
} student[MAX];

void main()
{	void display(stud student[MAX],int),sort(stud student[MAX],int);
	int no;
	clrscr();
	cout<<"How many ? "; cin>>no;
	for (int i=0;i<no;i++)
	{	cout<<"\nSl. No. : "<<i+1;
		cout<<"\nRoll  : "; cin>>student[i].roll;
		cout<<"Name    : "; cin>>student[i].name;
		cout<<"Marks   : "; cin>>student[i].marks;
		student[i].passed = (student[i].marks>=40 ? 'P' : 'F');
		cout<<"Status  : "<< student[i].passed;
		cout<<endl;
	}
	display(student,no);
	getche();
	sort(student,no);
	cout<<"\nSorted by name :-\n";
	display(student,no);
	getche();
}

void display(stud st[MAX],int n)
{   //clrscr();
	for (int d=0 ; d<n ; d++)
	{	cout<<"Sl.No. : "<<d+1<<"\t";
		cout<<"Roll   : "<<st[d].roll<<"\t";
		cout<<"Name   : "<<st[d].name<<"\t";
		cout<<"Marks  : "<<st[d].marks<<"\t";
		cout<<"Status : "<<st[d].passed<<"\t";
		cout<<endl;
	}

}

void sort(stud st[MAX],int n)
{   stud temp;
	for (int a=0; a<n-1; a++)
	{	for (int b=1; b<n; b++)
		{	if (strcmp(st[a].name,st[b].name)>=0)
			{	temp=st[b];st[b]=st[a];st[a]=temp;
			}
		}
	}
}
