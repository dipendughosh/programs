#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>


void main()
{ 	clrscr();
	char arr[3][3];
	int i,j,inputr1,inputc1,inputr2,inputc2,n=1;
	int check(char[3][3],int,int);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			arr[i][j]='0';
	cout<<"\n\tinput 1 or 2 or 3";
	cout<<"\n1st Player:\t\t\t2nd Player:";
	cout<<"\nEnter row number : ";
	cin>>inputr1;
	--inputr1;
	cout<<"\nEnter column number : ";
	cin>>inputc1;
	--inputc1;
	while(n<=9)
	{	if(check(arr,inputr1,inputc1)==1)
		{	arr[inputr1][inputc1]='X';
			cout<<"\n\t\tEnter row number : ";
			cin>>inputr2;
			--inputr2;
			cout<<"\n\t\tEnter column number : ";
			cin>>inputc2;
			--inputc2;
			n++;
		}
		else
		{	cout<<"\nRe-enter";
			cout<<"\nEnter row number : ";
			cin>>inputr1;
			--inputr1;
			cout<<"\nEnter column number : ";
			cin>>inputc1;
			--inputc1;
		}
		if(check(arr,inputr2,inputc2)==1)
		{	arr[inputr2][inputc2]='O';
			cout<<"\nEnter row number : ";
			cin>>inputr1;
			--inputr1;
			cout<<"\nEnter column number : ";
			cin>>inputc1;
			--inputc1;
			n++;
		}
		else
		{       cout<<"\nRe-enter";
			cout<<"\n\t\tEnter row number : ";
			cin>>inputr2;
			--inputr2;
			cout<<"\n\t\tEnter column number : ";
			cin>>inputc2;
			--inputc2;
		}
	}
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{	cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}
int check(char a[3][3],int b,int c)
{	int x;
	if(a[b][c]=='0')
		x=1;
	else
		x=0;
	return x;
}

