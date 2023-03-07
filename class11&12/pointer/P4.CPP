//Returning by reference
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

struct emp
{	char name[20];
	int age;
	float salary;
};

emp e1={"Sanjay",32,3200.00};
emp e2={"Sameer",28,2500.00};

void main()
{	clrscr();
	emp &fun();
	fun()=e2;
	cout<<"\nMain\n1st->"<<e1.name<<" "<<e1.age<<" " <<e1.salary;
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

emp &fun()
{	cout<<"\nFunction\n2nd->"<<e1.name<<" "<<e1.age<<" " <<e1.salary;
	return e1;
}