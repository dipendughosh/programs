#include <iostream.h>
#include <conio.h>
#include <string.h>

struct stud
{     int roll;
	  char name[20];
	  char passed;
};
stud student[100];

int main()
{   int no,a,i,j,b,k;
	stud temp;
	clrscr();
	cout<<"How many entries ? "; cin>>no;
	for(i=0;i<no;i++)
	{    cout<<"Sl. No.  : "<<i+1;
		 cout<<"\nName     : "; cin>>student[i].name;
		 cout<<"Roll No. : "; cin>>student[i].roll;
		 cout<<"Status   : "; cin>>student[i].passed;
	}
	//clrscr();
	for(a=0;a<no;a++)
	{    cout<<"\nSl. No.  : "<<a+1;
		 cout<<" Name     : "<<student[a].name;
		 cout<<" Roll No. : "<<student[a].roll;
		 cout<<" Status   : "<<student[a].passed;
		 cout<<endl;
	}
	for(b=0;b<no-1;b++)
	{    for (j=1;j<no;j++)
		 {   if (strcmp(student[b].name,student[j].name)>=0)
			 {  temp=student[j]; student[j]=student[b];
				student[b]=temp;
			 }
		 }
	}
	cout<<"As per order of entry\n";
	getche();
	for(i=0;i<no;i++)
	{       cout<<"\n\nSl. No.  : "<<i+1;
			cout<<"\nName     : "<<student[i].name;
			cout<<"\nRoll No. : "<<student[i].roll;
			cout<<"\nStatus   : "<<student[i].passed;
	}
	getche();
	return 0;
}
