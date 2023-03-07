#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<Math.h>
void main()
{
	clrscr();
	char a[50],b[50];
	int conv(char[]);
	cout<<"Enter first number string : ";
	gets(a);
	cout<<"Enter second number string : ";
	gets(b);
	int sum =0;
	sum = conv(a) + conv(b);
	cout<<"the sum of "<<a<<"  and "<<b<<" is "<<sum;
	getche();
}
int conv(char n[])
{
	int x=1,length,y,sum=0,i=0,r =10;
	length = strlen(n);
	y =(int)n[i];
	y-=48;
	sum= y*r;
	i++;
	while(x<length)
	{
		y =(int)n[i];
		y-=48;
		sum+= y;
		if(x<length-1)
		{
			sum*=r;
		}
		x++;
		i++;
	}
	if(length == 1)
	{
		sum =(int)n[0];
		sum-=48;
	}
	//cout<<sum<<endl;
	return sum;
}