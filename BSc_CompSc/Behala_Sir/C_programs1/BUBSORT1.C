/* 		         surya rules			*/

/*	           bubble sort of order n		*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"



void main()
{
	int input[50],size,i,j,temp,flag=0;
	clrscr();
	printf("enter the number of elements:");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("input[%d]",i);
		scanf("%d",&input[i]);
	}

	for(i=0;i<size && flag==0 ;i++)
	{
		flag=1;
		for(j=0;j<size-i-1;j++)
		{
			if(input[j]>input[j+1])
			{
				temp=input[j];
				input[j]=input[j+1];
				input[j+1]=temp;
				flag=0;
			}
		}
	}

	printf("\n the sorted array is..........\n\n");

	for(i=0;i<size;i++)
		printf("%4d ",input[i]);

	getch();

}