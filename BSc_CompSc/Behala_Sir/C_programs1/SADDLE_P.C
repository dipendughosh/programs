	   /* SADDLE POINT ( ROW MINIMA COLUMN MAXIMA ) */

#include<stdio.h>
#include<conio.h>

void main()
{
  int r,c,i,j,arr[50][50],pos,min;
  clrscr();
  printf("\n\tNumber of rows and column : ");
  scanf("%d%d",&r,&c);
    //inserting elements in array/////
  printf("\n\tEnter the elements of the array.");
  for(i=0;i<r;i++)
	{
	for(j=0;j<c;j++)
		{
		printf("\n\tEnter the [%d,%d] element : ",i,j);
		scanf("%d",&arr[i][j]);
		}	//end of for-j
	}	//end of for-i

	// finding out saddle point
   for(i=0;i<r;i++)
	{
	 min=arr[i][0];
	 pos=0;
	for(j=1;j<c;j++)
	   {
	   if(arr[i][j]<min)
		{
		 min=arr[i][j];
		 pos=j;
		}
	    }
	for(j=0;j<r;j++)
	   {
	    if(min < arr[j][pos])
	      break;
	   }
	if(j>=r)
	  printf("\n\n\tSaddle point is %d at position (%d,%d)",min,i,pos);
     }
getch();
}
