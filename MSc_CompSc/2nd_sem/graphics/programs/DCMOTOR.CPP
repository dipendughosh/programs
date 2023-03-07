//DC MOTOR CONTROLLER(SEPTEMBER 2005)ANTICLOCKWISE(DONE)
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>
#include<dos.h>

union REGS i,o;

int main()
{	//clrscr();
	int driver,mode,x,y,but;
	driver=DETECT;
       //	int initmouse();
	int resmptr(int p,int q,int r,int s);
	int showmptr();
	int getmpos(int *t,int *u,int *v);
	int text(int e,int f);
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	//outport(0x0378,0x00);
	/*if(initmouse()==0)
	{	closegraph();
		restorecrtmode();
		cout<<"\nmouse driver not loaded";
		exit(1);
	} */
	int d=0;
	gotoxy(14,11);
	cout<<d;
	showmptr();
	resmptr(30,30,635,460);
	setcolor(LIGHTRED);
	rectangle(30,30,635,460);
	rectangle(70,155,160,180);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(180,130,320,170);
	floodfill(202,132,LIGHTRED);
	rectangle(180,240,320,280);
	floodfill(202,242,LIGHTRED);
	rectangle(350,130,498,170);
	floodfill(352,132,LIGHTRED);
	rectangle(350,240,490,280);
	floodfill(352,242,LIGHTRED);
	line(250,220,420,220);
	line(335,220,335,210);
	line(250,220,250,240);
	line(420,220,420,240);
	text(8,13);
	outtextxy(188,45,"-:D C M O T O R:-");
	text(8,13);
	outtextxy(195,75,"-:Control Panal:-");
	text(6,4);
	outtextxy(85,300,"Instructions:-");
	outtextxy(210,140,"Clockwise:-");
	outtextxy(360,140,"Anticlockwise:-");
	outtextxy(210,250,"Increase:-");
	outtextxy(380,250,"Decrease:-");
	setcolor(10);
	outtextxy(310,185,"Speed");
	outtextxy(60,130,"Speed Factor");
	text(5,10);
	outtextxy(100,320,"#Press & hold 'Clockwise' button to rotate DC motor clockwise.");
	outtextxy(100,340,"#Press & hold 'Anticlockwise' button to rotate DC motor anticlockwise.");
	outtextxy(100,360,"#Press 'increase'/'decrease' button to change the speed");
	setcolor(13);
	outtextxy(200,440,"Press Esc key to exit program");
	setcolor(YELLOW);
	while(!kbhit())
	{	getmpos(&but,&x,&y);
		if(x>=200 && x<=300 && y>=130 && y<=170 && (but & 1)==1)
		{	text(6,13);
			outtextxy(210,140,"Clockwise");
			do
			{	getmpos(&but,&x,&y);
				outport(0x0378,0x0c);
				sound(750);
				delay(25+d);
				nosound();
				outport(0x0378,0x00);
				delay(25-d);
			}while((but & 1)==1);
			text(6,4);
			outtextxy(210,140,"Clockwise");
		}
		else if(x>=350 && x<=490 && y>=130 && y<=170 && (but & 1)==1)
		{	text(6,13);
			outtextxy(360,140,"Anticlockwise");
			do
			{	getmpos(&but,&x,&y);
				outport(0x0378,0x03);
				sound(750);
				delay(250+d);
				outport(0x0378,0x00);
				delay(25-d);
				nosound();
			}while((but & 1)==1);
			text(6,4);
			outtextxy(360,140,"Anticlockwise");
		}
		else if(x>=180 && x<=320 && y>=240 && y<=280 && (but & 1)==1)
		{       gotoxy(10,11);
			cout<<"      ";
			text(6,2);
			outtextxy(210,250,"Increase");
			sound(1000);
			delay(200);
			nosound();
			if(d<25)
			{       gotoxy(10,11);
				cout<<"          ";
				d++;
				gotoxy(14,11);
				cout<<d;
			}
			else
			{	gotoxy(10,11);
				cout<<" Max Speed";
			}
			text(6,4);
			outtextxy(210,250,"Increase");
		}
		else if(x>=350 && x<=490 && y>=240 && y<=280 && (but & 1)==1)
		{       gotoxy(10,11);
			cout<<"      ";
			text(6,2);
			outtextxy(380,250,"Decrease");
			sound(1000);
			delay(200);
			nosound();
			if(d>(-25))
			{       gotoxy(10,11);
				cout<<"          ";
				d--;
				gotoxy(14,11);
				cout<<d;
			}
			else
			{	gotoxy(10,11);
				cout<<" Min Speed";
			}
			text(6,4);
			outtextxy(380,250,"Decrease");
		}
	}
	closegraph();
	return 0;
}

int getmpos(int *but,int *x,int *y)
{	i.x.ax=3;
	int86(0x33,&i,&o);
	*but=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}

int initmouse()
{	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

int showmptr()
{	i.x.ax=1;
	int86(0x33,&i,&o);
}

int resmptr(int a,int b,int c,int d)
{	i.x.ax=7;
	i.x.cx=a;
	i.x.dx=c;
	int86(0x33,&i,&o);
	i.x.ax=8;
	i.x.cx=b;
	i.x.dx=d;
	int86(0x33,&i,&o);
}

int text(int e, int f)
{	setcolor(f);
	settextstyle(SMALL_FONT,HORIZ_DIR,e);
}





























































































































