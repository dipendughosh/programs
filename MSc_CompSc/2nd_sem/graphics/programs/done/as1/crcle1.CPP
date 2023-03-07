/*Normal circle without axis*/
#include<iostream.h>
#include<graphics.h>
#include<conio.h>

class circleAlgo
{
	private:
		int xc,yc,r,maxx,maxy;
	public:
		circleAlgo()
		{
			xc=0;
			yc=0;
			r=0;
		}
		void screenInitialize();
		void setCirclePixel(int,int);
		void getdata();
		void circleDraw();
		~circleAlgo()
		{
		}
};

void circleAlgo::screenInitialize()
{
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	maxx=getmaxx();
	maxy=getmaxy();
}

void circleAlgo::getdata()
{
	cout<<"Enter Center co-ordinates:-\nX-coordinate:- ";
	cin>>xc;
	cout<<"Y-coordinate:- ";
	cin>>yc;
	cout<<"Enter Radius:- ";
	cin>>r;
}

void circleAlgo::circleDraw()
{
	int x,y,h;
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
}

void circleAlgo::setCirclePixel(int x,int y)
{
    putpixel(xc+x,maxy-yc-y,255);
    putpixel(xc-x,maxy-yc-y,255);
    putpixel(xc-y,maxy-yc-x,255);
    putpixel(xc-y,maxy-yc+x,255);
    putpixel(xc-x,maxy-yc+y,255);
    putpixel(xc+x,maxy-yc+y,255);
    putpixel(xc+y,maxy-yc+x,255);
    putpixel(xc+y,maxy-yc-x,255);
}

int main()
{
	circleAlgo ob;
	ob.screenInitialize();
	ob.getdata();
	ob.circleDraw();
	getch();
	return 0;
}