#include <fstream.h>
#include <conio.h>
class seqfil
{   int empno,job,basic;
	char name[20];
	char buf;
	fstream datafil;
	public:
//	seqfil()
//	{	datafil.open("Emp.txt",ios::out);	}
	void getin()
	{   datafil.open("Emp.txt",ios::app);
		cout<<"Emp. Code : "; cin>>empno;
		//cout<<"Name      : "; cin.get(name,20);
		cout<<"Job Code  : "; cin>>job;
		cout<<"Basic Pay : "; cin>>basic;
		cin.get(buf);
		datafil<<empno<<'\n'<<job<<'\n'<<basic<<'\n';
		datafil.close();
	}
	void getout();
	~seqfil()
	{	datafil.close();	}
};
void seqfil::getout()
{   ifstream datafil;
	datafil.seekg(0);
	while(datafil)
	{	datafil>>empno;
		datafil.get(buf);
		//datafil.get(name,20);
		//datafil.get(buf);
		datafil>>job;
		datafil.get(buf);
		datafil>>basic;
		datafil.get(buf);
		cout<<empno<<"\t"<<job<<"\t"<<basic;
		cout<<"\n";
	}
	datafil.close();
}
void main()
{	seqfil test;
	clrscr();
	cout<<"Enter some data................\n";
	for(int i=0;i<2;i++)
		test.getin();
	//datafil.close();
	cout<<"\nNow the output...............\n";
   //	for(int j=0;j<2;j++)
		test.getout();
	getche();
}



