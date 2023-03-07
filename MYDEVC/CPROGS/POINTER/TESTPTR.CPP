#include<iostream.h>
#include<conio.h>
#include<string.h>

void main()
{
	void disptr(char*);
	char arr[]="c++ is a good language";

	//clrscr();
	disptr(arr);
	getche();
}

void disptr(char* a) {
    cout<<endl;
	while (*a) cout<<*a++;
}


