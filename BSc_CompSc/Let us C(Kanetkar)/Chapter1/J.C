#include<stdio.h>
#include<conio.h>

void main()
{	float t=80000,pm=52,tl=48,lm=35,im,iw,lw,tm,tw;
	clrscr();
	tm=t*lm/100;
	tw=t-tm;
	lm=t*lm/100;
	lw=tl*t/100;
	lw=lw-lm;
	getch();
}

