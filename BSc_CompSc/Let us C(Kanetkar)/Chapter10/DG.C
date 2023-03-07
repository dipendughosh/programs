#include<stdio.h>
#include<conio.h>

struct date
{	int dd,mm,yyyy;
};
struct d3
{	struct date d1,d2;
};
void main()
{       struct d3 d;
	clrscr();
	printf("Enter 1st Date\n");
	printf("Enter DD - ");
	scanf("%d",&d.d1.dd);
	printf("Enter MM - ");
	scanf("%d",&d.d1.mm);
	printf("Enter YYYY - ");
	scanf("%d",&d.d1.yyyy);
	printf("Enter 2nd Date\n");
	printf("Enter DD - ");
	scanf("%d",&d.d2.dd);
	printf("Enter MM - ");
	scanf("%d",&d.d2.mm);
	printf("Enter YYYY - ");
	scanf("%d",&d.d2.yyyy);
	if(d.d1.dd==d.d2.dd && d.d1.mm==d.d2.mm && d.d1.yyyy==d.d2.yyyy)
		printf("\nEqual");
	else
		printf("\nUnequal");
	getch();
}

