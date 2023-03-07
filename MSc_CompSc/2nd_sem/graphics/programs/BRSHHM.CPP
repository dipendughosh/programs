//Mouse breshnham
#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

union REGS in, out;
struct time t1,t2;

class mouse
{
	private:
		int xMax,yMax;
	public:
		mouse()
		{
			screenInitialize();
		}
		void screenInitialize();
		void drawCoordinates();
		void restrict(int,int,int,int);
		void detect_mouse();
		void showmouse();
		void getmousepos(int *,int *,int *);
		void timeint();
		void dline(int,int,int,int);
		void bhnLine(int,int,int,int,int,int);
		~mouse()
		{
			closegraph();
		}
};

void mouse::screenInitialize()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	outport(0x0378,0x00);
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		cout<<"Graphics error: %s\n"<<grapherrormsg(errorcode);
		cout<<"Press any key to halt:";
		getch();
		exit(0);
	}
	cleardevice();
	xMax=getmaxx();
	yMax=getmaxy();
	detect_mouse();
	drawCoordinates();
	showmouse();
}

void mouse::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Title");
	outtextxy(xMax/2-textwidth(msg)/2,0,msg);
	line(4,yMax/2,xMax-4,yMax/2);
	line(xMax/2,textheight(msg),xMax/2,yMax-2*textheight(msg));
	outtextxy(9,yMax/2+5,"X");
	gotoxy(3,16);
	cout<<"'";
	outtextxy(xMax-textwidth("X")-9,yMax/2+5,"X");
	outtextxy(xMax/2,textheight(msg)+5,"Y");
	outtextxy(xMax/2,yMax-3*textheight("Y")-4,"Y");
	gotoxy(42,29);
	cout<<"'";
	sprintf(msg,"Time:- ");
	gotoxy(2,30);
	cout<<msg;
	sprintf(msg,"Scale:- 1 Unit = 4 Pixels");
	gotoxy(55,30);
	cout<<msg;
	rectangle(4,textheight(msg),xMax-4,yMax-2*textheight(msg)+1);
	restrict(4,textheight(msg),xMax-4,yMax-2*textheight(msg)+1);
}

void mouse::restrict(int x1,int y1,int x2,int y2)
{
	in.x.ax = 7;
	in.x.cx = x1;
	in.x.dx = x2;
	int86 (0X33,&in,&out);
	in.x.ax = 8;
	in.x.cx = y1;
	in.x.dx = y2;
	int86 (0X33,&in,&out);
}

void mouse::detect_mouse()
{
	in.x.ax = 0;
	int86 (0X33,&in,&out);
	if (out.x.ax == 0)
	{
		cout<<"Mouse Fail To Initialize";
		cout<<"Press any key to halt:";
		getch();
		exit(0);
	}
}

void mouse::showmouse()
{
	in.x.ax = 1;
	int86 (0X33,&in,&out);
}

void mouse::getmousepos(int *button,int *x,int *y)
{
	in.x.ax = 3;
	int86 (0X33,&in,&out);
	*button=out.x.bx;
	*x = out.x.cx;
	*y = out.x.dx;
}

void mouse::timeint()
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
	gotoxy(10,30);
	printf("%d min :%d sec :%ld hsec",min,sec,ssec);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}

void mouse::dline(int xStart,int xEnd,int yStart,int yEnd)
{
	float m;
	if(xStart==xEnd)
		bhnLine(yStart,xStart,yEnd,xEnd,0,1);
	else
	{
		m=(float)(yEnd-yStart)/(xEnd-xStart);
		if(abs(m)<1.0 && m >= 0.0) //1st octant or 5th octant
			bhnLine(xStart,yStart,xEnd,yEnd,0,0);
		else if(abs(m) >=1.0 && m > 0.0) //2nd octant or 6th octant
			bhnLine(yStart,xStart,yEnd,xEnd,0,1);
		else if(abs(m)<1.0 && m <0.0) //4 th or 8th octant
			bhnLine(xStart,yStart,xEnd,yEnd,1,0);
		else if(abs(m)>=1.0 &&  m<=0.0) // 3rd or 7 th octant
			bhnLine(yStart,xStart,yEnd,xEnd,1,1);
	}
}

void mouse::bhnLine(int xS,int yS,int xE,int yE,int f,int c)
{
	/*f indicates if y will be decreamented or incremented*/
	/*c indicates if x and y are swapped or not*/
	int dx,dy,steps,i,dS,dE,dNE,x,y,xF;
	int xt,yt;
	gettime(&t1);
	dx=abs(xE-xS);
	dy=abs(yE-yS);
	dS=(2*dy)-dx;
	dE=2*dy;
	dNE=2*(dy-dx);
	if(xS>xE)
	{
		x=xE;
		y=yE;
		xF=xS;
	}
	else
	{
		x=xS;
		y=yS;
		xF=xE;
	}
	if(c==0)
		putpixel(xMax/2+x,yMax/2-y,10);
	else
		putpixel(xMax/2+y,yMax/2-x,10);
	while(x<xF)
	{
		x++;
		/*this comdition selects which point is to be chossen between East or North-East*/
		if(dS<0)
			dS+=dE;
		else
		{
			if(f==0)
				y++;
			else
				y--;
			dS+=dNE;
		}
		if(c==0)
			putpixel(xMax/2+x,yMax/2-y,10);
		else
			putpixel(xMax/2+y,yMax/2-x,10);
	}
	delay(200);
	gettime(&t2);
	timeint();
}

int main ()
{
	mouse ob;
	int x,y,button,xMax,yMax,xStart,xEnd,yStart,yEnd,f=0;
	xMax=getmaxx();
	yMax=getmaxy();
	while (!kbhit () )
	{
		ob.getmousepos(&button,&x,&y);
		gotoxy(35,30);
		cout<<"X:- "<<x<<" Y:- "<<y<<"  ";
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		if(out.x.bx == 1)
		{
			if(f==0)
			{
				xStart=x-xMax/2;
				yStart=yMax/2-y;
				f=1;
				delay(200);
			}
			else
			{
				xEnd=x-xMax/2;
				yEnd=yMax/2-y;
				f=0;
				ob.dline(xStart,xEnd,yStart,yEnd);
			}
		}
		rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
	}
	getch();
	return 0;
}