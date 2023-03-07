//permutation with 4 digits
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void swap(int x[],int p,int q);
void perm(int p[],int s);
void print(int arr[],int p);
int i,m=0,j,k,l,d=0;
int a[3],nw[3],c;
void main()
{
clrscr();
int b[]={1,2,3,4};
for(i=0;i<4;i++)
{   c=b[i];
	for(int v=0;v<4;v++)
		if(b[v]!=c)
			nw[d++]=b[v];
	d=0;
	perm(nw,c); cout<<"c:"<<c;
}
getch();
}
void perm(int p[],int s)
{   i=0,j=0;
	a[i++]=p[j++];
	a[i++]=p[j++];
	a[i]=p[j];
	for(i=0;i<3;i++)
	{
	swap(a,0,1);
	print(a,s);
	swap(a,1,2);
	print(a,s);
	}
}
void swap(int x[],int p,int q)
{   int temp;
	temp=x[p];
	x[p]=x[q];
	x[q]=temp;
}
void print(int arr[],int p)
{   cout<<p<<"  ";
	for(int x=0;x<3;x++) cout<<arr[x]<<"  ";
	cout<<"\n";
}