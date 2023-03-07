//shortcut to stack
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<vector>

void main()
{	clrscr();
	stack<char,vector<char>> st;
	char cont='y',ch;
	do
	{	cout<<"\nEnter value : ";
		cin>>ch;
		cout<<"\nMore?";
		cin>>ch;
	}
	while(ch!='n');
	cout<<"\nSize of the stzck isnow........."<<st.size();
	while(!st.empty())
	{	cout<<"\n"<<st.top();
		st.pop();
	}
	getche();
}































































































































