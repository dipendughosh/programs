#include<stdio.h>

long int x=0,y=0,g,p; 

//Power function
//result=x^y
long int powdef(long int x,long int y)
{
    long int i,res=1;
    
	for(i=1;i<=y;i++)
    {
      res=res*x;
    }
    
	return res;
}

//For generating the private keys
long int gen_no(long int g,long int p,long int x)
{
    long int r;
	long int z;
	
	z = pow(g,x);
	
    if(g!=1)
		r = z % p;
	else
		r=1;
		
    return(r);
}

//To take user A's private key and generate the public key
void attacker()
{
	long int c,d,sa,sb;
	
	//For User A
	printf("\nEnter the 1st private key for attacker:");
	scanf("%ld",&c);
	
	//For User B
	printf("\nEnter the 2nd private key for attacker:");
	scanf("%ld",&d);
	
	//Generating Public Key to be transmitted to User A
	y=gen_no(g,p,c);
	user_a();
	
	//Calculating common private key between User A and Attacker
	sa= gen_no(x,p,c);
	printf("\nCommon Private Key as calculated for User A by Attacker: %ld",sa);
	
	//Generating Public Key to be transmitted to User B
	x=gen_no(g,p,d);
	user_b();
	
	//Calculating common private key between User B and Attacker
	sb=gen_no(y,p,d);
	printf("\nCommon Private Key as calculated for User B by Attacker: %ld",sb);
}	
	
//To take user A's private key and generate the public key
void user_a()
{
    long int a,sa;
        
    do
	{
		//Private key of user A(6,6)
		printf("\nEnter User A's private key :- ");
		scanf("%ld",&a);
		
		if(a<p)
			break;
		else
			printf("\nReenter");
    }while(1);
	
    //Public key for user A
	x = gen_no(g,p,a);
	printf("\nPublic key for User A: %ld",x);
	
	//Start actions of User B
	if(y==0)
		user_b();
	
	//Private key for both the users
	sa = gen_no(y,p,a);
	printf("\nCommon Private Key as calculated by User A: %ld",sa);

}

//To take user B's private key and generate the public key
void user_b()
{
    long int b,sb;
        
    do
	{
		//Private key of user B(9,15)
		printf("\nEnter User B's private key :- ");
		scanf("%ld",&b);
		
		if(b<p)
			break;
		else
			printf("\nReenter");
    }while(1);
    
    //Public key for user B
	y = gen_no(g,p,b);
	printf("\nPublic key for User B: %ld",y);
	
	//Private key for both the users
	sb = gen_no(x,p,b);
	printf("\nCommon Private Key as calculated by User B: %ld",sb);
}

int main()
{	
    int ch;

	//prime number(p)
    p=11;//23
    //generator(g)
    g=7;//5
	
    printf("\nPrime number p = %ld",p);
    printf("\nGenerator g = %ld",g);
	
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
			default:
				printf("Invalid Choice!");
				break;
		}
	}while(1);
	
	return 0;
}