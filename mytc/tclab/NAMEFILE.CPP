#include<fstream.h>
#include<conio.h>
void main()
{   clrscr();
	int i = 0;
	char ch;
	ofstream outfile("name.txt");
   //	outfile.open("name.txt");
	outfile<<"arun\n"<<"barun\n"<<"kiranmala\n";
	outfile.close();
	char sname[20];
	outfile.open("sname.txt");
	for(;i<3;i++)
	{	cout<<"\nSurname : "; cin.get(sname,20);
		cin.get(ch);
		outfile<<sname<<"\n";
	}
	outfile.close();
	char name[20];
	ifstream infile1,infile2;
	infile1.open("name.txt");
	infile2.open("sname.txt");
	for( i=0;i<3;i++)
	{   infile1.getline(name,20);
		infile2.getline(sname,20);
		cout<<name<<" "<<sname<<endl;
	}
	infile1.close();
	infile2.close();
	getche();
}