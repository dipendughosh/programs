#include<stdio.h>
#include<conio.h>

void main()
{
	float hr;
	clrscr();
	printf("Enter hour of work:- ");
	scanf("%f",&hr);
	if(hr>=2 && hr<3)
		printf("\nHighly Efficient");
	else if(hr>=3 && hr<4)
		printf("\nImprove");
	else if(hr>=4 && hr<5)
		printf("\nNeeds Training");
	if(hr>=5)
		printf("\nPlease Leave");
	getch();
}

