/*Ellipse with axis and fill*/

#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

/*The class whose objects are used is defined*/
class ellipseAlgo
{
	private:
		int xMax,yMax;
		int xc,yc;
		float a,b;
		struct time t1,t2;
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
		void timeint();
		~ellipseAlgo()
		{
			closegraph();
		}
};

/*The function execute() performs sequentially the tasks for drawing an ellipse*/
void ellipseAlgo::execute()
{
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	ellipseDraw();
	getch();
}

/*The function below initializes the screen graphics mode and checks for any errors.*/
void ellipseAlgo::screenInitialize()
{
	/*Request auto detection*/
	int gdriver = DETECT, gmode, errorcode;

	/*Initialize graphics mode*/
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	outport(0x0378,0x00);

	/*Read result of initialization*/
	errorcode = graphresult();
	if (errorcode != grOk)/*An error occured*/
	{
		cout<<"Graphics error: %s\n"<<grapherrormsg(errorcode);
		cout<<"Press any key to halt:";
		getch();
		exit(0);
	}

	/*Set the maximum no. of points that can be plotted on the display screen both in X-direction and in Y-direction*/
	xMax=getmaxx();
	yMax=getmaxy();
}

/*The function drawCoordintes() is used to draw co-ordinate axes on the display screen.*/
void ellipseAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Ellipse");
	outtextxy(xMax/2-textwidth(msg)/2,0,msg);

	/*The lines of the co-ordinate axes are drawn*/
	line(4,yMax/2,xMax-4,yMax/2);
	line(xMax/2,textheight(msg),xMax/2,yMax-2*textheight(msg));

	/*The different axes is named*/
	outtextxy(9,yMax/2+5,"X");
	gotoxy(3,16);
	cout<<"'";
	outtextxy(xMax-textwidth("X")-9,yMax/2+5,"X");
	outtextxy(xMax/2,textheight(msg)+5,"Y");
	outtextxy(xMax/2,yMax-3*textheight("Y")-4,"Y");
	gotoxy(42,29);
	cout<<"'";

	/*Time is calculated and displayed below.
	  The scale is also displayed.*/
	sprintf(msg,"Time:- ");
	gotoxy(2,30);
	cout<<msg;
	sprintf(msg,"Scale:- 1 Unit = 4 Pixels");
	gotoxy(55,30);
	cout<<msg;

	/*Giving a border to the co-ordinate axes.*/
	rectangle(4,textheight(msg),xMax-4,yMax-2*textheight(msg)+1);
}

/*The getdata() is used to accept the information about an ellipse*/
void ellipseAlgo::getdata()
{
	/*The block below gets the center of the ellipse ane the values of a and b*/
	cout<<"Enter Center co-ordinates:-\nX-coordinate:- ";
	cin>>xc;
	cout<<"Y-coordinate:- ";
	cin>>yc;
	cout<<"Enter a:- ";
	cin>>a;
	cout<<"Enter b:- ";
	cin>>b;

	/*The center and a and b is set according to the co-ordinate axes drawn on screen*/
	xc=4*xc;
	yc=4*yc;
	a=4*a;
	b=4*b;
}

/*Ellipse Drawing Algorithm code*/
void ellipseAlgo::ellipseDraw()
{
	float x,y,sa,sb,d;
	gettime(&t1);
	x=0;
	y=b;
	sa=a*a;
	sb=b*b;
	d=(b*b)+(a*a*(1/4-b));
	setEllipsePixel(x,y);
	while((sb*(x+1)) < (sa*(y-1/2)))
	{ 	
		/*condition to select between East or South-East*/
		if(d < 0)
			d=d+(sb*(2*x+3));
		else
		{
			d=d+(sb*(2*x+3))-(sa*(2*y-2));
			y=y-1;
		}
		x=x+1;
		setEllipsePixel(x,y);
	}
	d=(sb*(x+1/2)*(x+1/2))+(sa*(y-1)*(y-1))-(sa*sb);
	while(y > 0)
	{
		/*condition to select between South-East and South*/
		if(d < 0)
		{
			d=d+(sb*(2*x+2))-(sa*(2*y-3));
			x=x+1;
		}
		else
			d=d-(sa*(2*y-3));
		y=y-1;
		setEllipsePixel(x,y);
	}
	gettime(&t2);
	timeint();
}

/*The function below plots the points on the display screen.*/
void ellipseAlgo::setEllipsePixel(int x,int y)
{
	putpixel(xMax/2+xc+x,yMax/2-yc-y,255);
	putpixel(xMax/2+xc-x,yMax/2-yc-y,255);
	putpixel(xMax/2+xc-x,yMax/2-yc+y,255);
	putpixel(xMax/2+xc+x,yMax/2-yc+y,255);
	setcolor(12);
	/*Lines to give fill the ellipse*/
	line(xMax/2+xc+x-1,yMax/2-yc-y+1,xMax/2+xc-x+1,yMax/2-yc-y+1);
	line(xMax/2+xc-x+1,yMax/2-yc+y-1,xMax/2+xc+x-1,yMax/2-yc+y-1);
	setcolor(15);
	delay(20);
}

/*This function calculates the time interval between the starting and ending time*/
void ellipseAlgo::timeint()
{
	int min,sec;
	long int hsec;
	if(t1.ti_hund>t2.ti_hund)
	{
		hsec=100+t1.ti_hund-t2.ti_hund;
		(t1.ti_sec)=(t1.ti_sec)-1;
	}
	else
		hsec=t2.ti_hund-t1.ti_hund;
	if(t1.ti_sec>t2.ti_sec)
	{
		sec=60+t1.ti_sec-t2.ti_sec;
		(t1.ti_min)=(t1.ti_min)-1;
	}
	else
		sec=t2.ti_sec-t1.ti_sec;
	min=t2.ti_min-t1.ti_min;
	gotoxy(10,30);
	printf("%d min : %d sec : %ld hsec",min,sec,hsec);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}

/*Main function*/
int main()
{
	ellipseAlgo ob;
	ob.execute();
	return 0;
}