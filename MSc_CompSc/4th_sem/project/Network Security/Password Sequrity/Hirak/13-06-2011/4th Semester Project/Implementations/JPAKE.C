/*Password Authenticated key Exchange by Juggling*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int g,s;
long int gx1=0,gx2=0,gx3=0,gx4=0;

void user_a();
void user_b(int);
int gen_random_no();

void main()
{
	char sk;
	
	clrscr();
	
	/*generator(g)*/
	printf("Enter a Generator:");
	scanf("%d",&g);
	
	fflush(stdin);
	
	/*Secret key (s) shared by both the users*/
	printf("\nEnter a secret key:");
	scanf("%c",&sk);
	
	/*Check for blank entry*/
	while (sk=='\n')
	{
		printf("\nPlease enter a key!!!");
		printf("\nEnter a secret key:");
		scanf("%c",&sk);
	}	
	
	s= atoi(&sk);
	
	user_a();
	
	getch();
	
}

int gen_random_no()
{
	int r;
	randomize();
	r=random (100);
	printf("Random number in the 0-99 range: %d\n", r);
	return(r);
}

void user_a(int c)
{
	int x1,x2,ra;
	long int ta;
	
	/*Private keys of user A*/
	pritnf("\nEnter the 1st private key for user A:");
	scanf("%d",x1);
	
	printf("\nEnter the 2nd private key for user A:");
	scanf("%d",x2);
	
	while(x2==0)
	{
		printf("\nPlease enter non-zero value!!!");
		printf("\nEnter the 2nd private key for user A:");
		scanf("%d",x2);
		
	}
	
	gx1=pow(g,x1);
	gx2=pow(g,x2);
	ra=gen_random_no();
	ta=pow(g,ra);
	user_b(ta,1);
	
}

void user_b(int ta,int flag)
{
	int x3,x4,rb,tb,c;
	
	if(flag==1)
	{
		c=gen_random_no();
		user_a(c);
	}
	
	/*Private keys of user B*/
	pritnf("\nEnter the 1st private key for user B:");
	scanf("%d",x3);
	
	printf("\nEnter the 2nd private key for user B:");
	scanf("%d",x4);
	
	while(x4==0)
	{
		printf("\nPlease enter non-zero value!!!");
		printf("\nEnter the 2nd private key for user B:");
		scanf("%d",x4);
		
	}
	
	gx3=pow(g,x3);
	gx4=pow(g,x4);	
	rb=gen_random_no();
}
