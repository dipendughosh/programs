#include<iostream.h>
#include<conio.h>
int arr1[] = { 4,5,6,7,8,9,11,12};
int arr2[] = { 5,7,8,9,10,12,15,20,22,36,45};
void main()
{
	clrscr();
	void mergesort( int [] , int , int [] , int );
	int s , a , i ;
	s = sizeof(arr1)/2;
	a = sizeof(arr2)/2;

	cout<<"\nArray 1->\t";
	for( i = 0; i < s; i++) cout<<arr1[i]<<"\t";
	cout<<"\nArray 2->\t";
	for( i = 0; i < a; i++) cout<<arr2[i]<<"\t";
	mergesort( arr1 , s , arr2 , a );
	getche();
}

/*void mergesort( int arr3[] , int s , int arr4[] , int a )
{   int i , j , c = 0 , arr5[100];
	for( i = 0 ; i < s ; i++ )
	{   for( j = 0 ; j < a ; j++ )
		{	if( arr3[i] <= arr4[j] )
			{	if(arr3!=0)
				{	arr5[c] = arr3[i];
					arr3[i]=0;
				}
			}
			else
			{	if(arr3!=0)
				{	arr5[c] = arr4[j];
					arr4[j]=0;
				}
			}
			c++;
		}
	}
	cout<<"\nArray 3->\t";
	for( i = 0 ; i < c ; i++ )
	{	cout<<arr5[i]<<"  ";
	}
} */

void mergesort( int a[] , int s1 , int b[] , int s2 )
{
	int c[100];
	int p=0,i=0,j=0;
	cout<<"s1-->"<<s1<<"s2-->"<<s2;
	getch();
	while(p<=s1 && p<=s2)
	{
		if(a[i]<b[j])
		{
			c[p++]=a[i++];
		}
		else
		{
			if(a[i]>b[j])
			{
				c[p++]=b[j++];
			}
			else
			{
				c[p++]=b[j++];
				i++;
			}
		}
	}
	cout<<"i--"<<i<<"j--"<<j<<"p--"<<p;
	cout<<endl;
	if((p-1)<s1)
	{	while(p<s1)
		{
			c[p++]=a[i++];
		}
	}
	if((p-1)<s2)
	{
		cout<<endl;
		while(p<s2)
		{

			c[p++]=b[j++];
			cout<<"p--"<<p<<"j--"<<j;
		}
	}
	cout<<endl;
	for(int k=0;k<p;k++)	cout<<c[k]<<"\t";
	getch();
}
