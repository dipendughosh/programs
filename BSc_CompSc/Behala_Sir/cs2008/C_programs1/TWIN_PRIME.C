
	   /* Twin prime nos. from 1 to given no.  */

#include<stdio.h>
#include<conio.h>

void main()
{
int num,n,rem,i,pvnum=1,count=0;
clrscr();
printf("\n\tEnter the upper limit of the range : ");
scanf("%d",&n);

printf("\n\tThe twin prime nos. are : \n");
for(num=3;num<=n;num++)
	{
	for(i=2;i<num;i++)
		{
			rem=num%i;
			if(rem==0)
				count++;
		}	//end of for-i
		if(count==0)
		{
			if(num-pvnum==2)  	//difference between 2 prime nos.
					printf("\t%d and %d\n",pvnum,num);
			pvnum=num;
		}
	count=0;	//end of if
	}	//end of for-num
getch();
}