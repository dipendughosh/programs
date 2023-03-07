#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
void drawaxis();
void timeinterval();
void drawline(int x1,int y1,int x2,int y2,int dc,int sw);
struct time t1,t2;
int xmax,ymax;
void main()
{
 int xa,ya,xb,yb,th,x1,x2,y2,y1,i;
 float m;
 /* Request auto detection of graphics mode */
 int gdriver=DETECT,gmode,errorcode;
 /* initialize graphics mode */
 initgraph(&gdriver,&gmode, "c:\\tc\\bgi\\");
 /* Taking the end points data */
 printf("The Starting Co-ordinates:\n\tX:");
 scanf("%d",&xa);
 printf("\n\tY:");
 scanf("%d",&ya);
 printf("The Ending Co-ordinates:\n\tX:");
 scanf("%d",&xb);
 printf("\n\tY:");
 scanf("%d",&yb);
 printf("\n Enter the thickness of the line \n");
 scanf("%d",&th);
 cleardevice();
 gettime(&t1);
 drawaxis();
	if(xa==xb)
		drawline(4*ya,4*xa,4*yb,4*xb,0,1); //parallel to y axis
	else
	{
		m=(float)(yb-ya)/(xb-xa);
		if(abs(m)<1.0 && m >= 0.0) //1st octant or 5th octant
			drawline(4*xa,4*ya,4*xb,4*yb,0,0);
		else if(abs(m) >=1.0 && m>0.0) //2nd octant or 6th octant
			drawline(4*ya,4*xa,4*yb,4*xb,0,1);
		else if(abs(m)<1.0 && m <0.0) //4 th or 8th octant
			drawline(4*xa,4*ya,4*xb,4*yb,1,0);
		else if(abs(m)>=1.0 &&  m<=0.0)  // 3rd or 7 th octant
			drawline(4*ya,4*xa,4*yb,4*xb,1,1);
	}
  // as 1 unit=4 pixels
	// making thickness
	x1=4*xa;
	x2=4*xb;
	y1=4*ya;
	y2=4*yb;
	setcolor(14);
	if((xb-xa)==0)
	{
	    for(i=0;i<=th;i++)
	  {
	   line(xmax/2+(x1+i),ymax/2-(y1),xmax/2+(x2+i),ymax/2-(y2));
	  line(xmax/2+(x1-i),ymax/2-(y1),xmax/2+(x2-i),ymax/2-(y2));
	  }
	}
	else if((yb-ya)==0)
       {
	 for(i=0;i<=th;i++)
	  {
	   line(xmax/2+(x1),ymax/2-(y1-i),xmax/2+(x2),ymax/2-(y2-i));
	  line(xmax/2+(x1),ymax/2-(y1+i),xmax/2+(x2),ymax/2-(y2+i));
	  }
       }
       else
       {
	if(m>0)
	{
	 line(xmax/2+(x1-th),ymax/2-(y1+th),xmax/2+(x1+th),ymax/2-(y1-th));
	  line(xmax/2+(x2+th),ymax/2-(y2-th),xmax/2+(x2-th),ymax/2-(y2+th));
	  for(i=0;i<=th;i++)
	  {
	   line(xmax/2+(x1+i),ymax/2-(y1-i),xmax/2+(x2+i),ymax/2-(y2-i));
	  line(xmax/2+(x1-i),ymax/2-(y1+i),xmax/2+(x2-i),ymax/2-(y2+i));
	  }
	}
	else
	{
	  line(xmax/2+(x1-th),ymax/2-(y1-th),xmax/2+(x1+th),ymax/2-(y1+th));
	  line(xmax/2+(x2+th),ymax/2-(y2+th),xmax/2+(x2-th),ymax/2-(y2-th));
	  for(i=0;i<=th;i++)
	  {
	  line(xmax/2+(x1-i),ymax/2-(y1-i),xmax/2+(x2-i),ymax/2-(y2-i));
	  line(xmax/2+(x1+i),ymax/2-(y1+i),xmax/2+(x2+i),ymax/2-(y2+i));
	  }
	}
      delay(30);
       }
 gettime(&t2);
 timeinterval();
 getch();
 closegraph();
}
void drawaxis()
{

	char msg1[80],msg2[80];
	xmax=getmaxx();
	ymax=getmaxy();
	sprintf(msg1,"Bresenham Line Drawing");
	sprintf(msg2,"Scale:- 1 Unit = 4 Pixels");
		/* Put labels */
	outtextxy(xmax/2-textwidth(msg1)/2,0,msg1);
	outtextxy(9,ymax/2+5,"X'");
	outtextxy(xmax-textwidth("X")-9,ymax/2+5,"X");
	outtextxy(xmax/2+3,textheight(msg1)+5,"Y");
	outtextxy(xmax/2+3,ymax-3*textheight("Y'")-4,"Y'");
	outtextxy(7,ymax-4*textheight("Time Taken:=")-8,"Time Taken:");
	outtextxy(xmax-textwidth(msg2),ymax-textheight(msg2),msg2);
	/* Drawing the borders */
	rectangle(4,textheight(msg1),xmax-4,ymax-2*textheight(msg2));
	/* Drawing X & Y Axis*/
	line(4,ymax/2,xmax-4,ymax/2);   //y axis
	line(xmax/2,textheight(msg1),xmax/2,ymax-2*textheight(msg2)); //x-axis

}
void drawline(int x1,int y1,int x2,int y2,int dc,int sw)
{       // dc indicates y will be decreamented or incremented
	// sw indicated x,y are swapped or nor
	int dx,dy,d,k;
	float xinc,yinc,x,y,xend,yend;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	d=2*dy-dx;
	if(dx!=0)
	if(x1>x2)
	{
		x=x2;
		y=y2;
		xend=x1;
	 }
	else
	{
		x=x1;
		y=y1;
		xend=x2;
	 }
	 if(sw==0)
	putpixel(xmax/2+x,ymax/2-y,15);
	else
	 putpixel(xmax/2+y,ymax/2-x,15);
	while(x<xend)
	{
		x++;
		if(d<0)
		   d+=2*dy;
		else
		{
			d+=2*(dy-dx);
			if(dc==0)
			y++;
			else
			 y--;
		}

		 if(sw==0)
	putpixel(xmax/2+x,ymax/2-y,15);
	else
	 putpixel(xmax/2+y,ymax/2-x,15);
	}

}

/*This function calculates the time interval between the starting and ending time*/
void timeinterval()
{
	int min,sec;
	long int ssec;
	if(t1.ti_hund>t2.ti_hund)
	{
	 ssec=100+t1.ti_hund-t2.ti_hund;
	 (t1.ti_sec)--;
	}
	else
	ssec=t2.ti_hund-t1.ti_hund;
	if(t1.ti_sec>t2.ti_sec)
	{
	 sec=60+t1.ti_sec-t2.ti_sec;
	 (t1.ti_min)--;
	}
	else
	sec=t2.ti_sec-t1.ti_sec;
	min=t2.ti_min-t1.ti_min;
      printf("%2dmin :%2dsec :%ldhsec",t1.ti_min,t1.ti_sec,t1.ti_hund);
      printf("%2dmin :%2dsec :%ldhsec",t2.ti_min,t2.ti_sec,t2.ti_hund);
       gotoxy(16,28);
       printf("%dmin :%dsec :%ldhsec\n",min,sec,ssec);
}
