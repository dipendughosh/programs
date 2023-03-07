//COMPUTERISED ELECTRICAL EQUIPMENT CONTROL(JULY 2005)(DONE)
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>

void main()
{	clrscr();
	void tone(void);
	int p=0x0378;
	char ex[23]={"Created by V.MARIYAPPAN"};
	int j;
	char ex1[34]={"For Further details & improvements"};
	int k;
	char ex2[40]={"Contact :           E-Mail-"};
	int l;
	char ex3[23]={"Programing in C++"};
	int m;
	int u[10];
	int i;
	static a,b,c,d,e,f,g,h;
	char no;
	clrscr();
	textcolor(15);
	gotoxy(20,6);
	cprintf("COMPUTERISED ELECTRCAL EQUIPMENT CONTROL.");
	textcolor(11);
	gotoxy(20,7);
	cprintf("-----------------------------------------");
	textcolor(11);
	gotoxy(10,10);
	cprintf("EQUIPMENT NO: 1  2  3  4  5  6  7  8");
	textcolor(11);
	gotoxy(10,12);
	cprintf("STATUS:    %d  %d  %d  %d  %d  %d  %d  %d",a,b,c,d,e,f,g,h);
	textcolor(10);
	gotoxy(9,16);
	cprintf("FOR 'ON' AND 'OFF' AN EQUIPMENT PRESS CORRESPONDING EQUIP.NO.");
	textcolor(11);
	gotoxy(28,18);
	cprintf("STATUS 0=OFF   STATUS 1=ON");
	textcolor(12);
	gotoxy(32,20);
	cprintf("FOR EXIT PRESS 'E'\n");
	no=getch();
	switch(no)
	{	case '1':
			a=!a;
			tone();
			outportb(p,1);
			delay(500);
			outportb(p,0);
			break;
		case '2':
			b=!b;
			tone();
			outportb(p,2);
			delay(500);
			outportb(p,0);
			break;
		case '3':
			c=!c;
			tone();
			outportb(p,4);
			delay(500);
			outportb(p,0);
			break;
		case '4':
			d=!d;
			tone();
			outportb(p,8);
			delay(500);
			outportb(p,0);
			break;
		case '5':
			e=!e;
			tone();
			outportb(p,16);
			delay(500);
			outportb(p,0);
			break;
		case '6':
			f=!f;
			tone();
			outportb(p,32);
			delay(500);
			outportb(p,0);
			break;
		case '7':
			g=!g;
			tone();
			outportb(p,64);
			delay(500);
			outportb(p,0);
			break;
		case '8':
			h=!h;
			tone();
			outportb(p,128);
			delay(500);
			outportb(p,0);
			break;
		case 'e':
			if((a|b|c|d|e|f|g|h)==1)
			{	clrscr();
				textcolor(10);
				gotoxy(20,12);
				cprintf("PLEASE SHUT DOWN ALL THE EQUIPMENTS");
				sound(200);
				delay(500);
				nosound();
				delay(3000);
				break;
			}
			else
			{	clrscr();
				for(j=0;j<23;j++)
				{	textcolor(10);
					gotoxy(20+j,12);
					cprintf("%c",ex[j]);
					sound(3000+j);
					delay(30);
					nosound();
				}
				for(m=0;m<23;m++)
				{	textcolor(10);
					gotoxy(20+m,13);
					cprintf("%c",ex3[m]);
					sound(1800+m);
					delay(30);
					nosound();
				}
				for(k=0;k<23;k++)
				{	textcolor(10);
					gotoxy(20+k,14);
					cprintf("%c",ex1[k]);
					sound(2000+k);
					delay(30);
					nosound();
				}
				for(l=0;l<23;l++)
				{	textcolor(10);
					gotoxy(20+l,15);
					cprintf("%c",ex2[l]);
					sound(2500+l);
					delay(30);
					nosound();
				}
				printf("\n\n\n\nPress any key");
				getch();
				outport(p,0);
				exit(0);
			}
		case 'E':
			if((a|b|c|d|e|f|g|h)==1)
			{	clrscr();
				textcolor(10);
				gotoxy(20,12);
				cprintf("PLEASE SHUT DOWN ALL THE EQUIPMENTS");
				sound(200);
				delay(500);
				nosound();
				delay(3000);
				break;
			}
			else
			{	clrscr();
				for(j=0;j<23;j++)
				{	textcolor(10);
					gotoxy(20+j,12);
					cprintf("%c",ex[j]);
					sound(3000+j);
					delay(30);
					nosound();
				}
				for(m=0;m<23;m++)
				{	textcolor(10);
					gotoxy(20+m,13);
					cprintf("%c",ex3[m]);
					sound(1800+m);
					delay(30);
					nosound();
				}
				for(k=0;k<23;k++)
				{	textcolor(10);
					gotoxy(20+k,14);
					cprintf("%c",ex1[k]);
					sound(2000+k);
					delay(30);
					nosound();
				}
				for(l=0;l<23;l++)
				{	textcolor(10);
					gotoxy(20+l,15);
					cprintf("%c",ex2[l]);
					sound(2500+l);
					delay(30);
					nosound();
				}
				printf("\n\n\n\nPress any key");
				getch();
				outport(p,0);
				exit(0);
			}
		default:
			clrscr();
			sound(500);
			delay(100);
			nosound();
			textcolor(11);
			gotoxy(30,12);
			cprintf("INVALID KEY PRESSED");
			textcolor(11);
			gotoxy(33,14);
			cprintf("WAIT 2 SECONDS");
			delay(3000);
			break;
	}
	main();
}

void tone(void)
{	sound(1000);
	delay(100);
	nosound();
}































































































































