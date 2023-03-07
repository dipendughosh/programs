#include<stdio.h>

int main()
{
	void func1();
	void func2();
	printf("main\n");
	func1();
	return 0;
}

void func1()
{
	
	printf("Func 1\n");
	func2();
}

void func2()
{
	printf("Func 2\n");
}
