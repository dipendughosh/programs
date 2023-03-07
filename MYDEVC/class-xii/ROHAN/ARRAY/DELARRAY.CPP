#include<conio.h>
#include<iostream.h>
void main()
{
	clrscr();
	int a[5];
	int serch,d=0;
	void delarr(int[],int);
	for(int i=0;i<5;i++)
	{
		cout<<"\nPlease enter data..-->";cin>>a[i];
	}
	cout<<"\nEnter number to be removed from vector..-->";cin>>serch;
	for(i=0;i<5;i++)
		if(serch==a[i])
			d++;
	if (d==0)
		cout<<"\nNumber not present...";
		else
		{
			if(d==5)
				cout<<"\nThe full array has been deleated...";
			else
				delarr(a,serch);
		 }

	getch();
}
void delarr(int x[],int term)
{
	int d=0;
	for(int j=0;j<(5-d);j++)
	{
		if(x[j]==term)
		{
			d++;
			for(int k=j;k<4;k++)
				x[k]=x[k+1];
			j--;
		}
	}
	cout<<"\nModified array is...\n";
	for(int k=0;k<(5-d);k++)
		cout<<x[k]<<"\t";
}