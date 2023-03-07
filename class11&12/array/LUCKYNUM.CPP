#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int arr[10],num,ctr=1,i=0,j=0,rep=0;
	for(j=0;j<10;j++)
		cin>>arr[j];
	for(j=0;j<10;j++)
		cout<<arr[j]<<"\t";
	cout<<"\nEnter a number :";
	cin>>num;
	do
	{	if(arr[i]==0)
		{	if(i<9)
				i++;
			else
				i=0;
			//if(ctr<9)
			       //	continue;
			//else
			       //	break;
			//cout<<"i="<<i<<" ctr="<<ctr<<" rep="<<rep<<" sage-1"<<"\n";
		}
		if(ctr==num)
		{	cout<<arr[i]<<"\n";
			arr[i]=0;
			rep++;
			ctr=0;
			//cout<<"i="<<i<<" ctr="<<ctr<<" rep="<<rep<<" sage-2"<<"\n";
		}
		ctr++;
		if(i<9)
			i++;
		else
			i=0;
			//cout<<"i="<<i<<" ctr="<<ctr<<" rep="<<rep<<" k"<<"\n";
	//getche();
	}while(rep<10);
	for(j=0;j<10;j++)
		if(arr[i]!=0)
			cout<<arr[j]<<"\t";
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}
