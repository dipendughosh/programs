//SPIROGRAPH (MAY 2006)
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void Epitrochoids(int x,int y,double R,double r, double h);
void Hypotrochoids(int x,int y,double R,double r, double h);


void main()
{	int a,b,c,d;
	double R=10,r=120,h=80,a1;
	detectgraph(&a,&b);
	initgraph(&a,&b,"c:\\tc\\bgi");
	cleardevice();
	setcolor(3);
	rectangle(1,1,639,479);
	setfillstyle(3,10);
	bar(60,100,570,380);
	settextjustify(1,1);
	settextstyle(1,0,2);
	outtextxy(320,42,"SPIROGRAPH");
	setcolor(14);
	settextstyle(0,0,1);
	outtextxy(320,460,"PRESS ANY KEY TO CONTINUE");
	getch();
	settextjustify(0,2);
	do
	{
		cleardevice();
		setcolor(10);
		circle(320,240,100);
		line(320,240,370,325);
		setcolor(11);
		circle(470,240,50);
		line(470,240,495,285);
		setcolor(12);
		circle(270,240,50);
		line(270,240,295,285);
		setcolor(13);
		circle(570,240,5);
		line(470,240,570,240);
		setcolor(14);
		circle(200,240,5);
		line(200,240,270,240);
		outtextxy(230,242,"h");
		outtextxy(540,242,"h");
		setcolor(10);
		outtextxy(350,282,"R");
		setcolor(12);
		outtextxy(282,252,"r");
		setcolor(11);
		outtextxy(482,252,"r");
		outtextxy(10,10,"Rolling circle in Epitrochoids");
		setcolor(12);
		outtextxy(10,30,"Rolling circle in Hypotrochoids");
		setcolor(10);
		outtextxy(10,50,"R,r-Radius of circles");
		setcolor(13);
		outtextxy(10,70,"h-Distance from centre of circle");
		setcolor(15);
		do
		{	gotoxy(44,7);
			printf("                                  ");
			outtextxy(10,100,"Enter      (1)Epitrochoids or (2)Hypotrochoids      ");
			gotoxy(49,7);
			scanf(" %d",&a);
		}while(a>2 || a<1);
		outtextxy(10,132,"Enter values of R,r,h followed");
		gotoxy(25,9);
		outtextxy(10,150,"by Enter key : ");
		gotoxy(1,11);
		scanf(" %d",&b);
		R=(double)b;
		scanf(" %d",&c);
		r=(double)c;
		scanf(" %d",&d);
		h=(double)d;
		gotoxy(1,13);
		cleardevice();
		setcolor(1);
		if(a==1)
			Epitrochoids(320,240,R,r,h);
		else if(a==2)
			Hypotrochoids(320,240,R,r,h);
		setcolor(13);
		outtextxy(200,470,"Press y to plot another or Enter to Exit");
		a=getch();
	}while(a=='y' || a=='Y');
	closegraph();
	restorecrtmode();
	return;
}

void Epitrochoids(int x,int y,double R,double r, double h)
{	int a;
	double a1,t;
	double xe,ye,c;
	double R0,r0;
	c=(R+r)/r;
	circle(x,y,R);
	a1=(r<R)?r:R;
	R0=R;
	r0=r;
	for(a=a1;a>1;a--)
	{	if(fmod(r0,a)==0 && fmod(R0,a)==0)
		{	R0/=a;
			r0/=a;
		}
	}
	a1=R0*r0;
	if(a1>100)
		a1=100;
	for(t=0;t<6.28*a1;t+=.001)
	{	xe=(R+r)*cos(t)+(h*cos(c*t));
		xe=(R+r)*sin(t)+(h*sin(c*t));
		putpixel(x+xe,y+ye,2);
	}
	gotoxy(35,1);
	printf("Epitrochoids");
	gotoxy(2,2);
	printf("R=%3.3f\n r=%3.3f\n h=%3.3f\n",R,r,h);
}

void Hypotrochoids(int x,int y,double R,double r, double h)
{	int a;
	double d,a1,t;
	double xh,yh;
	double R0,r0;
	d=(R-r)/r;
	circle(x,y,R);
	a1=(r<R)?r:R;
	R0=R;
	r0=r;
	for(a=a1;a>1;a--)
	{	if(fmod(r0,a)==0 && fmod(R0,a)==0)
		{	R0/=a;
			r0/=a;
		}
	}
	a1=R0*r0;
	if(a1>100)
		a1=100;
	for(t=0;t<6.28*a1;t+=.001)
	{	xh=(R-r)*cos(t)+(h*cos(d*t));
		xh=(R-r)*sin(t)-(h*sin(d*t));
		putpixel(x+xh,y-yh,3);
	}
	gotoxy(35,1);
	printf("Hypotrochoids");
	gotoxy(2,2);
	printf("R=%3.3f\n r=%3.3f\n h=%3.3f\n",R,r,h);
}


