#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int arr[] = {1,7,2,8,3,6,4,10,9,5},x,num=8;
	void selesort(int[]);
	int binserch(int[],int);
	selesort(arr);
	x = binserch(arr,num);
	if(x!=0)
	{
		cout<<"the number is present in position number "<<x;
	}
	getche();
}
void selesort(int a[])
{
	int i,j,temp,small;
	for(i=0;i<10;i++)
	{
		small = a[i];
		for(j=i+1;j<10;j++)
		{
			if(a[j]<small)
			{
				temp = a[j];
				a[j] = small;
				a[i] = temp;
			}
		}
	}
}
int binserch(int a[],int n)
{
	int h =10/2;
	if(a[h] == n)
	{
		return h;
	}
	return 0;
}


