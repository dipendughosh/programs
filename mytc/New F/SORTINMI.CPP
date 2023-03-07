#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int a[5];
	int c=1,max,mid,p=1,i=0,l,q,pos;
	void swap(int[],int,int);
	int findlarge(int[],int),findpos(int[],int);
	for(i=0;i<5;i++)
	{
		cout<<"\nEnter data...-->";cin>>a[i];
	}
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<"  ";
	}
	getch();
	cout<<endl;
	max=a[0];
	for(i=0;i<5;i++)
	{
		if(a[i]>=max)
		{	max=a[i];
			l=i;
		}
	}
   //	cout<<"\n"<<l;
	cout<<max;
	getch();
	mid=2;
	cout<<a[mid]<<a[l]<<endl;
	swap(a,mid,l);
	//int temp;
	//temp=a[mid];
	//a[mid]=a[l];
	//a[l]=temp;
	cout<<a[mid]<<a[l]<<endl;
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	getch();
	q=max;
	max=-100;
	for(int j=1;j<=4;j++)
	{


	//		cout<<max<<"\n      m  ";
		pos=mid+(c*p);
		//cout<<pos<<"  "<<l<<endl; getch();
		swap(a,pos,findpos(a,q));
		//cout<<(pos*p)<<"  ";
		//cout<<pos<<"  "<<l<<endl;
		//getch();
		c++;
		q=findlarge(a,q);
//		cout<<"q-->"<<q;
		p=p*-1;
	}
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<"  ";
	}
	getch();
}
void swap(int x[],int y1,int y2)
{
	int temp;
	temp=x[y1];
	x[y1]=x[y2];
	x[y2]=temp;
}
int findlarge(int x[],int q)
{   int max=-100;
	for(int i=0;i<5;i++)
	{
		if(x[i]>=max && x[i]<q)
			max=x[i];
	}
	return max;
}
int findpos(int x[],int q)
{   int max=-100,pos;
	for(int i=0;i<5;i++)
	{
		if(x[i]>=max && x[i]<q)
			pos=i;
	}
	return pos;
}







