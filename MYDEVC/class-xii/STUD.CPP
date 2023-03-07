//file program
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>

struct Student
{	char name[100],clas[10],sec[10];//,dob[10];
	int rollno,n;
};

class Stu
{       private:
	Student st;
	public:
	Stu();
	void ReadData();
	void CreateFile();
	void DisplayData();
	void AddData(int);
	void SearchData(int);
	void DeleteData(int);
	void AppendData();
	~Stu();
};

Stu::Stu()
{       int i;
	for(i=0;i<100;i++)
		st.name[i]='\0';
	for(i=0;i<10;i++)
	{	//st.dob[i]='\0';
		st.clas[i]='\0';
		st.sec[i]='\0';
	}
	st.rollno=0;
	st.n=0;
}

void Stu::ReadData()
{       cout<<"Enter Roll No.-";
	cin>>st.rollno;
	cout<<"Enter Name-";
	gets(st.name);
	cout<<"Enter Class-";
	gets(st.clas);
	cout<<"Enter Section-";
	gets(st.sec);
	cout<<"Enter number-";
	cin>>st.n;
/*	cout<<"Enter Date of Birth(DD-MM-YYYY)-";
	gets(st.dob);*/
}

void Stu::CreateFile()
{       char y='y';
	fstream fout;
	fout.open("Students.txt",ios::out);
	while(y!='n')
	{	ReadData();
		fout.write((char*)&st,sizeof(15));
		fout<<"\n";
		cout<<"\nDo you want to continue?";
		cin>>y;
	}
	fout.close();
}

void Stu::DisplayData()
{       fstream fin;
	fin.open("Students.txt",ios::in);
	do
	{	fin.read((char*)&st,sizeof(15));
			cout<<"\nRoll No.-"<<st.rollno;
			cout<<"\nName-"<<st.name;
			cout<<"\nClass-"<<st.clas<<" Section-"<<st.sec;
			//cout<<"\nDate of Birth-"<<st.dob;
			cout<<"\nNumber-"<<st.n;

	}while(!fin.eof());
	fin.close();
}

void Stu::AppendData()
{	fstream fout;
	fout.open("Students.txt",ios::app|ios::binary);
	ReadData();
	fout.write((char*)&st,sizeof(st));
	fout.close();
}

void Stu::SearchData(int rn)
{       char f='n';
	fstream fin;
	fin.open("Students.txt",ios::in|ios::binary);
	while(fin)
	{	fin.read((char*)&st,sizeof(st));
		if(st.rollno==rn)
		{	cout<<"\nRoll No.-"<<st.rollno;
			cout<<"\nName-"<<st.name;
			cout<<"\nClass-"<<st.clas<<" Section-"<<st.sec;
			//cout<<"\nDate of Birth-"<<st.dob;
			cout<<"\nNumber-"<<st.n;
			f='y';
		}
	}
	if(f=='n')
		cout<<"\nRecord not found.....SORRY!";
	fin.close();
}

void Stu::DeleteData(int rn)
{       char f='n';
	fstream fin;
	fstream fout;
	fin.open("Students.txt",ios::in|ios::binary);
	fout.open("Temp.txt",ios::out);
	while(fin)
	{	fin.read((char*)&st,sizeof(st));
		if(rn!=st.rollno)
			fout.write((char*)&st,sizeof(st));
		else
			f='y';
	}
	if(f=='y')
		cout<<"\nRecord Deleted.....";
	else
		cout<<"\nRecord not found........SORRY!";
	fin.close();
	fout.close();
	remove("Students.txt");
	rename("Temp.txt","Students.txt");
}

void Stu::AddData(int rn)
{	fstream fin;
	fstream fout;
	fin.open("Students.txt",ios::in|ios::binary);
	fout.open("Temp.txt",ios::out|ios::binary);
	while(fin)
	{	fin.read((char*)&st,sizeof(st));
		if(rn<st.rollno)
			fout.write((char*)&st,sizeof(st));
		else if(rn==st.rollno)
		{	ReadData();
			fout.write((char*)&st,sizeof(st));
		}
		else if(rn>st.rollno)
		{	++st.rollno;
			fout.write((char*)&st,sizeof(st));
		}
		else
		{	ReadData();
			fout.write((char*)&st,sizeof(st));
		}
	}
	fin.close();
	fout.close();
	remove("Students.txt");
	rename("Temp.txt","Students.txt");
}

Stu::~Stu()
{
}

void main()
{	clrscr();
	char y;
	int rn,c;
	Stu s;
	s.CreateFile();
	do
	{       clrscr();
		cout<<"\n\t\t     MENU";
		cout<<"\n\t\t1.Display Data";
		cout<<"\n\t\t2.Add Data";
		cout<<"\n\t\t3.Search Data";
		cout<<"\n\t\t4.Delete Data";
		cout<<"\n\t\t5.Append Data";
		cout<<"\n\t\t6.Exit";
		cout<<"\n\t\tEnter choice-";
		cin>>c;
		switch(c)
		{	case 1:
				s.DisplayData();
				break;
			case 2:
				cout<<"\nRoll no. where you want to add data ";
				cin>>rn;
				s.AddData(rn);
				break;
			case 3:
				cout<<"\nRoll no. of data to search ";
				cin>>rn;
				s.SearchData(rn);
				break;
			case 4:
				cout<<"\nRoll no. of record to delete ";
				cin>>rn;
				s.DeleteData(rn);
				break;
			case 5:
				s.AppendData();
				break;
			case 6:
				cout<<"\n\t\tEXITING";
				getche();
				exit(0);
			default:
				cout<<"\nWRONG CHOICE";
				break;
		}
		cout<<"\nDo you want to continue?";
		cin>>y;
	}while(y!='n');
	getche();
}































































































































