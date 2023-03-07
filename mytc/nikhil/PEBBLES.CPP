#include <conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include <iostream.h>

int *bowl(int j);
void animation(int n,int r,int *p);
void pick(int p,int q,int a);

void main()
{   clrscr();
	int driver,mode,*p,k,m,n=0,r=101;
	char c,d='n';
	do
	{	driver=DETECT;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(0,440,"Press Esc key to exit . ");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(15);
	randomize();
	while(r%4 == 1)
			r=33+random(12);
	outtextxy(50,1,"Pebbles.");
	p=bowl(r);
	pick(185,1,r);
	outtextxy(20,100,"Your pick ");
	outtextxy(0,200,"Computer pick ");
	while(r>1)
		{
		while(c!='1' && c!='2' && c!='3')
			{c=getche();
			switch(c)
				{
				case '1':n=1;break;
				case '2':n=2;break;
				case '3':n=3;break;
				case'\x1B':closegraph(); exit(0);
				default:outtextxy(0,350,"Pick 1,2 or 3");
				}
	}
	setcolor(0);
	outtextxy(0,350,"Pick 1,2 or 3");
	(n<r-n|r-n>0)?pick(195,100,n): exit(0);
	animation(n,r,p);
	r-=n;
	pick(195,100,'--');
	c='n';
	if(r==1)
	   {
	   settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	   outtextxy(350,40,"YOU WON");
	   settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
	   outtextxy(350,40,"DO U PLAY AGAIN ? ");
	   outtextxy(350,40,"PRESS 'Y'Y FOR YES . ");
	   d=getch();
	   }
	else
	   {
	   k=r%4;
	   switch(k)
		{
		case 0:m=3;break;
		case 2:m=1;break;
		case 3:m=2;break;
		default:m=1+random(3);
		}
	   delay(1000);
	   pick(255,200,m);
	   animation(m,r,p);
	   r-=m;
	   pick(185,1,r);
	   outtextxy(255,200,"--");
	   if(r==1)
		{
		settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
		outtextxy(300,40,"Computer won . ");
		settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
		outtextxy(350,120,"DO U PLAY AGAIN ? ");
		outtextxy(350,160,"PRESS 'Y' FOR YES . ");
		getche();
		}
	   }
	}
	closegraph();
	}while(d=='y');
	getche();
}


int *bowl(int j)
	{
	int size,i,k,t,u;
	arc(470,300,180,360,150);
	ellipse(470,293,0,36,150,50);
	setcolor(4);
	for(i=438,t=441,u=502;i>383;i-=18,t-=30,u+=20)
		{
		if(t==351) t+=20;
		if(u==522) u+=20;
		if(u==582) u-=10;
		for(k=t;k<u;k=k+20)
			{
			circle(k,i,8);
			floodfill(k,i,4);
			}
		}
	for(i=32,k=361;i<j;i++,k=k+20)
		{
		circle(k,366,8);
		floodfill(k,366,4);
		}
	int ulx=353,uly=358,lrx=369,lry=374;
	size=imagesize(ulx,uly,lrx,lry);
	int *pebble=new int[size];
	getimage(ulx,uly,lrx,lry,pebble);
	return pebble;
	}


void animation(int s,int t,int *pebble)
	{
	long a,j,k,m,x,y,u;
	for(u=1;u<=s;u++)
		{
		if(t>32)
			k=358;
		if(t>21&&t<33)
			k=376;
		if(t>11&&t<22)
			k=394;
		if(t>4&&t<12)
			k=412;
	if(t>5)
		k=430;
		switch(k)
			{
			case 358:j=(t-33)*20+353;break;
			case 376:j=(t-22)*20+363;break;
			case 394:j=(t-12)*20+373;break;
			case 412:j=(t-5)*20+403;break;
			case 430:j=(t-1)*20+433;break;
			}
		a=(j-700)*(j-700)+(k-300)*(k-300);
		m=k;
		putimage(j,k,pebble,XOR_PUT);
		for(x=j;x<640;x++)
			{
			y=sqrt(a-(x-700)*(x-700))+300;
			y=m-2*(y-m);
			putimage(x,y,pebble,XOR_PUT);
			}
		t--;
		}
	}



void pick(int u,int v,int w)
	{
	int d,s,p;
	setcolor(15);
	p=(w>9)?2:1;
	(u==185)?outtextxy(u,v," "):outtextxy(u,v," ");
	setcolor(0);
	outtextxy(u+7,v+2,ecvt(w,p,&d,&s));
	setcolor(15);
	}