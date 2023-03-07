//digital clock header
#include<graphics.h>
#include<process.h>
#include"mouse.h"
core();
timex();
version();
mainscreen();
miniwindow(char *name);
blackbox(int x,int y);
normalbutton(int f,int d,char *k);
clickedbutton(int f,int d,char *k);
closebutton();
arrange(int a,int b,int d);

core()
{	int x,y,m,n,button;
	mainscreen();
	miniwindow("Pixel Magic");
	blackbox(160,138);
	normalbutton(190,258,"Version");
	normalbutton(345,258,"Close");
	timex();
	return(0);
}

timex()
{	struct time t;
	int a,b,c,e=0,f=0,g=0,h=0,m=25,x,y,z=0,button;
	WIN:
	gettime(&t);
	a=t.ti_hour;
	b=t.ti_min;
	c=t.ti_sec;
	z=fmod(c,2);
	switch(z)
	{	case 0:
			setfillstyle(SOLID_FILL,10);
			bar(313,145,323,155);
			bar(313,225,323,235);
		break;
		case 1:
			setfillstyle(SOLID_FILL,0);
			bar(313,145,323,155);
			bar(313,225,323,235);
		break;
	}
	if(a>12)
	{	a=a-12;
	}
	if(a==0)
	{	a=12;
	}
	else
	{	a=a;
	}
	e=a/10;
	f=fmod(a,10);
	g=b/10;
	h=fmod(b,10);
	if(m!=h)
	{	arrange(e,163,10);
		arrange(f,236,10);
		arrange(g,328,10);
		arrange(h,400,10);
		m=h;
	}
	showmouse();
	getmouse(&button,&x,&y);
	closebutton();
	if((button&1)==1)
	{	if(x>=345 && x<=445 && y>=258 && y<=278)
		{	clickedbutton(345,258,"Close");
			delay(200);
			normalbutton(345,258,"Close");
			delay(1000);
			restorecrtmode();
			exit(1);
		}
		if(x>=190 && x<=290 && y>=258 && y<=278)
		{	clickedbutton(190,258,"Version");
			delay(200);
			normalbutton(190,258,"Version");
			delay(1000);
			hidemouse();
			version();
		}
	}
	goto WIN;
}
mainscreen()
{	int x,y;
	x=getmaxx();
	y=getmaxy();
	setfillstyle(1,3);
	bar(0,0,x,y);
	setfillstyle(1,15);
	bar(0,y-30,x,y);
	setcolor(DARKGRAY);
	setlinestyle(0,1,0);
	line(0,y-28,x,y-28);
	setcolor(LIGHTGRAY);
	line(0,y-29,x,y-29);
	setcolor(4);
	settextstyle(2,0,7);
	outtextxy(200,455,"DIPENDU");
	outtextxy(200,455,"DIPENDU");
	settextstyle(0,0,1);
	return(0);
}

miniwindow(char*name)
{	int x,y,a,b,button;
	x=getmaxx();
	y=getmaxy();
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(((x/2)-170),((y/2)-136),((x/2)+170),((y/2)+70));
	setlinestyle(0,1,0);
	setcolor(DARKGRAY);
	rectangle(((x/2)-168),((y/2)-137),((x/2)+170),((y/2)+71));
	setcolor(WHITE);
	rectangle(((x/2)-170),((y/2)-136),((x/2)+168),((y/2)+70));
	setfillstyle(SOLID_FILL,BLUE);
	bar(((x/2)-170),((y/2)-111),((x/2)+167),((y/2)-133));
	setcolor(WHITE);
	setlinestyle(0,2,2);
	rectangle(((x/2)-170),((y/2)-111),((x/2)+168),((y/2)-135));
	setcolor(DARKGRAY);
	line(150,308,486,308);
	line(150,307,486,307);
	setcolor(WHITE);
	line(150,308,486,308);
	setcolor(YELLOW);
	outtextxy(160,112,name);
	setcolor(15);
	rectangle(((x/2)+148),((y/2)-130),((x/2)+163),((y/2)-116));
	setcolor(DARKGRAY);
	rectangle(((x/2)+149),((y/2)-129),((x/2)+163),((y/2)-116));
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(((x/2)+149),((y/2)-129),((x/2)+162),((y/2)-117));
	setcolor(0);
	outtextxy(((x/2)+153),((y/2)-127),"x");
	return(0);
}

