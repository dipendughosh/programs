#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>

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
	//xMax=getmaxx();
	//yMax=getmaxy();

}

int main()
{
	int i;
	clrscr();
	screenInitialize();
	for(i=0;i<255;)
	{

		setcolor(i);
		line(10,20,100,200);
		outtext("i");
		i+=10;
		getch();
	}
	getch();
	cleardevice();
	closegraph();
	//getch();
	return 0;
}