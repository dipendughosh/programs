//*******LEARNING NEW AND DELETE*******
#include<iostream.h>
#include<string.h>
#include<conio.h>
void main()
{	clrscr();
	char *str="to be or not to be!!!  ";
	int len=strlen(str);
	char *ptr;
	ptr=new char[len+1];
	strcpy(ptr,str);
	cout<<"string is ::"<<ptr<<"\n"<<str;
	delete ptr;
	cout<<"string is ::"<<ptr<<"\n"<<str;
	getche();
}




