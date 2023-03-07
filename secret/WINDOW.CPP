//GUI SOFTWARE(JULY 2005)(DONE)
#include<iostream.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

union REGS in,ou;
int but,xm,ym;
int mx,my;
int mtmp=0;
int cmenut=10;
int menut=0;
initmouse();
void showmouseptr();
void hidemouseptr();
void restrictmouseptr(int,int,int,int);
void getmousepos();
void *timeage();

class button
{	int x1,y1,x2,y2,up,mi,dow,dep,ptmp;
	char cap[100];
	public:
	button(int x1,int y1,int x2,int y2,int up,int mi,int dow,int dep,char *cap)
	{	this->x1=x1;
		this->y1=y1;
		this->x2=x2;
		this->y2=y2;
		strcpy(this->cap,cap);
		this->dep=dep;
		this->up=up;
		this->dow=dow;
		this->mi=mi;
		ptmp=0;
		setlinestyle(0,0,0);
		setfillstyle(1,mi);
		bar(x1,y1,x2,y2);
		setcolor(dow);
		line(x2,y1,x2+dep,y1+dep);
		line(x2+dep,y1+dep,x2+dep,y2+dep);
		line(x2+dep,y2+dep,x2+dep,y2+dep);
		line(x1-dep,y2+dep,x1,y2);
		line(x1,y2,x2,y2);
		line(x2,y2,x2,y1);
		setfillstyle(1,dow);
		floodfill(x2-dep,y2+dep-1,dow);
		setcolor(up);
		line(x1-dep,y1-dep,x2+dep,y1-dep);
		line(x2+dep,y1-dep,x2,y1);
		line(x2,y1,x1,y1);
		line(x1,y1,x1,y2);
		line(x1,y1,x1-dep,y2+dep);
		line(x1-dep,y2+dep,x1-dep,y1-dep);
		setfillstyle(1,up);
		floodfill(x1,y1-dep+1,up);
		setlinestyle(3,3,3);
		if(strcmp("CLO",cap)==0)
		{	setcolor(0);
			setlinestyle(0,0,3);
			line(625,10,630,15);
			line(625,15,630,10);
		}
		else if(strcmp("MAX",cap)==0)
		{	setcolor(0);
			setlinestyle(0,0,2);
			rectangle(611,9,618,16);
			rectangle(611,10,618,15);
		}
		else if(strcmp("MIN",cap)==0)
		{	setcolor(0);
			setlinestyle(0,0,2);
			rectangle(598,15,604,16);
		}
		else
		{	settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(0);
			outtextxy((x1+x2)/2,(y1+y2)/2,cap);
			settextjustify(LEFT_TEXT,RIGHT_TEXT);
		}
	}
	int pressed()
	{	getmousepos();
		if(xm>x1 && xm<x2 && ym>y1 && ym<y2 && but==1 &mtmp==0)
		{	if(ptmp==0)
			{	hidemouseptr();
				mtmp=1;
				press(dow,mi,up);
				ptmp=1;
				showmouseptr();
			}
			return 0;
		}
		else if(ptmp==1 && but==0)
		{	hidemouseptr();
			ptmp=0;
			press(up,mi,dow);
			showmouseptr();
			return 1;
		}
		else
			return 0;
	}
	void press(int up,int mi,int dow)
	{	setlinestyle(0,0,0);
		setfillstyle(1,mi);
		bar(x1,y1,x2,y2);
		setcolor(dow);
		line(x2,y1,x2+dep,y1-dep);
		line(x2+dep,y1-dep,x2+dep,y2+dep);
		line(x2+dep,y2+dep,x1-dep,y2+dep);
		line(x1-dep,y2+dep,x1,y2);
		line(x1,y2,x2,y2);
		line(x2,y2,x2,y1);
		setfillstyle(1,dow);
		floodfill(x2-dep,y2+dep-1,dow);
		setcolor(up);
		line(x1-dep,y1-dep,x2+dep,y1-dep);
		line(x2+dep,y1-dep,x2,y1);
		line(x2,y1,x1,y1);
		line(x1,y1,x1,y2);
		line(x1,y2,x1-dep,y2+dep);
		line(x1-dep,y2+dep,x1-dep,y1-dep);
		setfillstyle(1,up);
		floodfill(x1,y1-dep+1,up);
		setlinestyle(3,3,3);
		if(strcmp("CLO",cap)==0)
		{	setcolor(0);
			setlinestyle(0,0,3);
			line(625,10,630,15);
			line(625,15,630,10);
		}
		else if(strcmp("MAX",cap)==0)
		{	setcolor(0);
			setlinestyle(0,0,2);
			rectangle(611,9,618,16);
			rectangle(611,10,618,15);
		}
		else if(strcmp("MIX",cap)==0)
		{	setcolor(0);
			setlinestyle(0,0,2);
			rectangle(598,15,604,16);
		}
		else
		{	settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(0);
			outtextxy((x1+x2)/2,(y1+y2)/2,cap);
			settextjustify(LEFT_TEXT,RIGHT_TEXT);
		}
	}
};

