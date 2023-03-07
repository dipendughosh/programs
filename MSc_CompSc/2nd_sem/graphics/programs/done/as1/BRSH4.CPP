/*Breshnham with co-ordinates and width*/
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<dos.h>

class bhnAlgo
{
	private:
		int xMax,yMax;
		int xStart,xEnd,yStart,yEnd,width;
	public:
		bhnAlgo()
		{
		}
		void execute();
		void screenInitialize();
		void drawCoordinates();
		void getdata();
		void bhnLine(int,int,int,int,int,int);
		void thickness();
		~bhnAlgo()
		{
			closegraph();
		}
};

void bhnAlgo::execute()
{
	float m;
	screenInitialize();
	getdata();
	cleardevice();
	drawCoordinates();
	if(xStart==xEnd)
		bhnLine(yStart,xStart,yEnd,xEnd,0,1);
	else
	{
		m=(float)(yEnd-yStart)/(xEnd-xStart);
		if(abs(m)<1.0 && m >= 0.0) //1st qua
			bhnLine(xStart,yStart,xEnd,yEnd,0,0);
		else if(abs(m) >=1.0 && m > 0.0) //2nd qua
		      bhnLine(yStart,xStart,yEnd,xEnd,0,1);
		else if(abs(m)<1.0 && m <0.0) //8th qua
		      bhnLine(xStart,yStart,xEnd,yEnd,1,0);
		else if(abs(m)>=1.0 &&  m<=0.0)//7th
		      bhnLine(yStart,xStart,yEnd,xEnd,1,1);
	}
	getch();
}

void bhnAlgo::screenInitialize()
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

void bhnAlgo::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Bresenham Algorithm");
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

void bhnAlgo::getdata()
{
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
		cout<<"Enter Width:- ";
		cin>>width;
		if(xStart == xEnd && yStart == yEnd)
			cout<<"Starting and Ending vertices are same\n\nRe-Enter";
		else
			break;
	}while(1);
	xStart=4*xStart;
	yStart=4*yStart;
	xEnd=4*xEnd;
	yEnd=4*yEnd;
	width=4*width;
}

void bhnAlgo::bhnLine(int xS,int yS,int xE,int yE,int f,int c)
{
	int dx,dy,steps,i,dS,dE,dNE,x,y,xF;
	int xt,yt;
	struct time t1,t2;
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
	thickness();
	gettime(&t2);
	gotoxy(10,30);
	printf("%2d:%02d:%02d.%09ld",t2.ti_hour-t1.ti_hour, t2.ti_min-t1.ti_min, t2.ti_sec-t1.ti_sec, t2.ti_hund-t1.ti_hund);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}

void bhnAlgo::thickness()
{
	int x1=xStart,x2=xEnd,y1=yStart,y2=yEnd,i;
	float m=(float)(yEnd-yStart)/(xEnd-xStart);
	setcolor(8);
	if((xEnd-xStart)==0)
	{
		for(i=0;i<=width;i++)
		{
			line(xMax/2+(x1+i),yMax/2-(y1),xMax/2+(x2+i),yMax/2-(y2));
			line(xMax/2+(x1-i),yMax/2-(y1),xMax/2+(x2-i),yMax/2-(y2));
		}
	}
	else if((yEnd-yStart)==0)
    {
		for(i=0;i<=width;i++)
		{
			line(xMax/2+(x1),yMax/2-(y1-i),xMax/2+(x2),yMax/2-(y2-i));
			line(xMax/2+(x1),yMax/2-(y1+i),xMax/2+(x2),yMax/2-(y2+i));
		}
    }
    else
    {
		if(m>0)
		{
			line(xMax/2+(x1-width),yMax/2-(y1+width),xMax/2+(x1+width),yMax/2-(y1-width));
			line(xMax/2+(x2+width),yMax/2-(y2-width),xMax/2+(x2-width),yMax/2-(y2+width));
			for(i=0;i<=width;i++)
			{
				line(xMax/2+(x1+i),yMax/2-(y1-i),xMax/2+(x2+i),yMax/2-(y2-i));
				line(xMax/2+(x1-i),yMax/2-(y1+i),xMax/2+(x2-i),yMax/2-(y2+i));
			}
		}
		else
		{
			line(xMax/2+(x1-width),yMax/2-(y1-width),xMax/2+(x1+width),yMax/2-(y1+width));
			line(xMax/2+(x2+width),yMax/2-(y2+width),xMax/2+(x2-width),yMax/2-(y2-width));
			for(i=0;i<=width;i++)
			{
				line(xMax/2+(x1-i),yMax/2-(y1-i),xMax/2+(x2-i),yMax/2-(y2-i));
				line(xMax/2+(x1+i),yMax/2-(y1+i),xMax/2+(x2+i),yMax/2-(y2+i));
			}
		}
	}
}

int main()
{
	bhnAlgo ob;
	ob.execute();
	return 0;
}