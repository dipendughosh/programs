//digital clock header
#include<graphics.h>
void zero(int x,int y,int m);
one(int x,int y,int m);
two(int x,int y,int m);
three(int x,int y,int m);
four(int x,int y,int m);
five(int x,int y,int m);
six(int x,int y,int m);
seven(int x,int y,int m);
eight(int x,int y,int m);
nine(int x,int y,int m);
coloring(int x,int y);

void zero(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+60,y+12);
	bar(x+14,y+88,x+60,y+96);
	bar(x+4,y+6,x+12,y+49);
	bar(x+4,y+51,x+12,y+94);
	bar(x+62,y+6,x+70,y+49);
	bar(x+62,y+51,x+70,y+94);
}


one(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+32,y+6,x+40,y+49);
	bar(x+32,y+52,x+40,y+94);
	return(0);
}

two(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+60,y+12);
	bar(x+14,y+46,x+60,y+54);
	bar(x+14,y+88,x+60,y+96);
	bar(x+4,y+48,x+12,y+94);
	bar(x+62,y+6,x+70,y+49);
	return(0);
}

three(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+60,y+12);
	bar(x+14,y+46,x+60,y+54);
	bar(x+14,y+88,x+60,y+96);
	bar(x+62,y+6,x+70,y+49);
	bar(x+62,y+51,x+70,y+94);
	return(0);
}

four(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+46,x+60,y+54);
	bar(x+4,y+6,x+12,y+49);
	bar(x+62,y+6,x+70,y+49);
	bar(x+62,y+51,x+70,y+94);
	return(0);
}

five(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+65,y+12);
	bar(x+14,y+46,x+60,y+54);
	bar(x+8,y+88,x+60,y+96);
	bar(x+4,y+6,x+12,y+50);
	bar(x+62,y+48,x+70,y+94);
	return(0);
}

six(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+65,y+12);
	bar(x+14,y+46,x+60,y+54);
	bar(x+14,y+88,x+60,y+96);
	bar(x+4,y+6,x+12,y+49);
	bar(x+4,y+51,x+12,y+94);
	bar(x+62,y+48,x+70,y+94);
	return(0);
}

seven(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+9,y+4,x+60,y+12);
	bar(x+62,y+6,x+70,y+49);
	bar(x+62,y+51,x+70,y+94);
	return(0);
}

eight(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+60,y+12);
	bar(x+14,y+46,x+60,y+54);
	bar(x+14,y+88,x+60,y+96);
	bar(x+4,y+6,x+12,y+49);
	bar(x+4,y+51,x+12,y+94);
	bar(x+62,y+6,x+70,y+49);
	bar(x+62,y+51,x+70,y+94);
	return(0);
}

nine(int x,int y,int m)
{	coloring(x,y);
	setfillstyle(SOLID_FILL,m);
	bar(x+14,y+4,x+60,y+12);
	bar(x+14,y+46,x+60,y+54);
	bar(x+14,y+88,x+60,y+96);
	bar(x+4,y+6,x+12,y+49);
	bar(x+62,y+6,x+70,y+49);
	bar(x+62,y+51,x+70,y+94);
	return(0);
}

coloring(int x,int y)
{	setfillstyle(SOLID_FILL,BLACK);
	bar(x,y,x+74,y+100);
	return(0);
}