#include<fstream.h>
#include<conio.h>
class person
{	protected:
		char name[40];
		int age;
	public:
		void getdata()
		{	cout<<"\nEnter name : "; cin.get(name,40);
			cout<<"\nEnter age  : "; cin>>age;
		}
		void showdata()
		{	cout<<"\nName : "<<name;
			cout<<"\nAge  : "<<age;
		}
};

void main()
{	person human ;
	clrscr();
	human.getdata();
	ofstream outfile("person.txt");
	outfile.write((char*)&human,sizeof(human));
	ifstream infile("person.txt");
	infile.read((char*)&human,sizeof(human));
	human.showdata();
	getche();
}

