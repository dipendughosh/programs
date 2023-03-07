/* 		         surya rules			*/

/*	    	          heap sort			*/

/* 		the program is working fine		*/
#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
/*		creation of heap and insertion of elements into it	*/

void insert_heap(int input[],int size,int item)
{
	int ptr,parent;
	size=size+1;
	ptr=size;

	while(ptr>1)
	{
		parent=ptr/2;
		if(item<=input[parent])
		{
			input[ptr]=item;
			return;
		}

		input[ptr]=input[parent];
		ptr=parent;
	}

	input[1]=item;
	return;
}

/*		deletion of heap		*/

void delete_heap(int input[],int *size,int *item)
{
	int left,right,last,ptr;

	*item=input[1];
	last=input[*size];
	*size=*size-1;
	ptr=1;
	left=2;
	right=3;

	while(right<=*size)
	{
		if(last>=input[left] && last>=input[right])
		{
			input[ptr]=last;
			return;
		}

		else
		{
			if (input[left]<input[right])
			{
				input[ptr]=input[right];
				ptr=right;
			}
			else
			{
				input[ptr]=input[left];
				ptr=left;
			}
		}

		left=2*ptr;
		right=left+1;
	 }

	 if(left==*size)
	 {
		if(last<input[left])
		{
			input[ptr]=input[left];
			ptr=left;
		}
	 }
	 input[ptr]=last;
	 return;
}



void main()
{

	int input[50],i,size,temp,item=0;
	clrscr();
	printf("Enter tne number of elements u want to sort:");
	scanf("%d",&size);
	printf("enter the elements u want to sort............\n");
	for(i=1;i<=size;i++)
	{
	       printf("input[%d]=",i);
	       scanf("%d",&input[i]);
	}

	for(i=1;i<size;i++)
	{
		insert_heap(input,i,input[i+1]);
	}

	temp=size;

	while(size>=1)
	{
		delete_heap(input,&size,&item);
		input[size+1]=item;
	}

	printf("\n\n\n the sorted elements are as follows............\n\n");
	for(i=1;i<=temp;i++)
	{
		printf("%d  ",input[i]);
	}

	getch();

}