/* 		         surya rules			*/

/*	        	 quick sort 			*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"


int quick(int input[],int beginning, int end)
{
	int pos,left,right,temp;

	left=beginning;
	right=end;
	pos=beginning;

	/* scan from right to left	*/
	do
	{
		while(input[pos]<=input[right] && pos!=right)
		{
			right--;
		}

		if(pos==right)
			return(pos);
		else
		{
			temp=input[pos];
			input[pos]=input[right];
			input[right]=temp;

			pos=right;
		}

		/*	scan from left to right		*/

		while(input[pos]>=input[left] && pos!=left)
		{
			left++;
		}

		if(pos==left)
			return(pos);
		else
		{
			temp=input[pos];
			input[pos]=input[left];
			input[left]=temp;

			pos=left;
		}

	}while(left<=right);

}



void main()
{
	int n,input[100],lower[100],upper[100],i,j;
	int beginning,end,pos,top=-1;

	clrscr();

	printf("enter the number of elements of the array:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&input[i]);
	}

	if(n>=1)
	{
		top=top+1;
		lower[top]=0;
		upper[top]=n-1;
	}

	while(top!=-1)
	{
		beginning=lower[top];
		end=upper[top];
		top=top-1;

		pos=quick(input,beginning,end);

		if(beginning+1<pos)
		{
			top=top+1;
			lower[top]=beginning;
			upper[top]=pos-1;
		}

		if(end-1>pos)
		{
			top=top+1;
			lower[top]=pos+1;
			upper[top]=end;
		}
	}

	printf("the sorted array is as follows...........\n\n");

	for(i=0;i<n;i++)
		printf("%5d ",input[i]);

	getch();

}