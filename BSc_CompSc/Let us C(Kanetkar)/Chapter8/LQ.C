#include<stdio.h>
#include<conio.h>

void main()
{       float x[]={34.22,39.87,41.85,43.23,40.60,53.29,53.29,54.14,49.12,40.71,55.15};
	float y[]={102.43,100.93,97.43,97.81,98.32,98.32,100.07,97.08,91.59,94.85,94.65};
	float mx=0,my=0,mxy=0,mxx=0,myy=0,mxxx=0,myyy=0,r=0,i;
	clrscr();
	for(i=0;i<11;i++)
	{	mx=mx+x[i];
		my=my+y[i];
		mxy=mxy+(x[i]*y[i]);
		mxx=mxx+(x[i]*x[i]);
		myy=myy+(y[i]*y[i]);
	}
	mxxx=mx*mx;
	myyy=my*my;
	mxx=mxx-mxxx;
	myy=myy-myyy;
	mxx=11*mxx;
	myy=11*myy;
	mxx=mxx*myy;
	mxx=sqrt(mxx);
	myy=mxy-(mx*my);
	r=myy/mxx;
	printf("r = %f",r);
	getch();
}

