#include<conio.h>
#include<iostream.h>

int j=0,n;
int arr[50];
void main()
{ clrscr();
  int i,c=-1,mid,x,y;
  cout<<"Enter the number of times : ";  cin>>n;
  for (i=1;i<=n;i++)
	arr[j++]=i;
  i--;
  while (i>=1)
	arr[j++]=--i;
  mid=j/2-1;
  int r=3,col=40,q=0;
  for (i=0;i<2*n-1;i++)
  { if(c==n-1) q=1;
	if (q==0) c++;
	else c--;
	gotoxy(col,r);
	cout<<arr[mid];
	for (x=0;x<c;x++)
	{ gotoxy(col+c,r);
	  cout<<arr[mid+c];
	  col=40;
	  gotoxy(col-c,r);
	  cout<<arr[mid-c];
	  col=40;
	}
	r++;
  }
}