closebutton()
{	int x,y,a,b,button;
	x=getmaxx();
	y=getmaxy();
	getmouse(&button,&a,&b);
	if((button&=1)==1)
	{	if((a>=(x/2)+148) && (a<=((x/2)+162) && (b>=(y/2)-129)) && (b<=(y/2)-116))
		{	delay(10000);
			setcolor(DARKGRAY);
			rectangle(((x/2)+148),((y/2)-130),((x/2)+163),((y/2)-116));
			setcolor(15);
			rectangle(((x/2)+149),((y/2)-129),((x/2)+163),((y/2)-116));
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(((x/2)+149),((y/2)-129),((x/2)+162),((y/2)-117));
			setcolor(0);
			outtextxy(((x/2)+154),((y/2)-126),"x");
			delay(15000);
			closegraph();
			restorecrtmode();
			exit(0);
		}
	}
	return(0);
}

blackbox(int x,int y)
{	setfillstyle(SOLID_FILL,BLACK);
	bar(x,y-1,x+317,y+103);
	setlinestyle(0,2,2);
	setcolor(WHITE);
	rectangle(x,y-1,x+317,y+103);
	setcolor(DARKGRAY);
	rectangle(x+1,y+1,x+319,y+105);
	setcolor(WHITE);
	rectangle(x,y-1,x+318,y+104);
	return(0);
}

normalbutton(int f,int d,char*k)
{	setcolor(15);
	rectangle(f-1,d-1,f+101,d+21);
	setcolor(DARKGRAY);
	rectangle(f-1,d-1,f+100,d+20);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(f,d,f+100,d+20);
	setcolor(BLACK);
	outtextxy(f+20,d+7,k);
	return(0);
}

clickedbutton(int f,int d,char *k)
{	setcolor(0);
	rectangle(f-1,d-1,f+101,d+21);
	setcolor(15);
	rectangle(f-1,d-1,f+100,d+20);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(f,d,f+100,d+20);
	setcolor(DARKGRAY);
	outtextxy(f+20,d+7,k);
	return(0);
}

version()
{	int button,x,y;
	miniwindow("Version");
	blackbox(160,138);
	settextstyle(3,0,6);
	setcolor(10);
	outtextxy(190,150,"Pixel Magic");
	settextstyle(0,0,1);
	outtextxy(250,112,"1.33");
	setcolor(11);
	outtextxy(170,145,"D.GHOSH");
	setcolor(14);
	outtextxy(220,220,"The simplest Digital Clock");
	setcolor(MAGENTA);
	outtextxy(232,295,"Platform : Turbo C++ 3.0");
	normalbutton(270,260,"Restore");
	showmouse();
	OUT:
	getmouse(&button,&x,&y);
	closebutton();
	if((button&=1)==1)
	{	if(x>=265 && x<=365 && y>=260 && y<=280)
		{	clickedbutton(270,260,"Restore");
			delay(1000);
			normalbutton(270,260,"Restore");
		}
		hidemouse();
		core();
	}
	goto OUT;
}

arrange(int a,int b,int d)
{	int c=139;
	switch(a)
	{	case 0:
			zero(b,c,d);
		break;
		case 1:
			one(b,c,d);
		break;
		case 2:
			two(b,c,d);
		break;
		case 3:
			three(b,c,d);
		break;
		case 4:
			four(b,c,d);
		break;
		case 5:
			five(b,c,d);
		break;
		case 6:
			six(b,c,d);
		break;
		case 7:
			seven(b,c,d);
		break;
		case 8:
			eight(b,c,d);
		break;
		case 9:
			nine(b,c,d);
		break;
		default:
			zero(b,c,d);
		break;
	}
	return(0);
}
































































