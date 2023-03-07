#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

typedef struct date
{	int dd;
	int mm;
	int yyyy;
};

typedef struct data
{	char name[80];
	char ph[80];
	char add[80];
	date dob;
};

void main()
{	clrscr();
	data stu[1];
	int i;
	for(i=0;i<1;i++)
	{	cout<<"Enter name : ";
		gets(stu[i].name);
		cout<<"Enter phone number : ";
		gets(stu[i].ph);
		cout<<"Enter address : ";
		gets(stu[i].add);
		cout<<"Enter date of birth in : ";
		cout<<"dd : ";
		cin>>stu[i].dob.dd;
		cout<<"mm : ";
		cin>>stu[i].dob.mm;
		cout<<"yyyy : ";
		cin>>stu[i].dob.yyyy;
	}
	for(i=0;i<1;i++)
	{	cout<<"\nName : "<<stu[i].name;
		cout<<"\nPhone number : "<<stu[i].ph;
		cout<<"\nAddress : "<<stu[i].add;
		cout<<"\nDate of birth in : ";
		cout<<"\ndd : "<<stu[i].dob.dd;
		cout<<"\nmm : "<<stu[i].dob.mm;
		cout<<"\nyyyy : "<<stu[i].dob.yyyy;
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
