#include<stdio.h>
#include<iostream.h>
#include<conio.h>
void a()
{
	cout << "my first recursion" <<"\n";
	a();
	cout << "end";
}
void b();
void c();
void d();
int main()
{
	clrscr();
	a();
	b();
	c();
	d();
	getch();
	return 0;
}
void a()
{
	cout << "my first recursion" <<"\n";
	a();
	cout << "end";
}
void b()
{
	cout << "my second recursion" <<"\n";
	b();
	cout << "end";
}
void c()
{
	cout << "not a recursion" <<"\n";
	cout << "end";
}
void d()
{
	cout << "my third recursion" <<"\n";
	d();
	cout << "end";
}



