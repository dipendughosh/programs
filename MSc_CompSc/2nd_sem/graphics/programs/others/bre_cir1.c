/****************************************************************************

		THIS PROGRAM IS CREATED BY SOUMIK GUHA ROY
		BRESENHAM CIRCLE DRAWING PROGRAM


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
   int gdriver = DETECT, gmode, errorcode,i,j,scale,xa1,ya1,xb1,yb1,temp,flag,xa,ya,r1;

   char *msg;

   /* initialize graphics and local variables */
      void Bresh_cir(int ,int ,int );


   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   if(argv!=4)
   {
      sprintf(msg,"Invalid input parameter...");
      outtextxy(getmaxx()/2,getmaxy()/2,msg);
      getch();
      closegraph();
      return 0;
   }

   /*Drawing the outline*/

   rectangle(0,0,getmaxx(),getmaxy());

   /*End of outline border*/

   line(getmaxx()/2,2,getmaxx()/2,getmaxy()-2); //Y co-ordinate
   line(2,getmaxy()/2-2,getmaxx()-2,getmaxy()/2-2); //X co-ordinate

   outtextxy(getmaxx()/2+textwidth("Y"),2,"Y");
   outtextxy(getmaxx()/2,getmaxy()-textheight("Y`"),"Y`");
   outtextxy(getmaxx()-textwidth("X"),getmaxy()/2,"X");
   outtextxy(0,getmaxy()/2-textheight("X`"),"X`");
   //outtextxy(getmaxx()/2,getmaxy()/2-2*textheight("0"),"0,0");


       //	putpixel(getmaxx()/2,getmaxy()/2,12);

	scale=textheight("Z")/2;


	settextstyle(3, 0, 1);
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

	xa1=atoi(args[1]);
	ya1=atoi(args[2]);
	r1=atoi(args[3]);

	setcolor(10);
	sprintf(msg,"Center: (%d %d)",xa1,ya1);
	putpixel(xa,ya,13);
	outtextxy(getmaxx()-textwidth(msg),getmaxy()/2-4*textheight("S"),msg);
	sprintf(msg,"Radius:%d",r1);
	outtextxy(getmaxx()-textwidth(msg),getmaxy()/2-2*textheight("S"),msg);


	Bresh_cir(xa1,ya1,r1);


   /* clean up */
//   sprintf(msg,"Created by Soumik Guha Roy");
//   outtextxy(0,getmaxy()-2*textheight("S"),msg);
   getch();
   closegraph();
   return 0;
}

void Bresh_cir(int xc,int yc,int R)
{
  int x=0;
  int y=R;
  int p=1-R;
  void circle_points(int ,int ,int ,int);

  circle_points(xc,yc,x,y);

  while(x<y)
  {
     x++;
     if(p<0)
      p+=2*x+1;
     else
     {
       y--;
       p+=2*(x-y)+1;
     }
     circle_points(xc,yc,x,y);
  }
}
void circle_points(int xc,int yc,int x,int y)
{
  void decide(int,int,int,int ,int);
  int scale;
  /*
  putpixel(xc+x,yc+y,13);
  putpixel(xc-x,yc+y,13);
  putpixel(xc+x,yc-y,13);
  putpixel(xc-x,yc-y,13);
  putpixel(xc+y,yc+x,13);
  putpixel(xc-y,yc+x,13);
  putpixel(xc+y,yc-x,13);
  putpixel(xc-y,yc-x,13);
*/
/*
  if (x==1)
   scale=textheight("H")/2;
  else*/
   scale=1;
  if(x!=0 && y!=0)
  {
   decide(xc+x,yc+y,xc-x,yc+y,scale);
   decide(xc+x,yc-y,xc-x,yc-y,scale);
   decide(xc+y,yc+x,xc-y,yc+x,scale);
   decide(xc+y,yc-x,xc-y,yc-x,scale);
  }

}

 void decide(int xa1,int ya1,int xb1,int yb1,int scale)
 {
	int xa,ya,xb,yb;
	char *msg;
	float m;
	void convert_coord(int,int ,int ,int ,int *,int *,int *,int *,int);
	void lineBres(int ,int ,int ,int ,int,int);

	convert_coord(xa1,ya1,xb1,yb1,&xa,&ya,&xb,&yb,scale);

	m=(float) (yb1-ya1)/(xb1-xa1);

	if(abs(m)<1.000000 && m >= 0.00000) //1st qua
	{
	      sprintf(msg,"1st qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);
	      lineBres(xa,ya,xb,yb,0,0);
	}
	else if(m >=1.00 ) //2nd qua
	{
	      sprintf(msg,"2nd qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);
	      lineBres(ya,xa,yb,xb,0,2);
	}

	else if(abs(m)<1.000000 && m <0.00) //8th qua
	{
	      sprintf(msg,"8th qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);
	      lineBres(xa,ya,xb,yb,1,0);
	}

	else if(abs(m)>=1.00 &&  m<=0.00)
	{
	      sprintf(msg,"7th qua...");
	      //outtextxy(getmaxx()/2+textheight("A"),getmaxy()/2-2*textheight("A"),msg);
	      lineBres(ya,xa,yb,xb,1,2);
	}
 }



void convert_coord(int xa1,int ya1,int xb1,int yb1,int *xa,int *ya,int *xb,int *yb,int scale)
{
	      *xa=xa1*scale+(getmaxx()/2);
	      *ya=((getmaxy()/2)-((ya1)*scale));
	      *xb=xb1*scale+(getmaxx()/2);
	      *yb=((getmaxy()/2)-(yb1*scale));
}


void lineBres(int xa,int ya,int xb,int yb,int flag,int cord)
{
  int m;
  char *msg;
  int dx,dy,p,twody,twodydx,x,y,xEnd;
  clock_t start,end;

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
	sprintf(msg,"Time needed:%f",(end-start)/CLK_TCK);
	//outtextxy(getmaxx()-textwidth(msg),(getmaxy()/2)-3*textheight("S"),msg);
}
