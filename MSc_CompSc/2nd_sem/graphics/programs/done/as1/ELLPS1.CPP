/*Ellipse without axis*/
#include<iostream.h>
#include<graphics.h>
#include<conio.h>

class ellipseAlgo
{
	private:
		int xc,yc,maxx,maxy;
		float a,b;
	public:
		ellipseAlgo()
		{
			xc=0;
			yc=0;
			a=0;
			b=0;
		}
		void screenInitialize();
		void setEllipsePixel(int,int);
		void getdata();
		void ellipseDraw();
		~ellipseAlgo()
		{
		}
};

void ellipseAlgo::screenInitialize()
{
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	maxx=getmaxx();
	maxy=getmaxy();
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

}

void ellipseAlgo::ellipseDraw()
{
	float x,y,h,sa,sb,d;
	x=0;
	y=b;
	sa=a*a;
	sb=b*b;
	d=(b*b)+(a*a*(1/4-b));
	setEllipsePixel(x,y);
	while((b*b*(x+1)) < (a*a*(y-1/2)))
	{ 	if(d < 0)
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
}

void ellipseAlgo::setEllipsePixel(int x,int y)
{
    putpixel(xc+x,maxy-yc-y,255);
    putpixel(xc-x,maxy-yc-y,255);
    putpixel(xc-x,maxy-yc+y,255);
    putpixel(xc+x,maxy-yc+y,255);
}

int main()
{
	ellipseAlgo ob;
	ob.screenInitialize();
	ob.getdata();
	ob.ellipseDraw();
	getch();
	return 0;
}