button *butall;

class checkbox
{	public:
	int x,y,chk;
	char cap[100];
	checkbox(int x,int y,char *cap)
	{	chk=0;
		this->x=x;
		this->y=y;
		strcpy(this->cap,cap);
		butall=new button(x,y,x+9,y+9,8,15,7,1,"");
		setcolor(8);
		setlinestyle(0,0,0);
		rectangle(x,y,x+10,y+10);
		settextstyle(SMALL_FONT,HORIZ_DIR,4);
		settextjustify(LEFT_TEXT,CENTER_TEXT);
		setcolor(0);
		outtextxy(x+20,y+3,cap);
	}
	int pressed()
	{	getmousepos();
		if(xm>x-2 && xm<x+12 && ym>y-2 && ym<y+12 && but==1 && chk==0 && mtmp==0)
		{	hidemouseptr();
			setlinestyle(0,0,0);
			setcolor(0);
			line(x-1,y+1,x-3,y+3);
			line(x-1,y+1,x+3,y+9);
			line(x+3,y+9,x+15,y-1);
			line(x-1,y-1,x-3,y+3);
			line(x-1,y-1,x+4,y+5);
			line(x+4,y+5,x+15,y-1);
			line(x-1,y-1,x-3,y+3);
			line(x-1,y-1,x+4,y+6);
			line(x+4,y+6,x+15,y-1);
			line(x-1,y-1,x+4,y+7);
			line(x+4,y+7,x+15,y-1);
			line(x-1,y-1,x+4,y+8);
			line(x+4,y+8,x+15,y-1);
			showmouseptr();
			chk=1;
			mtmp=1;
			return 1;
		}
		else if(xm>x-2 && xm<x+12 && ym>y-2 && ym<y+12 && but==1 && chk==1 && mtmp==0)
		{	hidemouseptr();
			butall=new button(x-4,y-2,x+15,y+12,7,7,7,0,"");
			chk=0;
			mtmp=0;
			draw();
			showmouseptr();
			return 1;
		}
		else return 0;
	}
	void draw()
	{	butall=new button(x,y,x+9,y+9,8,15,7,1,"");
		setcolor(8);
		setlinestyle(0,0,0);
		rectangle(x,y,x+10,y+10);
	}
	void check()
	{	setcolor(0);
		line(x-1,y+1,x-3,y+3);
		line(x-1,y+1,x+3,y+9);
		line(x+3,y+9,x+15,y-1);
		line(x-1,y-1,x-3,y+3);
		line(x-1,y-1,x+4,y+5);
		line(x+4,y+5,x+15,y-1);
		line(x-1,y-1,x-3,y+3);
		line(x-1,y-1,x+4,y+6);
		line(x+4,y+6,x+15,y-1);
		line(x-1,y-1,x+4,y+7);
		line(x+4,y+7,x+15,y-1);
		line(x-1,y-1,x+4,y+8);
		line(x+4,y+8,x+15,y-1);
		chk=1;
	}
	void uncheck()
	{	butall=new button(x-4,y-2,x+15,y+12,7,7,7,0,"");
		chk=0;
		draw();
	}
};

