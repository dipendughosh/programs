//STEPPER MOTOR CONTROLLR(OCTOBER 2005)(DONE)
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

union REGS i,o;

void main()
{	int driver,mode,x,y,but;
	driver = DETECT;
	int initmouse();
	int resmptr(int p,int q,int r,int s);
	int showmptr();
	int getmpos(int *t,int *u,int *v);
	int text(int e,int f);
	float s1,d=50,s=60;
	float r=1,n=5;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	if(initmouse()==0)
	{	closegraph();
		restorecrtmode();
		cout<<"\nMouse driver is not loaded";
		exit(1);
	}
	gotoxy(14,10);
	cout<<s;
	gotoxy(71,10);
	cout<<r;
	showmptr();
	resmptr(30,30,635,460);
	setcolor(LIGHTRED);
	rectangle(30,30,635,460);
	rectangle(70,135,160,165);
	rectangle(520,135,610,165);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(180,130,320,170);
	floodfill(202,132,LIGHTRED);
	rectangle(80,240,170,270);
	floodfill(82,242,LIGHTRED);
	rectangle(350,130,490,170);
	floodfill(352,132,LIGHTRED);
	rectangle(200,240,290,270);
	floodfill(202,242,LIGHTRED);
	rectangle(380,240,470,270);
	floodfill(382,242,LIGHTRED);
	rectangle(500,240,590,270);
	floodfill(502,242,LIGHTRED);
	line(125,220,245,220);
	line(425,220,545,220);
	line(185,220,185,210);
	line(485,220,485,210);
	line(245,220,245,240);
	line(545,220,545,240);
	line(125,220,125,240);
	line(425,220,425,240);
	text(8,13);
	outtextxy(188,45,"-:STEPPER MOTOR:-");
	text(8,13);
	outtextxy(195,75,"-:Control Panal:-");
	text(6,4);
	outtextxy(60,340,"Instructions:-");
	outtextxy(210,140,"Clockwise");
	outtextxy(360,140,"Anticlockwise");
	outtextxy(90,245,"Increase");
	outtextxy(210,245,"Decrease");
	outtextxy(390,245,"Increase");
	outtextxy(510,245,"Decrease");
	setcolor(10);
	outtextxy(175,190,"RPM");
	outtextxy(445,190,"Rotaions");
	outtextxy(60,110,"Current RPM");
	outtextxy(490,110,"No. of Rotations");
	text(5,10);
	outtextxy(70,360,"#Press 'Clockwise' button to rotate Stepper Motor clockwise.");
	outtextxy(70,380,"#Press 'Anticlockwise' button to rotate Stepper Motor anticlockwise.");
	outtextxy(70,400,"#Press 'increase'/'decrease' button to change the RPM");
	outtextxy(70,420,"#Press 'increase'/'decrease' button to change the No. of Rotations");
	setcolor(13);
	outtextxy(200,440,"Press Esc key to exit program");
	setcolor(YELLOW);
	while(!kbhit())
	{	getmpos(&but,&x,&y);
		if(x>=200 && x<=300 && y>=130 && y<=170 && (but & 1)==1)
		{	text(6,13);
			outtextxy(210,140,"Clockwise");
			for(int i=1;i<=n;i++)
			{	sound(500);
				outport(0x0378,0xcc);
				delay(d);
				outport(0x0378,0x3c);
				delay(d);
				outport(0x0378,0x33);
				delay(d);
				outport(0x0378,0xc3);
				delay(d);
				nosound();
			}
			text(6,4);
			outtextxy(210,140,"Clockwise");
		}
		else if(x>=350 && x<=490 && y>=130 && y<=170 && (but & 1)==1)
		{	text(6,13);
			outtextxy(360,140,"Anticlockwise");
			for(int i=1;i<=n;i++)
			{	sound(750);
				outport(0x0378,0xcc);
				delay(d);
				outport(0x0378,0xc3);
				delay(d);
				outport(0x0378,0x33);
				delay(d);
				outport(0x0378,0x3c);
				delay(d);
				nosound();
			}
			text(6,4);
			outtextxy(360,140,"Anticlockwise");
		}
		else if(x>=80 && x<=170 && y>=240 && y<=270 && (but & 1) == 1)
		{       gotoxy(10,10);
			cout<<"      ";
			text(6,2);
			outtextxy(90,245,"Increase");
			sound(1000);
			delay(200);
			nosound();
			if(s>=10)
				s=s+10;
			else
				s++;
			s1=s/60;
			d=50/s1;
			gotoxy(14,10);
			cout<<s;
			text(6,4);
			outtextxy(90,245,"Increase");
		}
		else if(x>=200 && x<=290 && y>=240 && y<=270 && ( but & 1 ) == 1)
		{	gotoxy(10,10);
			cout<<"      ";
			text(6,2);
			outtextxy(210,245,"Decrease");
			sound(1000);
			delay(200);
			nosound();
			if(s>10)
			{	s=s-10;
				gotoxy(14,10);
				cout<<s;
			}
			else
			{	if(s>1)
				{	s--;
					gotoxy(14,10);
					cout<<s;
				}
				else
				{	gotoxy(11,10);
					cout<<"minlimit";
				}
			}
			s1=s/60;
			d=50/s1;
			text(6,4);
			outtextxy(210,245,"Decrease");
		}
		else if(x>=380 && x<=470 && y>=240 && y<=270 && (but & 1) == 1)
		{       gotoxy(67,10);
			cout<<"      ";
			text(6,2);
			outtextxy(390,245,"Increase");
			sound(1000);
			delay(200);
			nosound();
			if(r<1)
				r=r*2;
			else
				r++;
			gotoxy(71,10);
			cout<<r;
			n=r*5;
			text(6,4);
			outtextxy(390,245,"Increase");
		}
		else if(x>=500 && x<=590 && y>=240 && y<=270 && ( but & 1 ) == 1)
		{	gotoxy(67,10);
			cout<<"      ";
			text(6,2);
			outtextxy(510,245,"Decrease");
			sound(1000);
			delay(200);
			nosound();
			if(r>1)
			{	r--;
				gotoxy(71,10);
				cout<<r;
			}
			else
			{	if(r>0.25)
				{	r=r/2;
					gotoxy(71,10);
					cout<<r;
				}
				else
				{	gotoxy(67,10);
					cout<<"Ooppps....";
				}
			}
			n=r*5;
			text(6,4);
			outtextxy(510,245,"Decrease");
		}
	}
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













































































