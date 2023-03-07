# include<iostream.h>
# include<conio.h>
void main()
{
	clrscr();
	int x;
	cout<<"\nEnter a length...";cin>>x;
	int *a=new int[x*x];
	for(int i=0;i<x;i++)
	   for(int j=0;j<x;j++)
	   {		cout<<"\n Enter no...";cin>>a[i*x+j];	}
	cout<<"\n OUTPUT \n";
	for(i=0;i<x;i++)
	{
	   for(j=0;j<x;j++)
			cout<<a[i*x+j]<<"\t ";
	   cout<<endl;
	}
	getch();
}
