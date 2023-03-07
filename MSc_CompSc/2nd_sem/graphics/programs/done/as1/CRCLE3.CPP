/*Normal Circle fill with axis 1*/
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<dos.h>



class circleAlgo
{
	private:
		int xMax,yMax;
		int xc,yc,r;
	public:
		circleAlgo()
		{
		}
		void execute();
		void screenInitialize();
		void drawCoordinates();
		void getdata();
		void setCirclePixel(int,int);
		void circleDraw();
		~circleAlgo()
		{
			closegraph();
		}
};

void circleAlgo::execute()
{
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	circleDraw();
	getch();
}

void circleAlgo::screenInitialize()
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

void circleAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Circle");
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

void circleAlgo::getdata()
{
	do
	{
		cout<<"Enter Center co-ordinates:-\nX-coordinate:- ";
		cin>>xc;
		cout<<"Y-coordinate:- ";
		cin>>yc;
		cout<<"Enter Radius:- ";
		cin>>r;
		if(r <= 0)
			cout<<"Re-Enter correct radius(must be positive\n";
		else
			break;
	}while(1);
	xc=4*xc;
	yc=4*yc;
	r=4*r;
}

void circleAlgo::circleDraw()
{
	int x,y,h;
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
	setcolor(88);
	for(int i=0;i<r;i++)
	{
		circle(xMax/2+xc,yMax/2-yc,i);
		delay(20);
	}
	gettime(&t2);
	gotoxy(10,30);
	printf("%2d:%02d:%02d.%06ld",t2.ti_hour-t1.ti_hour, t2.ti_min-t1.ti_min, t2.ti_sec-t1.ti_sec, t2.ti_hund-t1.ti_hund);
	setcolor(255);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}

void circleAlgo::setCirclePixel(int x,int y)
{
	//setcolor(25);
	//line(xMax/2+xc+x,yMax/2-yc-y,xMax/2+xc-x,yMax/2-yc+y);
	putpixel(xMax/2+xc+x,yMax/2-yc-y,5);
	putpixel(xMax/2+xc-x,yMax/2-yc+y,5);
	//delay(200);
	//setcolor(55);
	//line(xMax/2+xc-x,yMax/2-yc-y,xMax/2+xc+x,yMax/2-yc+y);
	putpixel(xMax/2+xc-x,yMax/2-yc-y,155);
	putpixel(xMax/2+xc+x,yMax/2-yc+y,155);
	//delay(200);
	//setcolor(25);
	//line(xMax/2+xc-y,yMax/2-yc-x,xMax/2+xc+y,yMax/2-yc+x);
	putpixel(xMax/2+xc-y,yMax/2-yc-x,5);
	putpixel(xMax/2+xc+y,yMax/2-yc+x,5);
	//delay(200);
	//setcolor(55);
	//line(xMax/2+xc-y,yMax/2-yc+x,xMax/2+xc+y,yMax/2-yc-x);
	putpixel(xMax/2+xc-y,yMax/2-yc+x,155);
	putpixel(xMax/2+xc+y,yMax/2-yc-x,155);
	//delay(200);
}


int main()
{
	circleAlgo ob;
	ob.execute();
	return 0;
}


