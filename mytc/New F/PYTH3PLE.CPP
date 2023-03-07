/*****    TO PRINT ALL PYTHAGOREAN TRIPLETS IN THE RANGE 100 - 1000    ******/
#include<iostream.h>
#include<conio.h>
#include<Math.h>
void main()
{
	clrscr();
	int i,j,k,isqr,jsqr,ksqr;
	cout<<"All PYTHAGOREAN TRIPLETS from 1 - 10";
	for(i =1;i<=10;i++)
	{
		isqr = pow(i,2);
		for(j =i+1;j<=10;j++)
		{
			jsqr = pow(j,2);
			for(k =j+1;k<=10;k++)
			{
				ksqr = pow(k,2);
				if(isqr+jsqr == ksqr)
				{
					cout<<"\n "<<i<<" "<<j<<" "<<k;
				}
			}
		}
	}
	getche();
}

