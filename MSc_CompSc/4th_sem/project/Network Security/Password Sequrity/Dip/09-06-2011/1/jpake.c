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
      int stp1c;                //Alice's g^x3 or Bob's g^x1
      int stp1d;                //Alice's g^x4 or Bob's g^x2
      int stp2;			//Alice's A or Bob's B
      int r1,c1,s1;
      int r2,c2,s2;
      int r3,c3,s3;
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

void changebase(int no,int base)
{
      int i,b,x=0;
      char stringhold[20];
      
      if(no==0)
      {
          stringhold[x]=(char)(no+48);
          x++;
      }
      else
      {
          while(no!=0)
          {
              b=no%base;
              no=no/base;
              if(b>=0 && b<=9)
              {
                  stringhold[x]=(char)(b+48);
                  x++;
              }
              if(b>9 && b<16)
              {
                  stringhold[x]=(char)(b+55);
                  x++;
              }
          }
      }
      stringhold[x]='\0';
      
      for(i=x-1;i>=0;i--)
          printf("%c",stringhold[i]);
}

void show(struct JPakeUser *user)
{
      /*printf("\nName\t:\t%s",user->name);
      printf("\nBase\t:\t%d",user->base);
      printf("\nSecret\t:\t");
      changebase(user->secret,user->base);
      printf("\nKey\t:\t");
      changebase(user->key,user->base);
      printf("\nxa\t:\t");
      changebase(user->xa,user->base);
      printf("\nxb\t:\t");
      changebase(user->xb,user->base);
      printf("\nstp1c\t:\t");
      changebase(user->stp1c,user->base);
      printf("\nstp1d\t:\t");
      changebase(user->stp1d,user->base);
      printf("\nstp2\t:\t");
      changebase(user->stp2,user->base);
      printf("\n");*/
      printf("\nName\t:\t%s\nBase\t:\t%d\nSecret\t:\t%d\nKey\t:\t%d\nxa\t:\t%d\nxb\t:\t%d\nstp1c\t:\t%d\nstp1d\t:\t%d\nstp2\t:\t%d\n",
                                user->name,user->base,user->secret,user->key,user->xa,user->xb,user->stp1c,user->stp1d,user->stp2);

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
          user->xa=genrand(3)%10;
          user->xb=genrand(5)%10;
      }
      else if(strcmp(user->name,"Bob"))
      {
          user->xa=genrand(13)%10;
          user->xb=genrand(17)%10;
      }
}

//verifier(Alice or Bob,send step,verification step,generator,r,c,s=r+c^x,y=g^x)
int verifier(int user,int ss,int sss,int g,int r,int c,int s,int y)
{
      int t1,t2,t;
      
      if(ss==1)
      {
          if(sss==1)
          {
              if(user==1)
                  c=genrand(29);
              else if(user==2)
                  c=genrand(31);
          }
          else if(sss==2)
          {
              if(user==1)
                  c=genrand(37);
              else if(user==2)
                  c=genrand(41);
          }
          
          c=c%10;
          
          return c;
      }
      else if(ss==2)
      {
          t1=powdef(g,s);
          t=powdef(g,r);
          t2=powdef(y,c);
          t2=t2*t;
          
          if(t1==t2)
              return 1;
      }
      else if(ss==3)
      {
          if(user==1)
              c=genrand(51);
          else if(user==2)
              c=genrand(53);
          
          c=c%10;
          
          return c;
      }
      else if(ss==4)
      {
          t1=powdef(g,s);
          t=powdef(g,r);
          t2=powdef(y,c);
          t2=t2*t;
          
          if(t1==t2)
              return 1;
      }
      return 0;
}

//prover(Alice or Bob,parameters,send step,substep)
void prover(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param,int ss,int sss)
{
      int u,t,r,c,s,y,f;
      
      if(strcmp(from->name,"Alice"))
          u=1;
      else if(strcmp(from->name,"Bob"))
          u=2;
      
      if(ss==1)
      {   
          if(sss==1)
          {
              if(u==1)
                  r=genrand(7);
              else if(u==2)
                  r=genrand(11);
              
              to->r1=r%10;
              
              to->c1=verifier(u,1,1,0,0,0,0,0);
      
              to->s1=to->r1+to->c1*from->xa;
          }
          else if(sss==2)
          {
              if(u==1)
                  r=genrand(43);
              else if(u==2)
                  r=genrand(47);
              
              to->r2=r%10;
              
              to->c2=verifier(u,1,2,0,0,0,0,0);
      
              to->s2=to->r2+to->c2*from->xb;
          }
      }
      else if(ss=3)
      {
          if(u==1)
              r=genrand(19);
          else if(u==2)
              r=genrand(23);
          
          to->r3=r%10;
              
          to->c3=verifier(u,3,0,0,0,0,0,0);
      
          to->s3=to->r3+to->c3*from->xb*from->secret;
      }
}

//zkp(Alice or Bob,parameter,send step) 
int zkp(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param,int ss)
{
      int f1=1,f2=1,u;
            
      if(ss==1)
      {
          prover(from,to,param,1,1);            
          prover(from,to,param,1,2);
          
          return 0;
      }
      else if(ss==2)
      {         
          if(strcmp(from->name,"Alice"))
              u=1;
          else if(strcmp(from->name,"Bob"))
              u=2;
          
          f1=verifier(u,2,0,param->g,to->r1,to->c1,to->s1,to->stp1c);
          f2=verifier(u,2,0,param->g,to->r2,to->c2,to->s2,to->stp1d);
      
          if(f1==1 && f2==1)
              return 1;
      }
      else if(ss==3)
      {
          prover(from,to,param,3,0);
          
          return 0;
      }
      else if(ss==4)
      {
          if(strcmp(from->name,"Alice"))
              u=1;
          else if(strcmp(from->name,"Bob"))
              u=2;
          
          f1=verifier(u,4,0,param->g,to->r3,to->c3,to->s3,(from->xb*from->secret));
      
          if(f1==1)
              return 1;
      }
      return 0;
}

void sendstep1(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      int f1=1,f2=1;
      
      f1=zkp(from,to,param,1);
      
      to->stp1c=powdef(param->g,from->xa);
      to->stp1d=powdef(param->g,from->xb);
      
      f2=zkp(from,to,param,2);
      
      if(f2==1)
          printf("\nStep 1 successful\n");
      else
      {
          printf("\nStep 1 Fail\nExitting\n");
          exit(0);
      }
}

void sendstep2(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      int user,lg,x,f=1;
      
      f=zkp(from,to,param,3);
      
      to->stp2=(powdef(param->g,from->xa)*from->stp1c*from->stp1d);
      to->stp2=powdef(to->stp2,from->xb*from->secret)%10;
           
      f=zkp(from,to,param,4);
      
      if(f==1)
          printf("\nStep 2 successful\n");
      else
      {
          printf("\nStep 2 Fail\nExitting\n");
          exit(0);
      }
}

void compute_key(struct JPakeUser *user,struct JPakeParameters *param)
{
      float temp;
      temp=powdef(user->stp1d,(user->xb*user->secret));
      temp=user->stp2/temp;
      user->key=powdef(temp,user->xb);
}

int main()
{       
      struct JPakeParameters param;
      struct JPakeUser alice,bob;
      char a;
      JPakeParameters_Init(&param);
      
      alice.name = "Alice";
      alice.base=5;
      alice.key=0;
            
      bob.name = "Bob";
      bob.base=7;
      bob.key=0;
      
      alice.secret=genrand(1)%10;
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
