/*dda with axis*/

#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

/*The class whose objects are used is defined*/
class ddaAlgo
{
	private:
		int xMax,yMax;
		int xStart,xEnd,yStart,yEnd;
		struct time t1,t2;
	public:
		ddaAlgo()
		{
		}
		void execute();
		void screenInitialize();
		void drawCoordinates();
		void getdata();
		void ddaLine();
		int round(int);
		void timeint();
		~ddaAlgo()
		{
			closegraph();
		}
};


/*The function execute() performs tasks for drawing a line*/
void ddaAlgo::execute()
{
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	ddaLine();
	getch();
}

/*The function below initializes the screen graphics mode and checks for any errors.*/
void ddaAlgo::screenInitialize()
{
	/*Request auto detection*/
	int gdriver = DETECT, gmode, errorcode;
	
	/*Initialize graphics mode*/
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	outport(0x0378,0x00);
	
	/*Read result of initialization*/
	errorcode = graphresult();
	if (errorcode != grOk)
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
void ddaAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"DDA");
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

/*The getdata() is used to accept the starting and ending points of a line*/
void ddaAlgo::getdata()
{
	/*The block below gets the values of two points from the user. Only correct points are taken.*/
	do
	{
		cout<<"Enter Starting co-ordinates:-\nX-coordinate:- ";
		cin>>xStart;
		cout<<"Y-coordinate:- ";
		cin>>yStart;
		cout<<"Enter Ending co-ordinates:-\nX-coordinate:- ";
		cin>>xEnd;
		cout<<"Y-coordinate:- ";
		cin>>yEnd;
		if(xStart == xEnd && yStart == yEnd)
			cout<<"Starting and Ending vertices are same\n\nRe-Enter";
		else
			break;
	}while(1);
	
	/*The starting and ending points are set according to the co-ordinate axes drawn on screen */
	xStart=4*xStart;
	yStart=4*yStart;
	xEnd=4*xEnd;
	yEnd=4*yEnd;
}

/*DDA Algorithm code*/
void ddaAlgo::ddaLine()
{
	int dx,dy,steps,i;
	float xInc,yInc,x,y;
	gettime(&t1);
	dx=xEnd-xStart;
	dy=yEnd-yStart;
	yStart=yStart;
	yEnd=yEnd;
	x=xStart;
	y=yStart;
	if(abs(dx) > abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xInc=dx/(float)steps;
	yInc=dy/(float)steps;
	putpixel(round(x)+xMax/2,yMax/2-round(y),255);
	for(i=0;i<steps;i++)
	{
		x=x+xInc;
		y=y+yInc;
		putpixel(round(x)+xMax/2,yMax/2-round(y),255);
	}
	delay(200);
	gettime(&t2);
	timeint();
}

/*Returns the rounded value of an integer*/
int ddaAlgo::round(int n)
{
	return ((int)(n+0.5));
}

/*This function calculates the time interval between the starting and ending time*/
void ddaAlgo::timeint()
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
	ddaAlgo ob;
	ob.execute();
	return 0;
}