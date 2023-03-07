/*		5
	     4  5  4
	  3  4  5  4  3
       2  3  4  5  4  3  2
    1  2  3  4  5  4  3  2  1
*/
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	int arr[9]={5,4,3,2,1,2,3,4,5};
	int i,j,k,r,spl=4;
	for(i=spl,r=spl;i>=0;i--,r++)
	{	for(j=0;j<=i;j++)
			cout<<" ";
		for(k=i;k<=r;k++)
			cout<<arr[k];
		cout<<"\n";
	}
	getche();
}