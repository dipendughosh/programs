#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{ clrscr();
  long dec,k;
  long bin;
  cout<<" enter the decimal no ";
  cin>>dec;
  while(k>=2)
  { long j=dec%2;
	cout<<j;
	k=dec/2;
	dec=k;
  }
  getche();
}