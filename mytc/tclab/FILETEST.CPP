#include<fstream.h>
#include<conio.h>
void main()
{   char buff[30];
	int n=0;
	clrscr();
	ofstream outfile("test.txt");
	outfile<<"This is All India Radio\n";
	outfile<<"ON FILE\n";
	cout<<"\nFile created...\n";
	ifstream infile("test.txt");
	while(infile)
	{	infile.getline(buff,30);
		cout<<buff;
		cout<<"HAHA";
		getche();
	}
	getche();
}