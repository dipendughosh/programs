#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<vector>

void main()
{	clrscr();
	stack<char> st1,st2;
	char arr[]={'A','+','B'};
	for(i=0;i<3;i++)
	{	if((int)arr[i]>=65 && (int)arr[i]<=91)
			st1.push(arr[i]);
		else st2.push(arr[i]);
	}
	st1.push(st2.top());
	cout<<st1.top();
	st1.pop();
	cout<<st1.top();
	st1.pop();
	cout<<st1.top();
	st1.pop();
	getche();
}































































































































