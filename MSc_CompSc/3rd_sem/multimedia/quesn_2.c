#include<graphics.h>
#include<stdlib.h>

int xMax,yMax;

void screenInitialize();
void draw();

void screenInitialize()
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
}

void draw()
{
	setcolor(0);
    setfillstyle(1,12);
    bar(xMax/2-300,yMax/2-200,xMax/2+300,yMax/2+200);
    setfillstyle(1,8);
    bar(xMax/2-250,yMax/2-150,xMax/2+250,yMax/2+150);
    while(!kbhit())
    {
		putpixel(random(439)+101,random(279)+101,random(16));
		delay(300);
		setcolor(random(16));
		delay(300);
		circle(320,240,random(170));
		delay(300);
    }
    closegraph();
}

int main()
{
	screenInitialize();
	draw();
	return 0;
}