#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>


class algo
{
	private:
		int xMax,yMax;
	public:
		algo()
		{
			FILE *ft;
			ft=fopen("f:\\test.txt","w");
			fclose(ft);
		}
		void screenInitialize();
		void fillscrn();
		~algo()
		{
			closegraph();
		}
};

void algo::screenInitialize()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	outport(0x0378,0x00);
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		cout<<"Graphics error: %s\n"<<grapherrormsg(errorcode);
		cout<<"Press any key to halt:";
		getch();
		exit(0);
	}
	xMax=getmaxx();
	yMax=getmaxy();
}


void algo::fillscrn()
{
	int x,y,i=0;
	FILE *ft;
	ft=fopen("f:\\test.txt","a");
	if(ft==NULL)
		;
	delay(2000);
	while(i<=10)
	{
		for(y=0;y<=yMax;y++)
		{
			for(x=0;x<=xMax;x++)
			{
				fprintf(ft,"%d %d \n",x,y);
				putpixel(x,y,i+1);
				//delay(1);
			}
			delay(1);
		}
		delay(100);
		cleardevice();
		for(x=0;x<=xMax;x++)
		{
			for(y=0;y<=yMax;y++)
			{
				fprintf(ft,"%d %d \n",x,y);
				putpixel(x,y,i+2);
				//delay(1);
			}
			delay(1);
		}
		delay(100);
		cleardevice();
		for(y=yMax;y>=0;y--)

		{
			for(x=0;x<=xMax;x++)
			{
				fprintf(ft,"%d %d \n",x,y);
				putpixel(x,y,i+3);
				//delay(1);
			}
			delay(1);
		}
		delay(100);
		cleardevice();
		for(x=xMax;x>=0;x--)
		{
			for(y=0;y<=yMax;y++)
			{
				fprintf(ft,"%d %d \n",x,y);
				putpixel(x,y,i+4);
				//delay(1);
			}
			delay(1);
		}
		delay(100);
		cleardevice();
		i++;
	}
	fclose(ft);
}

int main()
{
	algo ob;
	ob.screenInitialize();
	ob.fillscrn();
	return 0;
}

