#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
#include<fstream.h>
struct date
{
       int day,mon,yr;
};
class soccer
{
      char club[50],captain[50];
      date est;
      public:
	     void input()
	     {
		  cout<<"\nEnter Club's name.....";gets(club);
		  cout<<"\nEnter Club's captain..";gets(captain);
		  cout<<"\nEnter Date of establishment...";
		  cout<<"\nEnter day    -->  ";cin>>est.day;
		  cout<<"\nEnter month  -->  ";cin>>est.mon;
		  cout<<"\nEnter year   -->  ";cin>>est.yr;
	      }
	      void print()
	      {
		  cout<<"\nEnter Club's name.....";puts(club);
		  cout<<"\nEnter Club's captain..";puts(captain);
		  cout<<"\nEnter Date of establishment...";
		  cout<<"\nEnter day    -->  "<<est.day;
		  cout<<"\nEnter month  -->  "<<est.mon;
		  cout<<"\nEnter year   -->  "<<est.yr;
	      }
	      int compatre(soccer x,soccer y)
	      {
		  if(est.day>est.day)
			return 1;
		  else
			return 0;
	      }
};
int main()
{
    clrscr();
    soccer *obj=new soccer;
    soccer *temp=new soccer;
    char ch='y';
    int i=0;
    do
    {
	 obj[i++].input();
	 cout<<"\n\n Want to continue....";cin>>ch;
     }while(ch=='y');
     for(int j=0;j<i;j++)
	     obj[j].print();
     getche();
     for(j=0;j<(i-1);j++)
     {
	for(int k=j+1;k<i;k++)
		if(compare(obj[j],obj[k])==1)
		{
			temp=obj[j];
			obj[j]=obj[k];
			obj[k]=temp;
		}
     }
     for(j=0;j<i;j++)
	     obj[j].print();
     getche();


     return 0;
}



