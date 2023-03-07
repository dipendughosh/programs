#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	float deci,dec;
	int num,arr[100],a[100],limiti,limitd,i;
	int integer(int,int[]);
	int decimal(float,int[]);
	cout<<"enter a decimal number ";
	cin>>deci;
	num = deci;
	dec = deci - num;
	limiti = integer(num,arr);
	limitd = decimal(dec,a);
	for(i=limiti-1;i>=0;i--)
		cout<<arr[i];
	cout<<".";
	for(i=0;i<limitd;i++)
		cout<<a[i];
	getche();
}
int integer(int n, int arr[100])
{
	int i =0;
	while(n!=0)
	{
		arr[i]=n%2;
		n/=2;
		i++;
	}
	return i;
}
int decimal(float d,int a[100])
{
	float sum;
	int i,n;
	for(i=0;i<8;i++)
	{
		sum= d*2;
		n = sum;
		a[i] = n;
		d = sum -n;
		if(d== 0)
			break;
	}
	return i;
}








