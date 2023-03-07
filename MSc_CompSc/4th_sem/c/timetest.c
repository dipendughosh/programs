#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

struct time t1,t2;

void main()
{
   int i,j,k,min,sec;
	long int ssec;

	gettime(&t1);
   for(i=0;i<=1000;i++)
   	for(j=0;j<=1000;j++)
      	for(k=0;k<=1000;k++)
         	;
   gettime(&t2);

   if(t1.ti_hund>t2.ti_hund)
	{
		ssec=100+t1.ti_hund-t2.ti_hund;
		(t1.ti_sec)=(t1.ti_sec)-1;
	}
	else
		ssec=t2.ti_hund-t1.ti_hund;
	if(t1.ti_sec>t2.ti_sec)
	{
		sec=60+t1.ti_sec-t2.ti_sec;
		(t1.ti_min)=(t1.ti_min)-1;
	}
	else
		sec=t2.ti_sec-t1.ti_sec;
	min=t2.ti_min-t1.ti_min;

	printf("%d min :%d sec :%ld hsec",min,sec,ssec);

   getch();
}
