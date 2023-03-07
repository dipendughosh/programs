#include<iostream.h>
#include<conio.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void leap(int y)
{ if(((y%100==0) && (y%400!=0))||(y%4==0))
	month[2]=29;
  else
	month[2]=28;
}
void main()
{ clrscr();
  int dd,mm,yy;
  cout<<" enter the date (dd/mm/yy) ";
  cin>>dd>>mm>>yy;
  void leap(int);
  leap(yy);
  int s=0;
  for(int i=1;i<mm;i++)
	{s+=month[i];}
   s+=dd;
 cout<<" date no is "<<s;
 getche();
}
