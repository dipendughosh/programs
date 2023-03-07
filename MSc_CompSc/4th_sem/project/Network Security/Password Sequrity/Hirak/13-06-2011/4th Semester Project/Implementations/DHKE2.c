//Diffie Hellman Key Exchange

#include<stdio.h>
#include<conio.h>
#include<math.h>

int x,y;

int gen_no(int g,int p,int x)
{
    int z = pow(g,x);
    
    z = z % p;
   
    return(z);
}

int user_a(int g,int p)
{
    int ua;
        
    //a
    printf("\nEnter user A's private key :- ");
    scanf("%d",&ua);
    
    x = gen_no(g,p,ua);
    
    return(ua);
}

int user_b(int g,int p)
{
    int ub;
        
    //b
    printf("\nEnter user B's private key :- ");
    scanf("%d",&ub);
    
    y = gen_no(g,p,ub);
    
    return(ub);
}

int calc_sa(int aa,int p,int b)
{
    int z;
    
    z = gen_no(aa,p,b);
    
    return(z);
}

int calc_sb(int g,int p,int sa)
{
    int z;
    
    z = gen_no(g,p,sa);
    
    return(z);
}

void main()
{
    int p,g;
    int a,b;
    int sa,sb;
    
    //prime number(p)
    printf("\nEnter a prime number :- ");
    scanf("%d",&p);
    //generator(g)
    printf("\nEnter a generator :- ");
    scanf("%d",&g);
    
    //A
    a = user_a(g,p);
    //B
    b = user_b(g,p);
    
    //Calculate SA
    sa = calc_sa(x,p,b);
    //Calculate SB
    sb = calc_sb(y,p,a);
    
    printf("\np = %d",p);
    printf("\ng = %d",g);
    printf("\nA = %d",a);
    printf("\nB = %d",b);
    printf("\nSA = %d",sa);
    printf("\nSB = %d",sb);
      
    getch();
	
}