#include<graphics.h>
#include<stdlib.h>

int xMax,yMax;

void menu();
void choice(int);
void screenInitialize();
void drawCoordinates(char []);

void menu()
{
	int c;
	do
	{
		printf("\t\t\t\tDifferent Shapes to Draw\n");
		printf("\t\t\t\t\t1.Line\n");
		printf("\t\t\t\t\t2.Square\n");
		printf("\t\t\t\t\t3.Rectangle\n");
		printf("\t\t\t\t\t4.Ellipse\n");
		printf("\t\t\t\t\t5.Circle\n");
		printf("\t\t\t\t\t6.Sector\n");
		printf("\t\t\t\t\t7.Polygon\n");
		printf("\t\t\t\t\t8.Exit\n");
		printf("\t\t\tEnter choice(1/2/3/4/5/6/7/8) :- ");
		scanf("%d",&c);
		choice(c);
	}while(1);
}

void choice(int c)
{
	int x1,y1,x2,y2,a,b,r,sang,eang;
	int poly[12]={350,450, 350,410, 430,400, 350,350, 300,430, 350,450 };
	switch(c)
	{	case 1:
			printf("Line\n");
			printf("Enter Co-ordinates :- \n");
			printf("Enter 1st point :- \n");
			printf("X1 = ");
			scanf("%d",&x1);
			printf("Y1 = ");
			scanf("%d",&y1);
			printf("Enter 2nd point :- \n");
			printf("X2 = ");
			scanf("%d",&x2);
			printf("Y2 = ");
			scanf("%d",&y2);
			screenInitialize();
			drawCoordinates("Line");
			line(xMax/2+x1,yMax/2-y1,xMax/2+x2,yMax/2-y2);
			break;
		case 2:
			printf("Square\n");
			printf("Enter Co-ordinates :- \n");
			printf("Enter point :- \n");
			printf("X1 = ");
			scanf("%d",&x1);
			printf("Y1 = ");
			scanf("%d",&y1);
			printf("Enter Length of sides :- ");
			scanf("%d",&a);
			screenInitialize();
			drawCoordinates("Square");
			rectangle(xMax/2+x1,yMax/2-y1,xMax/2+x1+a,yMax/2-y1+a);
			break;
		case 3:
			printf("Rectangle\n");
			printf("Enter Co-ordinates :- \n");
			printf("Enter point :- \n");
			printf("X1 = ");
			scanf("%d",&x1);
			printf("Y1 = ");
			scanf("%d",&y1);
			printf("Enter Length :- ");
			scanf("%d",&a);
			printf("Enter Breath :- ");
			scanf("%d",&b);
			screenInitialize();
			drawCoordinates("Rectangle");
			rectangle(xMax/2+x1,yMax/2-y1,xMax/2+x1+a,yMax/2-y1+b);
			break;
		case 4:
			printf("Ellipse\n");
			printf("Enter Co-ordinates of Center:- \n");
			printf("Enter point :- \n");
			printf("X1 = ");
			scanf("%d",&x1);
			printf("Y1 = ");
			scanf("%d",&y1);
			printf("Enter X-Radian :- ");
			scanf("%d",&a);
			printf("Enter Y-Radian :- ");
			scanf("%d",&b);
			screenInitialize();
			drawCoordinates("Ellipse");
			ellipse(xMax/2+x1,yMax/2-y1,0,360,a,b);
			break;
		case 5:
			printf("Circle\n");
			printf("Enter Co-ordinates of Center:- \n");
			printf("Enter point :- \n");
			printf("X1 = ");
			scanf("%d",&x1);
			printf("Y1 = ");
			scanf("%d",&y1);
			printf("Enter Radius :- ");
			scanf("%d",&r);
			screenInitialize();
			drawCoordinates("Circle");
			circle(xMax/2+x1,yMax/2-y1,r);
			break;
		case 6:
			printf("Sector\n");
			printf("Enter Co-ordinates of Center:- \n");
			printf("Enter point :- \n");
			printf("X1 = ");
			scanf("%d",&x1);
			printf("Y1 = ");
			scanf("%d",&y1);
			printf("Enter Start-Angle :- ");
			scanf("%d",&sang);
			printf("Enter End-Angle :- ");
			scanf("%d",&eang);
			printf("Enter X-Radian :- ");
			scanf("%d",&a);
			printf("Enter Y-Radian :- ");
			scanf("%d",&b);
			screenInitialize();
			drawCoordinates("Sector");
			sector(xMax/2+x1,yMax/2-y1,sang,eang,a,b);
			break;
		case 7:
			printf("Polygon\n");
			screenInitialize();
			drawCoordinates("Polygon");
			drawpoly(6, poly);
			break;
		case 8:
			printf("\nExiting");
			cleardevice();
			closegraph();
			exit(0);
		default:
			printf("\aWrong Choice-");
			delay(200);
			printf("\aEnter a valid choice\n");
			break;
	}
	getch();
	clrscr();
	cleardevice();
}

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

void drawCoordinates(char a[])
{
	char msg[80];
	setcolor(20);
	sprintf(msg,a);
	outtextxy(xMax/2-textwidth(msg)/2,0,msg);
	setcolor(255);
	line(4,yMax/2,xMax-4,yMax/2);
	line(xMax/2,textheight(msg),xMax/2,yMax-2*textheight(msg));
	outtextxy(9,yMax/2+5,"X");
	gotoxy(3,16);
	printf("'");
	outtextxy(xMax-textwidth("X")-9,yMax/2+5,"X");
	outtextxy(xMax/2,textheight(msg)+5,"Y");
	outtextxy(xMax/2,yMax-3*textheight("Y")-4,"Y");
	gotoxy(42,29);
	printf("'");
	setcolor(50);
	sprintf(msg,"Press any Key to Continue");
	outtextxy(430,470,msg);
	setcolor(255);
	rectangle(4,textheight(msg),xMax-4,yMax-2*textheight(msg)+1);
	setcolor(random(255));
}

int main()
{
	clrscr();
	menu();
	getch();
	return 0;
}