#include<stdio.h>

int powdef(int x,int y)
{
    int i,res=1;
    for(i=1;i<=y;i++)
    {
      res=res*x;
    }
    return res;
}

struct JPakeParameters
{
      int p;
      int g;
};

struct JPakeUser
{
      const char *name;         //Must be unique
      int base;                 //3 for Alice 7 for Bob
      int secret;               //The shared secret
      int key;                  //The calculated(shared) Secret
      int xa;                   //Alice's x1 or Bob's x3
      int xb;                   //Alice's x2 or Bob's x4
      int xc;                   //Alice's x3 or Bob's x1
      int xd;                   //Alice's x4 or Bob's x2
      int stp1c;                //Alice's g^x3 or Bob's g^x1
      int stp1d;                //Alice's g^x4 or Bob's g^x2
      int stp2;			//Alice's A or Bob's B
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

int genrand(int n)
{
      int x;
      srand(n*rand());
      x=rand();
      return x;
}

void genknp(struct JPakeUser *user,struct JPakeParameters *param)
{
      if(strcmp(user->name,"Alice"))
      {
          user->xa=genrand(3)%100;
          user->xb=genrand(5)%100;
		
          /*user->xc=genrand(7)%10;
          user->xd=genrand(11)%10;*/
      }
      else if(strcmp(user->name,"Bob"))
      {
          user->xa=genrand(13)%100;
          user->xb=genrand(17)%100;
        
          /*user->xc=genrand(19)%10;
          user->xd=genrand(23)%10;*/
      }
      /*user->stp1c=pow(param->g,user->xc);
      user->stp1d=pow(param->g,user->xd);*/
}

//verifier(Alice or Bob,send step,verification step,generator,s=r+c^x,t=g^r,y=g^x,c)
int verifier(int user,int ss,int step,int g,int s,int t,int y,int c)
{
      int t1,t2;
      
      if(step==1)
      {
      
          if(ss==1)
          {
              if(user==1)
                  c=genrand(29);
              else if(user==2)
                  c=genrand(31);
          }
          else if(ss==2)
          {
              if(user==1)
                  c=genrand(37);
              else if(user==2)
                  c=genrand(41);
          }
          
          return c;
      }
      else if(step==2)
      {
          t1=powdef(g,s);
          t2=powdef(y,c);
          t2=t2*t;
          
          if(t1==t2)
              return 1;
      }
      
      return 0;
}

//prover(Alice or Bob,send step,generator,xa or xb)
int prover(int user,int ss,int g,int x)
{
      int t,r,c,s,y,f;
      
      if(ss==1)
      {         
          if(user==1)
              r=genrand(7);
          else if(user==2)
              r=genrand(11);
      }
      else if(ss=2)
      {
          if(user==1)
              r=genrand(19);
          else if(user==2)
              r=genrand(23);
      }
     
      t=powdef(g,r);
      
      c=verifier(user,ss,1,0,0,0,0,0);
      
      s=r+c*x;
      y=powdef(g,x);
      
      f=verifier(user,ss,2,g,s,t,y,c);
      
      return f;
}

//zkp(Alice or Bob,send step,generator,xa or xb for send step 1/xb^secret for send step 2) 
int zkp(int user,int ss,int g,int x)
{
      int f;
            
      f=prover(user,ss,g,x);            
      
      return f;
}

void sendstep1(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      int user,lg,x,f1=1,f2=1;
      
      if(strcmp(from->name,"Alice"))
          user=1;
      else if(strcmp(from->name,"Bob"))
          user=2;
      
      lg=param->g;
      
      x=from->xa;
      //f1=zkp(user,1,lg,x);
      
      x=from->xb;
      //f2=zkp(user,1,lg,x);
      
      if(f1==1 && f2==1)
      {
          to->xc=from->xa;
          to->xd=from->xb;
          to->stp1c=powdef(param->g,to->xc);
          //to->stp1c=to->stp1c%param->p;
          to->stp1d=powdef(param->g,to->xd);
          //to->stp1d=to->stp1d%param->p;
          
          printf("\nStep 1 successful\n");
      }
      else
      {
          printf("\nStep 1 Fail\nExitting\n");
          exit(0);
      }
          
}

void sendstep2(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      int user,lg,x,f=1;
      
      if(strcmp(from->name,"Alice"))
          user=1;
      else if(strcmp(from->name,"Bob"))
          user=2;
      
      lg=param->g;
      
      x=from->xb*from->secret;
      
      //f=zkp(user,2,lg,x);
      
      if(f==1)
      {
          to->stp2=powdef(param->g,from->xa)*from->stp1c*from->stp1d;
          to->stp2=powdef(to->stp2,from->xb*from->secret);
          //to->stp2=to->stp2%param->p;
          printf("\nStep 2 successful\n");
      }
      else
      {
          printf("\nStep 2 Fail\nExitting\n");
          exit(0);
      }
}

void compute_key(struct JPakeUser *user,struct JPakeParameters *param)
{
      user->key=powdef(param->g,(user->xa+user->xc));
      user->key=powdef(user->key,(user->xb*user->xd*user->secret));
}

int main()
{       
      struct JPakeParameters param;
      struct JPakeUser alice,bob;
      char a;
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
      
      //Bob's x3 and x4
      genknp(&bob,&param);
      
      //step 1 send
      sendstep1(&alice,&bob,&param);
      sendstep1(&bob,&alice,&param);
	
      //step 2 send
      sendstep2(&alice,&bob,&param);
      sendstep2(&bob,&alice,&param);

      //compute keys
      compute_key(&alice,&param);
      compute_key(&bob,&param);
      
      show(&alice);
      show(&bob);
	  
      printf("\nTerminating Successfully\n");
      
      return 0;
}
