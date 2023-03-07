#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
union REGS in,out;

int initmouse()
{
	in.x.ax=0;
	int86(51,&in,&out);
	return out.x.ax;
}

void getmousepos(int *x,int *y,int *click)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*click=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
}

int hidemouse()
{
	in.x.ax=2;
	int86(51,&in,&out);
	return 1;
}
int showmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}
void setmousepos(int xpos,int ypos)
{
	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}
void main()
{
	int x,y,cl,a,b;
	int g=DETECT,m;
	printf("\nPRESS ANY KEY TO SHOW MOUSE POINTER");
	getch();
	clrscr();
	initgraph(&g,&m,"c:\\tc\\bgi");
	if(!initmouse())
	{
		printf("\nMOUSE SUPPORT NOT AVAILABLE");
		getch();
		exit(0);
	}
	setmousepos(0,0);
	showmouse();
	do
	{
	    getmousepos(&x,&y,&cl);
	    gotoxy(10,9);
	    printf("\n\tMouse Support Available!");
	    printf("\n\tMouse Position is: %3d,%3d",x,y);
	    printf("\n\tClick: %d",cl);
	    printf("\n\tPress any key to hide the mouse");
	}while(!kbhit());
	getch();
	hidemouse();
	printf("\n\n\tPress any key to Exit");
	getch();
}