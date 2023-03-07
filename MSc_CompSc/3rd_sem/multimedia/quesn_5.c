#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

union REGS in, out;

int xMax,yMax;

void detect_mouse()
{
	in.x.ax = 0;
	int86 (51,&in,&out);
	if (out.x.ax == 0)
	{
		printf("Mouse Fail To Initialize");
		printf("Press any key to halt:");
		getch();
		exit(0);
	}
}

void restrict(int x1,int y1,int x2,int y2)
{
	in.x.ax = 7;
	in.x.cx = x1;
	in.x.dx = x2;
	int86 (51,&in,&out);
	in.x.ax = 8;
	in.x.cx = y1;
	in.x.dx = y2;
	int86 (51,&in,&out);
}

void draw()
{
	char msg[80];
	sprintf(msg,"Mouse Functions");
	outtextxy(xMax/2-textwidth(msg)/2,0,msg);
	rectangle(4,textheight(msg),xMax-4,yMax-3*textheight(msg)+1);
	restrict(4,textheight(msg),xMax-4,yMax-3*textheight(msg)+1);
}

void show_mouse()
{
	in.x.ax = 1;
	in.x.cx=xMax/2;
	in.x.dx=yMax/2;
	int86 (51,&in,&out);
}

void screen_initialize()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	outport(0x0378,0x00);
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n",grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(0);
	}
	xMax=getmaxx();
	yMax=getmaxy();
	detect_mouse();
	draw();
	show_mouse();
}

void hide_mouse()
{
    in.x.ax = 2;
    int86(51,&in,&out);
}

void get_mouse_pos(int *button,int *x,int *y)
{
	in.x.ax = 3;
	int86 (51,&in,&out);
	*button=out.x.bx;
	*x = out.x.cx;
	*y = out.x.dx;
}

void mouse_reset()
{
    in.x.ax=0;
    int86(51,&in,&out);	      
}	

void mouse_on_screen()
{
	int x,y,button;
	screen_initialize();
	show_mouse();
	while (!kbhit () )
	{
		get_mouse_pos(&button,&x,&y);
		gotoxy(30,30);
		printf("Co-ordinates --- X:- %d Y:- %d   ",x,y);
		in.x.ax = 3;
		int86 (51,&in,&out);
		if(out.x.bx == 1)
		{
			gotoxy(2,30);
			printf("Left Click Occoured ");
			hide_mouse();
		}
		else if(out.x.bx == 2)
		{
			gotoxy(2,30);
			printf("Right Click Occoured ");
			show_mouse();
		}
	}
	clrscr();
	cleardevice();
}

int main ()
{
	char c;
	do
	{
		mouse_on_screen();
		printf("\nPress E to Exit or R to Reset Mouse :");
		fflush(stdin);
		scanf("%c",&c);
		if(c == 'E' || c == 'e')
		{
			closegraph();
			cleardevice();
			exit(0);
		}
		else if(c == 'R' || c == 'r')
		{
			mouse_reset();
			continue;
		}
	}while(1);
	return 0;
}