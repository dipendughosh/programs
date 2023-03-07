/****************************************************************************

		THIS PROGRAM IS CREATED BY SOUMIK GUHA ROY
		BRESENHAM LINE DRAWING PROGRAM


*********************************************************************************/


#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "math.h"
#include "dos.h"
#include "time.h"


int main(int argv,char *args[])
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode,i,j,scale,xa1,ya1,xb1,yb1,temp,flag,xa,ya,xb,yb;
   float m;
   char *msg;

   /* initialize graphics and local variables */
   void lineBres(int ,int ,int ,int ,int ,int,int);
   void convert_coord(int,int ,int ,int ,int *,int *,int *,int *,int );
   void Draw_Outline(int);
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi\\");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   if(argv< 5)
   {
      sprintf(msg,"Invalid input parameter...");
      outtextxy(getmaxx()/2,getmaxy()/2,msg);
      getch();
      closegraph();
      return 0;
   }



       //	putpixel(getmaxx()/2,getmaxy()/2,12);

	scale=textheight("Z")/2;

	Draw_Outline(scale);

	xa1=atoi(args[1]);
	ya1=atoi(args[2]);
	xb1=atoi(args[3]);
	yb1=atoi(args[4]);
		   /*
	if(xa1>xb1)
	{
	  temp=xa1;
	  xa1=xb1;
	  xb1=temp;
	  temp=ya1;
	  ya1=yb1;
	  yb1=temp;
	}            */
	if(xb1==xa1)
		lineBres(ya,xa,yb,xb,scale,0,2);
	else
	 m=(float)(yb1-ya1)/(xb1-xa1);

	convert_coord(xa1,ya1,xb1,yb1,&xa,&ya,&xb,&yb,scale);

	sprintf(msg,"Gradient:%f",m);
	outtextxy(getmaxx()-textwidth(msg),(getmaxy()/2)-2*textheight("A"),msg);
	line(xa,ya,xb,yb);//White line by Turbo C
	setfillstyle(1,getmaxcolor());
	circle(xa,ya,scale);
	circle(xb,yb,scale);
	setcolor(12);
	sprintf(msg,"(%d,%d)",xa1,ya1);
	outtextxy(xa+scale,ya,msg);
	sprintf(msg,"(%d,%d)",xb1,yb1);
	outtextxy(xb+scale,yb,msg);


	if(abs(m)<1.000000 && m >= 0.00000) //1st qua
	{
	      sprintf(msg,"1st qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);
	      lineBres(xa,ya,xb,yb,scale,0,0);
	}
	else if(m >=1.00 ) //2nd qua
	{
	      sprintf(msg,"2nd qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);

	      lineBres(ya,xa,yb,xb,scale,0,2);
	}

	else if(abs(m)<1.000000 && m <0.00) //8th qua
	{
	      sprintf(msg,"8th qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);


	  lineBres(xa,ya,xb,yb,scale,1,0);
	}

	else if(abs(m)>=1.00 &&  m<=0.00)
	{
	      sprintf(msg,"7th qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);
	      lineBres(ya,xa,yb,xb,scale,1,2);

	}

   /* clean up */
   sprintf(msg,"Bresenham line Drawing");
   outtextxy(0,getmaxy()-2*textheight("S"),msg);
   getch();
   closegraph();
   return 0;
}

void Draw_Outline(int scale)
{
	char *msg;
	settextstyle(3, 0, 1);
	/*Drawing the outline*/
	rectangle(0,0,getmaxx(),getmaxy());

	/*End of outline border*/

	line(getmaxx()/2,2,getmaxx()/2,getmaxy()-2); //Y co-ordinate
	line(2,getmaxy()/2-2,getmaxx()-2,getmaxy()/2-2); //X co-ordinate
	setcolor(10);
	outtextxy(getmaxx()/2+textwidth("Y"),2,"Y");
	outtextxy(getmaxx()/2,getmaxy()-textheight("Y`"),"Y`");
	outtextxy(getmaxx()-textwidth("X"),getmaxy()/2,"X");
	outtextxy(0,getmaxy()/2-textheight("X`"),"X`");
	outtextxy(getmaxx()/2+textheight("S"),getmaxy()/2-2*textheight("0"),"0,0");

	setcolor(14);
	sprintf(msg,"1Unit=%d pixel",scale);
	outtextxy(getmaxx()-textwidth(msg),getmaxy()-2*textheight("A"),msg);


	sprintf(msg,"Max X val=%d",getmaxx()/(2*scale));
	outtextxy(getmaxx()-textwidth(msg),getmaxy()-3*textheight("A"),msg);

	sprintf(msg,"Max Y val=%d",getmaxy()/(2*scale));
	outtextxy(getmaxx()-textwidth(msg),getmaxy()-4*textheight("A"),msg);
	sprintf(msg,"1Unit=%d pixel",scale);
	outtextxy(getmaxx()-textwidth(msg),getmaxy()-2*textheight("A"),msg);

	rectangle(getmaxx()-textwidth(msg)-scale,getmaxy()-5*textheight("A"),getmaxx(),getmaxy());

}

void convert_coord(int xa1,int ya1,int xb1,int yb1,int *xa,int *ya,int *xb,int *yb,int scale)
{
	      *xa=xa1*scale+(getmaxx()/2);
	      *ya=((getmaxy()/2)-((ya1)*scale));
	      *xb=xb1*scale+(getmaxx()/2);
	      *yb=((getmaxy()/2)-(yb1*scale));


}

void lineBres(int xa,int ya,int xb,int yb,int scale,int flag,int cord)
{
  int m;
  char *msg;
  int dx,dy,p,twody,twodydx,x,y,xEnd;
  clock_t start,end;
		   /*
	      xa=xa1*scale+(getmaxx()/2);
	      ya=((getmaxy()/2)-((ya1)*scale));
	      xb=xb1*scale+(getmaxx()/2);
	      yb=((getmaxy()/2)-(yb1*scale)); */
	 /*
	 line(xa,ya,xb,yb);//White line by Turbo C
	setfillstyle(1,getmaxcolor());
	circle(xa,ya,scale);
	circle(xb,yb,scale);
	sprintf(msg,"(%d,%d)",xa1,ya1);
	  outtextxy(xa+scale,ya,msg);
	  sprintf(msg,"(%d,%d)",xb1,yb1);
	  outtextxy(xb+scale,yb,msg);
	   */
	start=clock();
	dx=abs(xa-xb),dy=abs(ya-yb);
	p=2*dy-dx;
	twody=2*dy,twodydx=2*(dy-dx);
	if(xa>xb)
	{
		x=xb;
		y=yb;
		xEnd=xa;
	}
	else
	{
		x=xa;
		y=ya;
		xEnd=xb;
	}
	//putpixel(x,y,13);
	while(x<xEnd)
	{
		if (cord==2)
		 putpixel(y,x,13); // for 2nd qua
		else
		 putpixel(x,y,13);

		x++;
		if(p<0)
		{
			p+=twody;

		}
		else
		{
			if(flag==1)
			{
			  y++;


			}
			else
			{
			  y--;

			}
			p+=twodydx;
		}
		//delay(25);

	}
	end=clock();
	setcolor(14);
	sprintf(msg,"Time needed:%f",(end-start)/CLK_TCK);
	outtextxy(getmaxx()-textwidth(msg),(getmaxy()/2)-3*textheight("S"),msg);
}