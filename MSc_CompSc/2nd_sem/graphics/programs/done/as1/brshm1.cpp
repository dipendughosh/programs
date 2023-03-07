/*Breshnham without coordinate 1*/
#include<iostream.h>
#include<graphics.h>
#include<conio.h>

class bhnAlgo
{
	private:
		int xStart,xEnd,yStart,yEnd,maxx,maxy;
		public:
		bhnAlgo()
		{
			xStart=0;
			yStart=0;
			xEnd=0;
			yEnd=0;
		}
		void screenInitialize();
		void getdata();
		void bhnLine();
		~bhnAlgo()
		{
		}
};

void bhnAlgo::screenInitialize()
{
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	maxx=getmaxx();
	maxy=getmaxy();
}

void bhnAlgo::getdata()
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

void bhnAlgo::bhnLine()
{
	int dx,dy,steps,i,dS,dE,dNE,x,y;
	dx=xEnd-xStart;
	dy=yEnd-yStart;
	yStart=yStart;
	yEnd=yEnd;
	dS=(2*dy)-dx;
	dE=2*dy;
	dNE=2*(dy-dx);
	x=xStart;
	y=yStart;
	putpixel(x,maxy-y,255);
	while(x < xEnd)
	{
		if(dS <= 0)
			dS=dS+dE;
		else
		{
			dS=dS+dNE;
			y=y+1;
		}
		x=x+1;
		putpixel(x,maxy-y,255);
	}
}

int main()
{
	bhnAlgo ob;
	ob.screenInitialize();
	ob.getdata();
	ob.bhnLine();
	getch();
	return 0;
}