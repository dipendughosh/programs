#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	cout<<"\nBALL IS THROWN FROM A CERTAIN HEIGHT\nIN EACH FALL IT BOUNCES UP BUT IT'S SPEED REDUCES \nTHERE BY IT NEW HEIGHT BECOMES 80% OF THE PREVIOUS";
	long float bounce=0.,totup=0.,totdo=0.,h=0.,height=0.,time=0.;
	cout<<"\nHEIGHT OF FALL .....";cin>>height;
	h=height;
	cout<<"\nBALL TAKES 2 SECONDS TO FALL 1m \nAND 1.5SECONDS TO RISE 1m UPWARDE....\n\n";
	while(h>(.1*height))
	{
		//cout<<"\nHEIGHT......"<<h;
		totdo+=h;
		//cout<<"totdo--"<<totdo<<endl;getch();
		h=(h*.8);
		bounce++;
		if(h<(.8*height))
		{	totup+=h;	}
		//cout<<"totup--"<<totup<<endl;getch();
	}
	cout<<"\nTOTAL NUMBER OF BOUNCES IS ......"<<bounce;
	cout<<"\nToTAL UPWARD DIST.."<<totup<<"\nTOTAL DOWANWARD DIST...."<<totdo;
	time=((totup/1.5)+(totdo/2));
	cout<<"\nTOTAL TIME TILL WHICH BALL BOUNCED....."<<time<<" seconds\n";
	getch();
}
