#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>

void main()
{
	clrscr();
	ofstream fout;
	fout.open("test.txt",ios::out);// | ios::binary);
	int rollno;
	char ch;
	char name[5],clas[5],sec[5],neme[26];
	do
	{
		cout<<"Enter Roll No.-";cin>>rollno;
		cout<<"Enter Name-";gets(name);
		cout<<"Enter Class-";gets(clas);
		cout<<"Enter Section-";gets(sec);
		//cout<<"Enter number-";cin>>n;
		fout<<rollno<<" "<<name<<" "<<clas<<" "<<sec<<"\n";
		cout<<"\nWant to continue...";cin>>ch;
	}
	while(ch=='y');
	fout.close();
	ifstream fin;
	fin.open("test.txt",ios::in);
	while(!fin.eof())
	{
		fin>>rollno;

		fin.getline(neme,25);
		puts(neme);
	}
	fin.close();
	getch();
}





