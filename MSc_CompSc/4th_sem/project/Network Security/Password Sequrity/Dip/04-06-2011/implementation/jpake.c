#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct JPakeParameters
{
    long int p;
    long int g;
};

struct JPakeUser
{
      const char *name;         //Must be unique
      long int base;                 //3 for Alice 7 for Bob
      long int secret;               //The shared secret
      long int key;                  //The calculated(shared) Secret
      long int xa;                   //Alice's x1 or Bob's x3
      long int xb;                   //Alice's x2 or Bob's x4
      long int xc;                   //Alice's x3 or Bob's x1
      long int xd;                   //Alice's x4 or Bob's x2
      long int stp1c;                //Alice's g^x3 or Bob's g^x1
      long int stp1d;                //Alice's g^x4 or Bob's g^x2
	  long int stp2;					//Alice's A or Bob's B
};

void JPakeParameters_Init(struct JPakeParameters *param)
{
      //prime number(p)
      printf("\nEnter a prime number :- ");
      scanf("%d",&param->p);
      //generator(g)
      printf("\nEnter a generator :- ");
      scanf("%d",&param->g);
}

void show(struct JPakeUser *user)
{
      printf("\nName\t:\t%s\nBase\t:\t%d\nSecret\t:\t%d\nKey\t:\t%d\nxa\t:\t%d\nxb\t:\t%d\nxc\t:\t%d\nxd\t:\t%d\nstp1c\t:\t%d\nstp1d\t:\t%d\nstp2\t:\t%d\n",
				user->name,user->base,user->secret,user->key,user->xa,user->xb,user->xc,user->xd,user->stp1c,user->stp1d,user->stp2);
}

long int genrand(long int n)
{
      long int x;
      srand(n*rand());
      x=rand();
      return x;
}

void genknp(struct JPakeUser *user,struct JPakeParameters *param)
{
      if(strcmp(user->name,"Alice"))
      {
        user->xa=genrand(3)%10;
        user->xb=genrand(5)%10;
		
        /*user->xc=genrand(7)%10;
        user->xd=genrand(11)%10;*/
      }
      else if(strcmp(user->name,"Bob"))
      {
        user->xa=genrand(13)%10;
        user->xb=genrand(17)%10;
        
		/*user->xc=genrand(19)%10;
        user->xd=genrand(23)%10;*/
      }
      /*user->stp1c=pow(param->g,user->xc);
      user->stp1d=pow(param->g,user->xd);*/
}

void sendstep1(JPakeUser *from,JPakeUser *to,JPakeParameters *param)
{
	  to->xc=from->xa;
	  to->xd=from->xb;
	  to->stp1c=pow(param->g,to->xc);
	  to->stp1c=to->stp1c%param->p;
	  to->stp1d=pow(param->g,to->xd);
	  to->stp1d=to->stp1d%param->p;
}

void sendstep2(JPakeUser *from,JPakeUser *to,JPakeParameters *param)
{
	  to->stp2=pow(param->g,from->xa)*from->stp1c*from->stp1d;
	  to->stp2=pow(to->stp2,from->xb*from->secret);
	  to->stp2=to->stp2%param->p;
}

int main()
{       
      struct JPakeParameters param;
	  struct JPakeUser alice,bob;
	  
      JPakeParameters_Init(&param);
      
      alice.name = "Alice";
      alice.base=3;
      alice.key=0;
      /*printf("\nEnter Alice's Base :- ");
      scanf("%d",&alice.base);*/
            
      bob.name = "Bob";
      bob.base=7;
      bob.key=0;
      /*printf("\nEnter Bob's Base :- ");
      scanf("%d",&bob.base);*/
      
      alice.secret=genrand(1);
      bob.secret=alice.secret;
      
      //generate knowledge proofs
      
      //Alice's x1 and x2
      genknp(&alice,&param);
      
      //Bob's x1 and x2
      genknp(&bob,&param);
      
	  sendstep1(&alice,&bob,&param);
	  sendstep1(&bob,&alice,&param);
	  
	  sendstep2(&alice,&bob,&param);
	  sendstep2(&bob,&alice,&param);
	  
      show(&alice);
      show(&bob);
	  
	  printf("\nTerminating Successfully");
	  getch();
	  return 0;
}
