
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

unsigned int x=0,y=0;
int g,p;

int gen_no(int,int,unsigned int);
void attacker();
void user_a();
void user_b();

int main()
{
   int ch;
   //clrscr();

	//prime number(p)
   printf("\nEnter a prime number :- ");
   scanf("%d",&p);
   //generator(g)
   printf("\nEnter a generator :- ");
   scanf("%d",&g);

   printf("\nPrime number p = %d",p);
   printf("\nGenerator g = %d",g);

	do
	{
		printf("\n\nDEFFIE-HELLMAN KEY EXCHANGE:-");
		printf("\n1. Normal Exchange of key.");
		printf("\n2. Key Exchange infilterated by attacker.");
		printf("\n3. Exit.");
		printf("\nEnter your choice (1-3):");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				user_a();
				break;
			case 2:
				attacker();
				break;
			case 3:
				exit(0);
			default:
				printf("Invalid Choice!");
				break;
		}
	}while(1);
	return(0);
}

int gen_no(int g,int p,unsigned int x)
{
   unsigned int r;
   
   unsigned int z = pow((double)g,(double)x);

   if(g!=1)
		r = z % p;
	else
		r=1;
   return(r);
}

void attacker()
{
	unsigned int c,d,sa,sb;

	//For User A
   //randomize();
   c = random();
	printf("\n1st private key for attacker generated :  %d",c);

	//For User B
   d = random();
	printf("\n2nd private key for attacker generated : %d",d);

	//Generating Public Key to be transmitted to User A
	y=gen_no(g,p,c);
	user_a();

	//Calculating common private key between User A and Attacker
	sa= gen_no(x,p,c);
	printf("\nCommon Private Key as calculated for User A by Attacker: %d",sa);

	//Generating Public Key to be transmitted to User B
	x=gen_no(g,p,d);
	user_b();

	//Calculating common private key between User B and Attacker
	sb=gen_no(y,p,d);
	printf("\nCommon Private Key as calculated for User B by Attacker: %d",sb);
}

void user_a()
{
   unsigned int a,sa;

   //randomize();
   //a
   a = random();
   printf("\nA's private key generated :- %d",a);

   //public key for user A
	x = gen_no(g,p,a);
	printf("\nPublic key for User A: %d",x);

	//start actions of User B
	if(y==0)
		user_b();

	//private key for both the users
	sa = gen_no(y,p,a);
	printf("\nCommon Private Key as calculated by User A: %d",sa);

}

void user_b()
{
   unsigned int b,sb;

   //randomize();
   //b
   b = random();
   printf("\nB's private key generated :- %d",b);

   //public key for user A
	y = gen_no(g,p,b);
	printf("\nPublic key for User B: %d",y);

	//private key for both the users
	sb = gen_no(x,p,b);
	printf("\nCommon Private Key as calculated by User B: %d",sb);
}