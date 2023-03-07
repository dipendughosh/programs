/*****    TO PRINT ALL PYTHAGOREAN TRIPLETS IN THE RANGE 100 - 1000    ******/
#include<iostream.h>
#include<conio.h>
#include<Math.h>
void main()
{
	int i,j,k,isqr,jsqr,ksqr;
	cout<<"All PYTHAGOREAN TRIPLETS from 1 - 10";
	for(i =1;i<=100;i++)
	{
		isqr = pow(i,2);
		for(j =i+1;j<=100;j++)
		{
			jsqr = pow(j,2);
			for(k =j+1;j<=100;k++)
			{
				ksqr = pow(k,2);
				if(isqr+jsqr == ksqr)
				{
					cout<<" "<<i;
				}
			}
		}
	}
	getche();
}

