#include<stdio.h>
#include<conio.h>
#include<process.h>

void main()
{       long int pol,ag,pre,pr;
	char se,t;
	clrscr();
	printf("Enter Age :- ");
	scanf("%dl",&ag);
	printf("Enter Sex (M-Male,F-Female) :- ");
	scanf("%c",&se);
	printf("Enter Policy Amount :- ");
	scanf("%dl",&pol);
	printf("Enter Place of residence (V-Village,C-City) :- ");
	scanf("%c",&t);

	if(ag>=25 && ag<=35)
	{	if(t=='c' || t=='C')
		{	if(se=='m' || se=='M')
			{       if(pol>=200000)
				{	printf("\nCannot be insured");
					getch();
					exit(0);
				}
				else
				{	pre=4*pol/1000;
					pr=4;
				}
			}
			if(se=='f' || se=='F')
			{       if(pol>=100000)
				{	printf("\nCannot be insured");
					getch();
					exit(0);
				}
				else
				{	pre=3*pol/1000;
					pr=3;
				}
			}
		}
		if(t=='v' || t=='V')
		{	if(se=='m' || se=='M')
			{       if(pol>=10000)
				{	printf("\nCannot be insured");
					getch();
					exit(0);
				}
				else
				{	pre=6*pol/1000;
					pr=6;
				}
			}
		}
		printf("\nAge :- %dl\nSex :- %c\nPlace of residence :- %c\nPolicy Amount :- %dl\nPremium Rate :- %dl\nPremium Amount :- %dl",ag,t,pol,pr,pre);
	}
	else
		printf("\nCannot be insured");

	getch();
}

