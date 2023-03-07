/*Ellipse with axis 2*/
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<dos.h>



class ellipseAlgo
{
	private:
		int xMax,yMax;
		int xc,yc,a,b;
	public:
		ellipseAlgo()
		{
		}
		void execute();
		void screenInitialize();
		void drawCoordinates();
		void getdata();
		void setEllipsePixel(int,int);
		void ellipseDraw();
		~ellipseAlgo()
		{
			closegraph();
		}
};

void ellipseAlgo::execute()
{
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	ellipseDraw();
	getch();
}

void ellipseAlgo::screenInitialize()
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
	xMax=getmaxx();
	yMax=getmaxy();
}

void ellipseAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Ellipse");
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
}

void ellipseAlgo::getdata()
{
	do
	{
		cout<<"Enter Center co-ordinates:-\nX-coordinate:- ";
		cin>>xc;
		cout<<"Y-coordinate:- ";
		cin>>yc;
		cout<<"Enter b:- ";
		cin>>b;
		cout<<"Enter a:- ";
		cin>>a;
		if(b > a)
			cout<<"Value of \"b\" is greater than \"a\"\nRe-Enter\n";
		else
			break;
	}while(1);
	xc=4*xc;
	yc=4*yc;
	a=4*a;
	b=4*b;
}

void ellipseAlgo::ellipseDraw()
{
	int x,y,h,sa,sb,d,tsa,tsb,dx,dy;
	struct time t1,t2;
	gettime(&t1);
	x=0;
	y=b;
	sa=a*a;
	sb=b*b;
	tsa=2*sa;
	tsb=2*sb;
	dx=0;
	dy=tsa*y;
	d=tsb-(tsa*sb)+(1/4*tsa);
	setEllipsePixel(x,y);
	while(dx < dy)
	{ 	
		dx=dx+tsb;
		if(d < 0)
			d=d+sb+dx;
		else
		{
			dy=dy-tsa;
			d=d+sb+dx-dy;
			y=y-1;
		}
		x=x+1;
		setEllipsePixel(x,y);
	}
	d=(sb*(x+1/2)*(x+1/2))+(sa*(y-1)*(y-1))-(sa*sb);
	while(y > 0)
	{
		dy=dy-tsa;
		if(d < 0)
		{
			dx=dx+tsb;
			d=d+sa-dy+dx;
			x=x+1;
		}
		else
			d=d+sa-dy;
		y=y-1;
		setEllipsePixel(x,y);
	}
	gettime(&t2);
	gotoxy(10,30);
	printf("%2d:%02d:%02d.%08ld",t2.ti_hour-t1.ti_hour, t2.ti_min-t1.ti_min, t2.ti_sec-t1.ti_sec, t2.ti_hund-t1.ti_hund);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}

void ellipseAlgo::setEllipsePixel(int x,int y)
{
    putpixel(xMax/2+xc+x,yMax/2-yc-y,255);
    putpixel(xMax/2+xc-x,yMax/2-yc-y,255);
    putpixel(xMax/2+xc-x,yMax/2-yc+y,255);
    putpixel(xMax/2+xc+x,yMax/2-yc+y,255);
}

int main()
{
	ellipseAlgo ob;
	ob.execute();
	return 0;
}
