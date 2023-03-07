#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int hour=0,j=950,min=0;
	float s1=0.,s2=0.,gap=0.,jj=0.;
	for(int i=0;i<(950);i+=50,j-=60)
	{
		if(i+50<j-60)
		{      hour++;		}
		else
			break;
	}
	--hour;
	gap=(60*hour)-(50*hour);s1=(50/60.);s2=(60/60.);jj=gap;
	for(float ii=0.;ii<gap;ii+=s1,jj-=s2)
	{
		if(ii+s1<jj-s2)
		{       min++;		}
		else
			break;
	}
	--min;
	cout<<"\nTrains will meet in   "<<hour<<"hrs  "<<min<<"min\n";
	getch();
}
