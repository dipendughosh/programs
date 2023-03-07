
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<dos.h>

unsigned int x=0,y=0,g,p;
char string[80];

struct time t1,t2;

int min,sec,i,j,k;
long int ssec;

int check(char []);
int changebase(char []);
unsigned int gen_no(unsigned int,unsigned int,unsigned int);
void attacker();
void user_a();
void user_b();
void time_cnt();

void main()
{
   int ch,f=0;

   min = 0;
   sec = 0;
   ssec = 0;

   clrscr();

	//prime number(p)
   do
   {
    	printf("\nEnter a prime number in binary :- ");
      fflush(stdin);
		gets(string);

      gettime(&t1);
      for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
      f = check(string);
      gettime(&t2);
      time_cnt();

      if(f == 1)
      	continue;
      else
         break;
   }while(1);

   gettime(&t1);
   for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   p = changebase(string);
   gettime(&t2);
   time_cnt();

   printf("\nTime taken is ::== %d min :%d sec :%ld hsec",min,sec,ssec);

 //generator(g)
   do
   {
    	printf("\nEnter a generator in binary :- ");
      fflush(stdin);
		gets(string);

    	gettime(&t1);
      for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
      f = check(string);
      gettime(&t2);
      time_cnt();

	  	if(f == 1)
      	continue;
      else
         break;
   }while(1);

   printf("\nTime taken is ::== %d min :%d sec :%ld hsec",min,sec,ssec);

  	gettime(&t1);
   for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   g = changebase(string);
   gettime(&t2);
   time_cnt();

   printf("\nPrime number p = %u",p);
   printf("\nGenerator g = %u",g);

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
            printf("\nTime taken is ::== %d min :%d sec :%ld hsec",min,sec,ssec);
            min = 0;
   			sec = 0;
   			ssec = 0;
   			break;
			case 2:
				attacker();
            printf("\nTime taken is ::== %d min :%d sec :%ld hsec",min,sec,ssec);
            min = 0;
   			sec = 0;
   			ssec = 0;
   			break;
			case 3:
				exit(0);
			default:
				printf("Invalid Choice!");
				break;
		}
	}while(1);
   //printf("\nTime taken is ::== %d min :%d sec :%ld hsec",min,sec,ssec);
   //getch();
}

unsigned int gen_no(unsigned int g,unsigned int p,unsigned int x)
{
   unsigned int r;
	unsigned  int z = pow(g,x);

   if(g!=1)
		r = z % p;
	else
		r=1;
   return(r);
}

void attacker()
{
	unsigned int c,d,sa,sb,f=0;

	//For User A
   do
   {
    	printf("\nEnter the 1st private key for attacker in binary : ");
		fflush(stdin);
		gets(string);

		gettime(&t1);
      for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   	f = check(string);
      gettime(&t2);
   	time_cnt();

		if(f == 1)
      	continue;
      else
         break;
   }while(1);

	gettime(&t1);
   for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   c = changebase(string);
   gettime(&t2);
   time_cnt();

   //For User B
   do
   {
    	printf("\nEnter the 2nd private key for attacker in binary : ");
		fflush(stdin);
		gets(string);

		gettime(&t1);
      for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   	f = check(string);
		gettime(&t2);
   	time_cnt();

		if(f == 1)
      	continue;
      else
         break;
   }while(1);

   gettime(&t1);
   for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   d = changebase(string);
	gettime(&t2);
   time_cnt();


	//Generating Public Key to be transmitted to User A
	y=gen_no(g,p,c);
	user_a();

	//Calculating common private key between User A and Attacker
	sa= gen_no(x,p,c);
	printf("\nCommon Private Key as calculated for User A by Attacker: %u",sa);

	//Generating Public Key to be transmitted to User B
	x=gen_no(g,p,d);
	user_b();

	//Calculating common private key between User B and Attacker
	sb=gen_no(y,p,d);
	printf("\nCommon Private Key as calculated for User B by Attacker: %u",sb);
}

