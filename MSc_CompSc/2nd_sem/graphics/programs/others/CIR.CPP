#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
void drawaxis();
void timeinterval();
void setCirclePixel(int,int);
void fill(int ,int,int );
void drawcircle(int x1,int y1,int r);
struct time t1,t2;
int xc,yc;
int xMax,ymax,yMax,xmax;
void main()
{
 int r;
 /* Request auto detection of graphics mode */
 int gdriver=DETECT,gmode,errorcode;
 /* initialize graphics mode */
 initgraph(&gdriver,&gmode, "c:\\tc\\bgi\\");
 /* Taking the end points data */
 printf("The center Co-ordinates:\n\tX:");
 scanf("%d",&xc);
 printf("\n\tY:");
 scanf("%d",&yc);
 printf("\n Enter the radious of the circle \n");
 scanf("%d",&r);
 cleardevice();
 gettime(&t1);
 drawaxis();
 drawcircle(xc,yc,r); // as 1 unit=4 pixels
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
	xMax=xmax;
	yMax=ymax;
	sprintf(msg1,"Midpoint Circle Drawing");
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
      // printf("%2dmin :%2dsec :%ldhsec",t1.ti_min,t1.ti_sec,t1.ti_hund);
      // printf("%2dmin :%2dsec :%ldhsec",t2.ti_min,t2.ti_sec,t2.ti_hund);
       gotoxy(16,28);
       printf("%dmin :%dsec :%ldhsec\n",min,sec,ssec);
}

void drawcircle(int x,int y,int r)
{
	int h;
	struct time t1,t2;
	gettime(&t1);
	x=0;
	y=r;
	h=1-r;
	setCirclePixel(x,y);
	while(y > x)
	{
		if(h <= 0)
			h=h+(2*x)+3;
		else
		{
			h=h+2*(x-y)+5;
			y=y-1;
	    }
	    x=x+1;
	    setCirclePixel(x,y);
	}
       //	gettime(&t2);
       //	gotoxy(10,30);

       //	printf("%2d:%02d:%02d.%06ld",t2.ti_hour-t1.ti_hour, t2.ti_min-t1.ti_min, t2.ti_sec-t1.ti_sec, t2.ti_hund-t1.ti_hund);
       //	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
       fill(xc,yc,r);
}
void setCirclePixel(int x,int y)
{
    putpixel(xMax/2+xc+x,yMax/2-yc-y,5);
    putpixel(xMax/2+xc-x,yMax/2-yc-y,155);
    putpixel(xMax/2+xc-y,yMax/2-yc-x,5);
    putpixel(xMax/2+xc-y,yMax/2-yc+x,155);
    putpixel(xMax/2+xc-x,yMax/2-yc+y,5);
    putpixel(xMax/2+xc+x,yMax/2-yc+y,155);
    putpixel(xMax/2+xc+y,yMax/2-yc+x,5);
    putpixel(xMax/2+xc+y,yMax/2-yc-x,155);
}
void fill(int x,int y,int r)
{
	float dis;
	int current=getpixel(x,y);
	dis=sqrt(pow((x-xc),2)+pow((y-yc),2));
	printf("%f\n",dis);

	if(ceil(dis)<r)
	{
		putpixel(xmax/2+x,ymax/2-y,14);
		getch();
		fill(x+1,y,r);
		fill(x-1,y,r);
		fill(x,y+1,r);
		fill(x,y-1,r);
	}
}