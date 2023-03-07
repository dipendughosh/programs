#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>

void timeint();
struct time t1,t2;

int main()
{
	clrscr();
	gettime(&t1);
	delay(20000);
	gettime(&t2);
	timeint();
	getch();
	return(0);
}

void timeint()
{
	int min,sec;
	long int ssec;
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
	printf("%2dmin :%2dsec :%ldhsec",t1.ti_min,t1.ti_sec,t1.ti_hund);
	printf("\n%2dmin :%2dsec :%ldhsec",t2.ti_min,t2.ti_sec,t2.ti_hund);
	printf("\n%dmin :%dsec :%ldhsec\n",min,sec,ssec);
}