void user_a()
{
   unsigned int a,sa,f=0;

   //a
   do
   {
    	printf("\nEnter user A's private key in binary :- ");
   	fflush(stdin);
		gets(string);

   	gettime(&t1);
      for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
		f = check(string);
		gettime(&t2);
   	time_cnt();

		if(f == 1)
      	continue;
      else
         break;
   }while(1);

   gettime(&t1);
   for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   a = changebase(string);
	gettime(&t2);
   time_cnt();


   //public key for user A
	x = gen_no(g,p,a);
	printf("\nPublic key for User A: %u",x);

	//start actions of User B
	if(y==0)
		user_b();

	//private key for both the users
	sa = gen_no(y,p,a);
	printf("\nCommon Private Key as calculated by User A: %u",sa);

}

void user_b()
{
   unsigned int b,sb,f=0;

   //b
   do
   {
    	printf("\nEnter user B's private key in binary :- ");
   	fflush(stdin);
		gets(string);

   	gettime(&t1);
      for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
		f = check(string);
		gettime(&t2);
   	time_cnt();

	if(f == 1)
      	continue;
      else
         break;
   }while(1);

   gettime(&t1);
   for(i=0;i<=100;i++)
      	for(j=0;j<=100;j++)
      		for(k=0;k<=100;k++);
   b = changebase(string);
	gettime(&t2);
   time_cnt();

   //public key for user A
	y = gen_no(g,p,b);
	printf("\nPublic key for User B: %u",y);

	//private key for both the users
	sb = gen_no(x,p,b);
	printf("\nCommon Private Key as calculated by User B: %u",sb);
}


int check(char stringhold[80])
{
	int len,i,a,f=0;
	len=strlen(stringhold);
	for(i=0;i<len;i++)
	{
   	a=stringhold[i];
		//Checking digits
		if((a-48)>=0 && (a-48)<=9)
		{	if((a-48)>=2)
			{	printf("\nINCORRECT\n\aRe-enter\n");
					f=1;
				break;
			}
		}
		//Checking alphabetes in upper cases
		else if((a-55)>=10 && (a-55)<16)
		{	if((a-55)>=2)
			{       printf("\nINCORRECT\n\aRe-enter\n");
					f=1;
				break;
			}
		}
		//Checking alphabetes in lower cases
		else if((a-87)>=10 && (a-87)<16)
		{	if((a-87)>=2)
			{	printf("\nINCORRECT\n\aRe-enter\n");
				f=1;
				break;
			}
		}
	}
   return(f);
}

//Function to change entered number from old base to new base
int changebase(char stringhold[80])
{
   //Declaring variables
	int x=0,s=0,c,i,a,b,len;
   len = strlen(stringhold);
	//Loop to convert number from given base to decimal
	for(i=(len-1);i>=0;i--)
	{	a=stringhold[i];
		if(a>=48 && a<=58)
		{	b=a-48;
			c=(pow(2,x))*b;
			s=s+c;
		}
		if(a>=65 && a<=70)
		{       b=a-55;
			c=(pow(2,x))*b;
			s=s+c;
		}
		if(a>=97 && a<=102)
		{       b=a-87;
			c=(pow(2,x))*b;
			s=s+c;
		}
		x++;
	}
   return(s);
}

void time_cnt()
{
	//printf("\nTime Count");
	if(t1.ti_hund>t2.ti_hund)
	{
		ssec=ssec + 100+t1.ti_hund-t2.ti_hund;
		(t1.ti_sec)=(t1.ti_sec)-1;
	}
	else
		ssec=ssec + t2.ti_hund-t1.ti_hund;
	if(t1.ti_sec>t2.ti_sec)
	{
		sec=sec + 60+t1.ti_sec-t2.ti_sec;
		(t1.ti_min)=(t1.ti_min)-1;
	}
	else
		sec=sec + t2.ti_sec-t1.ti_sec;
	min=min + t2.ti_min-t1.ti_min;
}
