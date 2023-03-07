#include<iostream.h>
#include<conio.h>
class student
{   private:
		char name[20];
		int roll;
		int marks[3];
		int totmarks();
	public:
		void nameroll();
		int marksin(int);
		void display();
}
void student : display()
{	cout<<"\nName  : "; puts(name);
	cout<<"\nRoll  : "<<roll;
	cout<<"\nTotal : "<<totmarks();
	cout<<endl;
}
int student : totmarks()
int student : marksin(int serial,sub)
{	cout<<"\Marks of student "<<serial
		<<" Subject "<<sub;
	cin>>marks[sub];
	totmarks();
}


void main()
{	student stu;
	stu.nameroll();
	for(int i = 0; i<3; i++)
	{	stu.marksin(1,i);


