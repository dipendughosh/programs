#include<stdio.h>
#include<conio.h>
#include<math.h>

void n_queen(int,int);
int place(int,int);
int a[8];

void main()
{
 int l,n=8;
// clrscr();

  for(l=1;l<=n;l++)
  {
    a[l]=0;
  }
n_queen(1,n);
getch();
//return 0;
}

void n_queen(int k,int n)
{
int i;
 for(i=1;i<=n;i++)
 {
 if(place(k,i))
 {
  a[k]=i;
 // clrscr();
  if(k==n)
  {

  for(i=1;i<=n;i++)
  printf("%d\t",a[i]);


 //getch();
 break;
 }
  else
  {

  n_queen(k+1,n);

  }

 }
}
 }



int place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
	{
		if((a[j]==i)||(abs(a[j]-i)==abs(j-k)))
			return 0;
				//return 1;
	}
	return 1;
}