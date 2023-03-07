//My prgrm
#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

union REGS in, out;
//struct time t1,t2;

class mouse
{
	private:
		int xMax,yMax;
	public:
		mouse()
		{
			screenInitialize();
		}		
		void screenInitialize();
		void drawCoordinates();
		void restrict(int,int,int,int);
		void detect_mouse();
		void showmouse();
		void getmousepos(int *,int *,int *);
		void timeint();
		~mouse()
		{
			closegraph();
		}
};

void mouse::screenInitialize()
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
	cleardevice();
	xMax=getmaxx();
	yMax=getmaxy();
	detect_mouse();
	drawCoordinates();
	showmouse();

}

void mouse::drawCoordinates()
{
	char msg[80];
	sprintf(msg,"Title");
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
	restrict(4,textheight(msg),xMax-4,yMax-2*textheight(msg)+1);	
}

void mouse::restrict(int x1,int y1,int x2,int y2)
{
	in.x.ax = 7;
	in.x.cx = x1;
	in.x.dx = x2;
	int86 (0X33,&in,&out);
	in.x.ax = 8;
	in.x.cx = y1;
	in.x.dx = y2;
	int86 (0X33,&in,&out);
}

void mouse::detect_mouse()
{
	in.x.ax = 0;
	int86 (0X33,&in,&out);
	if (out.x.ax == 0)
	{
		cout<<"Mouse Fail To Initialize";
		cout<<"Press any key to halt:";
		getch();
		exit(0);
	}
}

void mouse::showmouse()
{
	in.x.ax = 1;
	int86 (0X33,&in,&out);
}

void mouse::getmousepos(int *button,int *x,int *y)
{
	in.x.ax = 3;
	int86 (0X33,&in,&out);
	*button=out.x.bx;
	*x = out.x.cx;
	*y = out.x.dx;
}

void mouse::timeint()
{
	int min,sec;
	long int ssec;
	if(t1.ti_hund>t2.ti_hund)
	{
		ssec=100+t1.ti_hund-t2.ti_hund;
		(t1.ti_sec)=(t1.ti_sec)-1;
	}
	else
		ssec=t2.ti_hund-t1.ti_hund;
	if(t1.ti_sec>t2.ti_sec)
	{
		sec=60+t1.ti_sec-t2.ti_sec;
		(t1.ti_min)=(t1.ti_min)-1;
	}
	else
		sec=t2.ti_sec-t1.ti_sec;
	min=t2.ti_min-t1.ti_min;
	gotoxy(10,30);
	printf("%d min :%d sec :%ld hsec",min,sec,ssec);
	rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
}


int main ()
{
	mouse ob;
	int x,y,button,xMax,yMax;
	xMax=getmaxx();
	yMax=getmaxy();
	/*gettime(&t1);
	delay(200);
	gettime(&t2);
	ob.timeint();
	getch();*/
	while (!kbhit () )
	{
		ob.getmousepos(&button,&x,&y);
		gotoxy(35,30);
		cout<<"X - "<<x<<" Y - "<<y<<"  ";
		rectangle(4,textheight("A"),xMax-4,yMax-2*textheight("A")+1);
	}
	getch();
	return 0;
}