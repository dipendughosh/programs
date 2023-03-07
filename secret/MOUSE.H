//digital clock header
#include<dos.h>

union REGS i,o;
initmouse();
showmouse();
hidemouse();
getmouse(int*button,int*x,int*y);
moveonly(int x1,int y1,int x2,int y);

initmouse()
{	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

showmouse()
{	i.x.ax=1;
	int86(0x33,&i,&o);
	return(0);
}

hidemouse()
{	i.x.ax=2;
	int86(0x33,&i,&o);
	return(0);
}

getmouse(int *button,int *x,int *y)
{	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
	return(0);
}

int moveonly(int x1,int y1,int x2,int y2)
{	i.x.ax=7;
	i.x.cx=x1;
	i.x.dx=x2;
	int86(0x33,&i,&o);
	i.x.ax=8;
	i.x.cx=y1;
	i.x.dx=y2;
	int86(0x33,&i,&o);
	return(0);
}
