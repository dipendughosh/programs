#include<stdio.h>

unsigned long long x=0,y=0,g,p; 

//Power function
//result=x^y
unsigned long long powdef(unsigned long long x,unsigned long long y)
{
    unsigned long long i,res=1;
    
    for(i=1;i<=y;i++)
    {
        res=res*x;
    }
    
    return res;
}

//For generating the private keys
unsigned long long gen_no(unsigned long long g,unsigned long long p,unsigned long long x)
{
    unsigned long long r;
    unsigned long long z;
	
    z = powdef(g,x);
	
    if(g!=1)
	r = z % p;
    else
	r=1;
		
    return(r);
}

//To take user B's private key and generate the public key
void user_b()
{
    unsigned long long b,sb;
        
    do
    {
        //Private key of user B(9,15)
        printf("\nEnter User B's private key :- ");
        scanf("%llu",&b);
                
        if(b<p)
                break;
        else
                printf("\nReenter");
    }while(1);
    
    //Public key for user B
    y = gen_no(g,p,b);
    printf("\nPublic key for User B: %llu",y);
        
    //Private key for both the users
    sb = gen_no(x,p,b);
    printf("\nCommon Private Key as calculated by User B: %llu",sb);
}

//To take user A's private key and generate the public key
void user_a()
{
    unsigned long long a,sa;
        
    do
    {
        //Private key of user A(6,6)
        printf("\nEnter User A's private key :- ");
        scanf("%llu",&a);
        
        if(a<p)
                break;
        else
                printf("\nReenter");
    }while(1);
        
    //Public key for user A
    x = gen_no(g,p,a);
    printf("\nPublic key for User A: %llu",x);
        
    //Start actions of User B
    if(y==0)
        user_b();
        
    //Private key for both the users
    sa = gen_no(y,p,a);
    printf("\nCommon Private Key as calculated by User A: %llu",sa);

}

//To take user A's private key and generate the public key
void attacker()
{
    unsigned long long c,d,sa,sb;
	
    //For User A
    printf("\nEnter the 1st private key for attacker:");
    scanf("%llu",&c);
	
    //For User B
    printf("\nEnter the 2nd private key for attacker:");
    scanf("%llu",&d);
	
    //Generating Public Key to be transmitted to User A
    y=gen_no(g,p,c);
    user_a();
	
    //Calculating common private key between User A and Attacker
    sa= gen_no(x,p,c);
    printf("\nCommon Private Key as calculated for User A by Attacker: %llu",sa);
	
    //Generating Public Key to be transmitted to User B
    x=gen_no(g,p,d);
    user_b();
	
    //Calculating common private key between User B and Attacker
    sb=gen_no(y,p,d);
    printf("\nCommon Private Key as calculated for User B by Attacker: %llu",sb);
}	
	
int main()
{	
    int ch;

    //prime number(p)
    p=11;//23
    //generator(g)
    g=7;//5
	
    printf("\nPrime number p = %llu",p);
    printf("\nGenerator g = %llu",g);
	
    //Performing the key exchange depending on user's choice of Normal Exchange of key or Key Exchange infilterated by attacker
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
                        break;
		default:
			printf("Invalid Choice!");
			break;
	}
    }while(1);
	
    return 0;
}