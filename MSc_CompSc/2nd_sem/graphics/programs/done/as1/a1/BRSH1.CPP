/*Breshnham with co-ordinates*/

#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>


/*The class whose objects are used is defined*/
class bhnAlgo
{
	private:
		int xMax,yMax;
		int xStart,xEnd,yStart,yEnd;
		struct time t1,t2;
	public:
		bhnAlgo()
		{
		}
		void execute();
		void screenInitialize();
		void drawCoordinates();
		void getdata();
		void bhnLine(int,int,int,int,int,int);
		void timeint();
		~bhnAlgo()
		{
			closegraph();
		}
};


/*The function execute() sequentially performs the tasks for drawing a line.*/
void bhnAlgo::execute()
{
	float m;
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	
	/*Case when the starting and ending x points are same*/
	/*Parallel to y axis*/
	if(xStart==xEnd)
		bhnLine(yStart,xStart,yEnd,xEnd,0,1);
		
	/*Case when the starting and ending points are different. 
	  Here the function bhnLine() is called according to slope of the line to be drawn.
	  Different parameters are passed for each case*/	
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
	getch();
}


/*The function below initializes the screen graphics mode and checks for any errors.*/
void bhnAlgo::screenInitialize()
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
void bhnAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Bresenham Algorithm");
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
void bhnAlgo::getdata()
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
	
	/*The starting and ending points are set according to our co-ordinate axes drawn on screen*/
	xStart=(4*xStart);
	yStart=(4*yStart);
	xEnd=(4*xEnd);
	yEnd=(4*yEnd);
}

/*Bresenham's Line Drawing Algorithm code.*/
void bhnAlgo::bhnLine(int xS,int yS,int xE,int yE,int f,int c)
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

/*This function calculates the time interval between the starting and ending time*/
void bhnAlgo::timeint()
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
	printf("%d min : %d sec : %2ld hsec",min,sec,hsec);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}

/*Main function*/
int main()
{
	bhnAlgo ob;
	ob.execute();
	return 0;
}