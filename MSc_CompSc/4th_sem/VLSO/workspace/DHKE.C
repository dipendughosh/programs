//Diffie Hellman Key Exchange

#include<stdio.h>
#include<conio.h>
#include<math.h>

int x,y,g,p; 

void user_a();
void user_b();
int gen_no(int,int,int);

void main()
{	
    clrscr();
	
	//prime number(p)
    printf("\nEnter a prime number :- ");
    scanf("%d",&p);
    //generator(g)
    printf("\nEnter a generator :- ");
    scanf("%d",&g);
	
    printf("\nPrime number p = %d",p);
    printf("\nGenerator g = %d",g);
	
    user_a();
   
    getch();
}

int gen_no(int g,int p,int x)
{
    int r;
	int z = pow(g,x);
    
    r = z % p;
   
    return(r);
}

void user_a()
{
    int a,sa;
        
    //a
    printf("\nEnter user A's private key :- ");
    scanf("%d",&a);
    
    //public key for user A
	x = gen_no(g,p,a);
	printf("\nPublic key for User A: %d",x);
	
	//start actions of User B
	user_b();
	
	//private key for both the users
	sa = gen_no(y,p,a);
	printf("\nCommon Private Key as calculated by User A: %d",sa);

}

void user_b()
{
    int b,sb;
        
    //b
    printf("\nEnter user B's private key :- ");
    scanf("%d",&b);
    
    //public key for user A
	y = gen_no(g,p,b);
	printf("\nPublic key for User B: %d",y);
	
	//private key for both the users
	sb = gen_no(x,p,b);
	printf("\nCommon Private Key as calculated by User B: %d",sb);
}