/*Normal Circle with axis*/

#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

/*The class whose objects are used is defined*/
class circleAlgo
{
	private:
		int xMax,yMax;
		int xc,yc,r;
		struct time t1,t2;
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
		void timeint();
		~circleAlgo()
		{
			closegraph();
		}
};

/*The function execute() performs sequentially the tasks for drawing a circle*/
void circleAlgo::execute()
{
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	circleDraw();
	getch();
}

/*The function below initializes the screen graphics mode and checks for any errors.*/
void circleAlgo::screenInitialize()
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
void circleAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Circle");
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

/*The getdata() is used to accept the center and radius of a circle*/
void circleAlgo::getdata()
{
	/*The block below gets the radius and the co-ordinates of the center from the user. Only the correct radius are taken.*/
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
	
	/*The center and radius is set according to the co-ordinate axes drawn on screen*/
	xc=4*xc;
	yc=4*yc;
	r=4*r;
}

/*Circle Drawing Algorithm code*/
void circleAlgo::circleDraw()
{
	int x,y,h;
	gettime(&t1);
	x=0;
	y=r;
	h=1-r;
	setCirclePixel(x,y);
	while(y > x)
	{
		/*condition to select between East or South-East*/ 
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
	gettime(&t2);
	timeint();
}

/*The function setCirclePixel is used to plot the respective points in each octant each time it is called*/
void circleAlgo::setCirclePixel(int x,int y)
{
    putpixel(xMax/2+xc+x,yMax/2-yc-y,5);
    putpixel(xMax/2+xc-x,yMax/2-yc-y,155);
    putpixel(xMax/2+xc-y,yMax/2-yc-x,5);
    putpixel(xMax/2+xc-y,yMax/2-yc+x,155);
    putpixel(xMax/2+xc-x,yMax/2-yc+y,5);
    putpixel(xMax/2+xc+x,yMax/2-yc+y,155);
    putpixel(xMax/2+xc+y,yMax/2-yc+x,5);
    putpixel(xMax/2+xc+y,yMax/2-yc-x,155);
    delay(20);
}

/*This function calculates the time interval between the starting and ending time*/
void circleAlgo::timeint()
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
	circleAlgo ob;
	ob.execute();
	return 0;
}