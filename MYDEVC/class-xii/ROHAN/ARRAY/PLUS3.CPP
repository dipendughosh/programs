#include <iostream.h>
#include <conio.h>
#include <process.h>
int chk(int dob,int s1,int m1)
{
	int f=0;
	if(dob>=1 && dob<=31)
	{       //cout<<"f"<<f;getch();
		if((m1>=1 && m1<=12))
		{       //cout<<"f--"<<f;getch();
			if (s1>=1 && s1<=12)
			{

				f=1;
				//cout<<"f--"<<f;getch();
			}
		}
	}
	return f;
}
void main()
{
    clrscr();
    cout<<"\nWANT TO KNOW YOUR LUCKY NUMBER'S.....\n\n";
    int arr[50],i = 0,k = 0,l = 50,dob=0,dx=0;
    void disparr(int[],int);
    for(; i<l; i++) arr[i] = i+1;
    int skip,m1=0,s1=0 ;
    cout<<"\nPlease enter your date of birth....";cin>>dob;
    cout<<"\nEnter month of your birth......";cin>>s1;
    cout<<"\nEnter current month......";cin>>m1;
    cout<<"\nEnter current day......";cin>>dx;
    if(chk(dob,s1,m1)==0)
    {
	cout<<"\nIllegal entry.....\n\nCannot  continue the programme...\n ";
	getch();
	exit(0);
    }
    skip=(m1+s1)/2+(dx/7);
    dob++;
    l=dob;
    do
    {   k = 0;
	for(i = 0; i<l; i+=skip) arr[k++] = arr[i];
	//cout<<"\nAfter skipping "<<skip-1<<" : \n";  // Showing steps
	//disparr(arr,k);
	l = k;
	skip;
    } while(skip<=l);
    cout<<"\nHence Your Lucky Numbers for this month ----> :";
    disparr(arr,k);
    cout<<"\nTHANK YOU FOR USING OUR SERVICES\n\n\t*****************OUR PATENT*****************\n\n\t\t\tROHAN DUTTA\n";
    getche();
}
void disparr(int a[],int n)
{   for(int d = 0; d<n; d++) cout<<a[d]<<" ";
    cout<<endl;
}