class textbox
{	public:
	int x1,y1,x2,y2,fsize,font;
	char text[100];
	textbox(int x1,int y1,int x2,int y2,char text[100],int font,int fsize)
	{	this->x1=x1;
		this->y1=y1;
		this->x2=x2;
		this->y2=y2;
		this->fsize=fsize;
		this->font=font;
		strcpy(this->text,text);
		draw();
		settextstyle(font,HORIZ_DIR,fsize);
		settextjustify(LEFT_TEXT,CENTER_TEXT);
		setcolor(0);
		outtextxy(x1+5,y1+6,text);
	}
	int pressed();
	void draw()
	{	butall=new button(x1,y1,x2,y2,8,15,7,1,"");
		setcolor(8);
		setlinestyle(0,0,0);
		rectangle(x1,y1,x2+1,y2+1);
	}
	void settext(char text[100])
	{	draw();
		settextjustify(LEFT_TEXT,CENTER_TEXT);
		setcolor(0);
		outtextxy(x1+5,y1+6,text);
	}
};

class windo
{	public:
	button *butwin;
	button *buttitl;
	button *butclo;
	button *butmax;
	button *butmin;
	button *menubar;
	windo(char *T)
	{	butwin=new button(5,5,635,475,15,7,8,0,"");
		buttitl=new button(5,5,636,20,9,1,0,0,"");
		butclo=new button(622,7,633,18,15,7,8,0,"CLO");
		butmax=new button(609,7,620,18,15,7,8,0,"MAX");
		butmin=new button(596,7,607,18,15,7,8,0,"MIN");
		menubar=new button(5,40,635,41,15,7,8,0,"");
		menubar=new button(5,42,635,43,15,7,8,0,"");
		setcolor(9);
		outtextxy(16,11,T);
		setcolor(15);
		outtextxy(15,10,T);
		settextstyle(SMALL_FONT,HORIZ_DIR,4);
	}
};

int textbox::pressed()
{	if(xm>x1 && xm<x2 && ym>y1 && ym<y2 && but==1)
	{	hidemouseptr();
		char txt;
		char txtt[20];
		int xp=x1+5;
		draw();
		settextjustify(LEFT_TEXT,CENTER_TEXT);
		strcpy(text,"");
		do
		{	setcolor(0);
			line(xp,y2-4,xp+3,y2-4);
			txt=getch();
			if(xp>x2-6 && txt!=char(8))
			{	sound(150);
				delay(50);
				nosound();
			}
			else
			{	if(txt==char(8))
				{	if(strcmp(text,"")==0)
					{	sound(150);
						delay(50);
						nosound();
					}
					else
					{	text[strlen(text)-1]='\0';
						xp=xp-6;
						setfillstyle(1,15);
						bar(xp-2,y1+2,x2-2,y2-2);
						line(xp,y2-4,xp+3,y2-4);
						outtextxy(x1+5,y1+6,text);
					}
				}
				else
				{	setcolor(15);
					line(xp,y2-4,xp+3,y2-4);
					setcolor(0);
					sprintf(txtt,"%c",txt);
					settextjustify(LEFT_TEXT,CENTER_TEXT);
					strcat(text,txtt);
					outtextxy(x1+5,y1+6,text);
					xp=xp+6;
				}
			}
		}
		while(txt!=char(13));
		setcolor(15);
		line(xp,y2-4,xp+3,y2-4);
		showmouseptr();
		return 1;
	}
	else
		return 0;
}

