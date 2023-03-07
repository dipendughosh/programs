/* 		         surya rules			*/

/*		        binary search			*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"

int binary(int a[],int lb,int ub,int item)
{
	int beg,end,mid,loc;
	beg=lb;end=ub;
	mid=(beg+end)/2;
	while(beg<=end && a[mid]!=item)
	{
		if(item<a[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
		mid=(beg+end)/2;
	}
	if(a[mid]==item)
		loc=mid;
	else
		loc=NULL;

	return (loc);
}


void main()
{

    int a[5],item,i,loc,ub,lb;
    clrscr();
    ub=4;lb=0;

    printf("enter 5 numbers:\n");

    for(i=0;i<5;i++)
    {
	scanf("%d",&a[i]);
    }
	printf("\n enter item: ");

	scanf("%d",&item);
	printf("wats up");


	loc=binary(a,lb,ub,item);


	if(loc!=NULL)
	{
		printf("\n\n  %d found at %d ",item,loc+1);
	}
	else
	{
		printf("\n\n %d not found",item);
	}



	getch();

}