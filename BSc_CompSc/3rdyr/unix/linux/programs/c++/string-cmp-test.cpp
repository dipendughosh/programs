#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[20]="xyz",c[20]="yz";
/*	s="xyz";
	c="xyz";*/
	int i;
	i=strcmp(s,c);
	cout<<i<<"\n";
	return 0;
}