void main()
{	//clrscr();
	int gdriver=VGA,gm=VGAHI;
	char kstroke;
	initgraph(&gdriver,&gm,"C:\\tc\\bgi");
	windo gui("GUI THROUGH C++");
	textbox n1(50,75,90,90,"0",SMALL_FONT,4);
	textbox n2(150,75,190,90,"0",SMALL_FONT,4);
	textbox ans(80,185,160,200,"0",SMALL_FONT,4);
	button butplus(25,125,50,150,15,7,8,0,"+");
	button butminus(75,125,100,150,15,7,8,0,"-");
	button butmul(125,125,150,150,15,7,8,0,"*");
	button butdiv(175,125,200,150,15,7,8,0,"/");
	textbox s1(260,75,450,90,"",SMALL_FONT,4);
	textbox s2(260,185,450,200,"",SMALL_FONT,4);
	button butrev(330,125,380,150,15,7,8,0,"Reverse");
	checkbox c1(500,75,"NEW");
	checkbox c2(500,125,"YORK");
	textbox result(500,185,600,200,"",SMALL_FONT,4);
	button butexit(550,425,600,455,15,7,8,0,"EXIT");
	butall=new button(230,50,231,250,15,7,8,0,"");
	butall=new button(475,50,476,250,15,7,8,0,"");
	butall=new button(10,260,630,261,15,7,8,0,"");
	if(initmouse()==0)
	{	cout<<"NO MOUSE....";
		closegraph();
		exit(0);
	}
	restrictmouseptr(5,5,635,475);
	showmouseptr();
	mainloop:
	while(!kbhit())
	{	getmousepos();
		if(but==0)
			mtmp=0;
		if(gui.butclo->pressed()==1)
		{	cleardevice();
			closegraph();
			exit(0);
		}
		if(butplus.pressed()==1)
		{	long int no1,no2;
			char answer[10];
			no1=atol(n1.text);
			no2=atol(n2.text);
			ltoa(no1+no2,answer,10);
			ans.settext(answer);
		}
		if(butminus.pressed()==1)
		{	long int no1,no2;
			char answer[10];
			no1=atol(n1.text);
			no2=atol(n2.text);
			ltoa(no1-no2,answer,10);
			ans.settext(answer);
		}
		if(butmul.pressed()==1)
		{	long int no1,no2;
			char answer[10];
			no1=atol(n1.text);
			no2=atol(n2.text);
			ltoa(no1*no2,answer,10);
			ans.settext(answer);
		}
		if(butdiv.pressed()==1)
		{	float no1,no2;
			char answer[10];
			no1=atol(n1.text);
			no2=atol(n2.text);
			if(no2==0)
			{	ans.settext("Error");
			}
			else
			{	ltoa(no1/no2,answer,10);
				ans.settext(answer);
			}
		}
		if(butrev.pressed()==1)
		{	s2.settext(strrev(s1.text));
		}
		if(butexit.pressed()==1)
		{	cleardevice();
			closegraph();
			exit(0);
		}
		if(c1.pressed()==1)
		{	char tmp[20]="";
			if(c1.chk==1)
			{       strcat(tmp,c1.cap);
			}
			if(c2.chk==1)
			{       strcat(tmp,c2.cap);
			}
			result.settext(tmp);
		}
		if(n1.pressed()==1)
		{
		}
		if(n2.pressed()==1)
		{
		}
		if(s2.pressed()==1)
		{
		}
	}
	char a=getch();
	if(a!=char(27))
		goto mainloop;
	closegraph();
}

initmouse()
{	in.x.ax=0;
	int86(0x33,&in,&ou);
	return(ou.x.ax);
}

void showmouseptr()
{	in.x.ax=1;
	int86(0x33,&in,&ou);
}

void hidemouseptr()
{	in.x.ax=2;
	int86(0x33,&in,&ou);
}

void restrictmouseptr(int x1,int y1,int x2,int y2)
{	in.x.ax=7;
	in.x.cx=x1;
	in.x.dx=x2;
	int86(0x33,&in,&ou);
	in.x.ax=8;
	in.x.cx=y1;
	in.x.dx=y2;
	int86(0x33,&in,&ou);
}

void getmousepos()
{	in.x.ax=3;
	int86(0x33,&in,&ou);
	but=ou.x.bx;
	xm=ou.x.cx;
	ym=ou.x.dx;
}


























































































































