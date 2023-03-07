//digital clock (APRIL 2006)
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include"segment.h"
#include"visual.h"


void main()
{	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	if(initmouse()==0)
	{	mainscreen();
		miniwindow("Pixel Magic");
		setfillstyle(SOLID_FILL,DARKGRAY);
		fillellipse(183,163,20,20);
		setcolor(15);
		setfillstyle(SOLID_FILL,RED);
		fillellipse(180,160,20,20);
		settextstyle(3,0,7);
		setcolor(15);
		outtextxy(168,117,"x");
		settextstyle(0,0,1);
		sound(2000);
		delay(400);
		nosound();
		setcolor(RED);
		outtextxy(240,150,"ERROR");
		setcolor(0);
		outtextxy(240,170,"The problem may be due to:");
		outtextxy(240,200,"Mouse is NOT Installed OR");
		outtextxy(240,215,"Mouse Druver Corrupted OR");
		outtextxy(240,230,"Unsupported Mouse");
		setcolor(BLUE);
		outtextxy(240,260,"PRESS ANY KEY TO EXIT");
		getch();
		closegraph();
		restorecrtmode();
	}
	else
	{	core();
	}
}

