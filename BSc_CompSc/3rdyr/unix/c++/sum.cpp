#include<iostream>

using namespace std;

int main()
{
	int n,i,s=0;
	cout<<"Enter n:- ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s=s+i;
	}
	cout<<"SUM = "<<s<<endl
		<<"AVG = "<<s/n;
	return 0;
}
