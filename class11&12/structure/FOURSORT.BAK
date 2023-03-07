#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int cho;
	void bubblesort();
	void insertionsort();
	void selectionsort();
	void mergesort();
	cout<<"\tM E N U";
	cout<<"\n1.Bubble Sort.";
	cout<<"\n2.Insertion Sort.";
	cout<<"\n3.Selection Sort.";
	cout<<"\n4.2 Way Merge Sort.";
	cout<<"\n5.Exit.";
	cout<<"\nEnter choice :";
	cin>>cho;
	switch(cho)
	{	case 1:
			bubblesort();
		break;
		case 2:
			insertionsort();
		break;
		case 3:
			selectionsort();
		break;
		case 4:
			mergesort();
		break;
		case 5:
		break;
		default:
			cout<<"\nWrong Choice";
		break;
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}

void bubblesort()
{	int a[5],i,j,temp;
	cout<<"\nEnter array:\n";
	for(i=0;i<5;i++)
	{	cin>>a[i];
	}
	for(i=0;i<4;i++)
	{	for(j=i+1;j<5;j++)
		{	if(a[i]>a[j])
			{	temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	cout<<"\n";
	for(i=0;i<5;i++)
	{	cout<<a[i]<<"\t";
	}
}
void insertionsort()
{	int a[5],i,j,temp;
	cout<<"\nEnter array:\n";
	for(i=0;i<5;i++)
	{	cin>>a[i];
	}
	for(i=1;i<5;i++)
	{	j=i;
		temp=a[i];
		while(j>0 && a[j-1]>temp)
		{	a[j--]=a[j-1];
		}
		a[j]=temp;
	}
	cout<<"\n";
	for(i=0;i<5;i++)
	{	cout<<a[i]<<"\t";
	}
}
void selectionsort()
{	int a[5],i,j,k,temp;
	cout<<"\nEnter array:\n";
	for(i=0;i<5;i++)
	{	cin>>a[i];
	}
	for(i=1;i<5;i++)
	{	k=0;
		for(j=1;j<(5-i);j++)
		{	if(a[j]>a[k])
			{	k=j;
			}
		}
		temp=a[k];
		a[k]=a[5-i];
		a[5-i]=temp;
	}
	cout<<"\n";
	for(i=0;i<5;i++)
	{	cout<<a[i]<<"\t";
	}
}
void mergesort()
{	int a[5],b[5],c[10],i,j,temp;
	cout<<"\nEnter array:\n";
	for(i=0;i<5;i++)
	{	cin>>a[i];
	}
	cout<<"\nEnter array:\n";
	for(i=0;i<5;i++)
	{	cin>>b[i];
	}
	for(i=0;i<5;i++)
	{	c[i]=a[i];
	}
	j=0;
	for(i=5;i<10;i++)
	{	c[i]=b[j];
		j++;
	}
	for(i=0;i<9;i++)
	{	for(j=i+1;j<10;j++)
		{	if(c[i]>c[j])
			{	temp=c[j];
				c[j]=c[i];
				c[i]=temp;
			}
		}
	}
	cout<<"\n";
	for(i=0;i<10;i++)
	{	cout<<c[i]<<"\t";
	}
}









































































































































































































































































































































































