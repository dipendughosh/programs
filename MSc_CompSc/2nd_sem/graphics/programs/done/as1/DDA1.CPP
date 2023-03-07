/*DDA without axis*/
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

class ddaAlgo
{
	private:
		int xStart,xEnd,yStart,yEnd,maxx,maxy;
		public:
		ddaAlgo()
		{
			xStart=0;
			yStart=0;
			xEnd=0;
			yEnd=0;
		}
		void screenInitialize();
		void getdata();
		void ddaLine();
		int round(int);
		~ddaAlgo()
		{
		}
};

void ddaAlgo::screenInitialize()
{
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	maxx=getmaxx();
	maxy=getmaxy();
}

void ddaAlgo::getdata()
{       do
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
}

void ddaAlgo::ddaLine()
{
	int dx,dy,steps,i;
	float xInc,yInc,x,y;
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
	putpixel(round(x),maxy-round(y),255);
	for(i=0;i<steps;i++)
	{
		x=x+xInc;
		y=y+yInc;
		putpixel(round(x),maxy-round(y),255);
	}
}

int ddaAlgo::round(int n)
{
	return ((int)(n+0.5));
}

int main()
{
	ddaAlgo ob;
	ob.screenInitialize();
	ob.getdata();
	ob.ddaLine();
	getch();
	return 0;
}